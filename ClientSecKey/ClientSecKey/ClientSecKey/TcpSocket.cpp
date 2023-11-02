#include "TcpSocket.h"

TcpSocket::TcpSocket(int connect)
{
	m_socket = connect;
}

int TcpSocket::connectToHost(string ip, unsigned short port, int timeout)
{
	int ret = 0;
	if (port <= 0 || port > 65535 || timeout < 0)
	{
		ret = ParamError;
		return ret;
	}
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket < 0)
	{
		ret = errno;
		cout << "socket error : " << ret << endl;
		return ret;
	}
	sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr(ip.data());

	ret = connectTimeout((sockaddr_in*)(&servaddr), (unsigned int)timeout);
	if (ret < 0)
	{
		// 超时
		if (ret == -1 && errno == ETIMEDOUT)
		{
			ret = TimeoutError;
			return ret;
		}// 失败
		else
		{
			printf("connectTimeout 调用异常, 错误号: %d\n", errno);
			return errno;
		}
	}
	// 成功
	return ret;
}
int TcpSocket::sendMsg(string sendData, int timeout)
{
	int ret = writeTimeout(timeout);
	if (ret == 0)
	{
		int writed = 0;
		int dataLen = sendData.size() + 4;
		// 添加的4字节作为数据头, 存储数据块长度
		unsigned char* netdata = (unsigned char*)malloc(dataLen);
		if (netdata == NULL)
		{
			ret = MallocError;
			cout << "socket client send mlloc error " << ret << endl;
			return ret;
		}

		// 转换为网络字节序
		int netlen = htonl(sendData.size());
		memcpy(netdata, &netlen, 4);	// 把长度拷贝到 netdata
		memcpy(netdata + 4, sendData.data(), sendData.size());

		// 没问题返回发送的实际字节数, 应该 == 第二个参数: dataLen
		// 失败返回: -1
		writed = writen(netdata, dataLen);
		if (writed < dataLen)	// 发送失败
		{
			if (netdata != NULL)
			{
				free(netdata);
				netdata = NULL;
			}
			return writed;
		}
		// 释放内存
		if (netdata != NULL)
		{
			free(netdata);
			netdata = NULL;
		}
	}
	else
	{
		//失败返回-1，超时返回-1并且errno = ETIMEDOUT
		if (ret == -1 && errno == ETIMEDOUT)
		{
			ret = TimeoutError;
			cout << "socket client send time error : " << ret << endl;
		}
	}
	return ret;
}
string TcpSocket::recvMsg(int timeout)
{
	int ret = readTimeout(timeout);
	if (ret != 0)
	{
		// 超时
		if (ret == -1 || errno == ETIMEDOUT)
		{
			cout << "readTimeout error : TimeoutError " << endl;
			return string();
		}
		else //失败
		{
			cout << "readTimeout error :" << ret << endl;
			return string();
		}
	}

	//读包头 4个字节
	int netdatalen = 0;
	ret = readn(&netdatalen, 4);
	if (ret == -1)
	{
		cout << "readn error : " << ret << endl;
		return string();
	}
	else if (ret < 4)
	{
		cout << "readn error peer closed : " << ret << endl;
		return string();
	}
	int n = ntohl(netdatalen);

	// 根据包头中记录的数据大小申请内存, 接收数据
	char* tmpBuf = (char*)malloc(n + 1);		// 多分配一个，方便后面结尾用
	if (tmpBuf == NULL)
	{
		ret = MallocError;
		cout << "malloc error " << endl;
		return NULL;
	}


	// 根据长度读数据
	ret = readn(tmpBuf, n);
	if (ret == -1)
	{
		cout << "readn error : " << ret << endl;
		return string();
	}
	else if (ret < n)
	{
		cout << "readn error peer closed : " << ret << endl;
		return string();
	}

	tmpBuf[n] = '\0'; //多分配一个字节内容，兼容可见字符串 字符串的真实长度仍然为n
	string data = string(tmpBuf);
	// 释放内存
	free(tmpBuf);

	return data;

	return data;
}
void TcpSocket::disConnect()
{
	if (m_socket >= 0)
	{
		close(m_socket);
	}
}

/////////////////////////////////////////////////
//////             子函数                   /////
/////////////////////////////////////////////////
/*
* setNonBlock - 设置I/O为非阻塞模式
* @fd: 文件描符符
*/
int TcpSocket::setNoBlock(int fd)
{
	int flags = fcntl(fd, F_GETFL);
	if (flags == -1)
	{
		return flags;
	}
	flags |= O_NONBLOCK;
	int ret = fcntl(fd, F_SETFL, flags);
	return ret;

}
/*
* setBlock - 设置I/O为阻塞模式
* @fd: 文件描符符
*/
int TcpSocket::setBlock(int fd)
{
	int flags = fcntl(fd, F_GETFL);
	if (flags == -1)
	{
		return flags;
	}
	flags &= ~O_NONBLOCK;
	int ret = fcntl(fd, F_SETFL, flags);
	return ret;
}

/*
* readTimeout - 读超时检测函数，不含读操作
* @wait_seconds: 等待超时秒数，如果为0表示不检测超时
* 成功（未超时）返回0，失败返回-1，超时返回-1并且errno = ETIMEDOUT
*/
int TcpSocket::readTimeout(unsigned int wait_seconds)
{
	int ret = 0;
	if (wait_seconds > 0)
	{
		fd_set read_fdset;
		timeval timeout;

		FD_ZERO(&read_fdset);
		FD_SET(m_socket, &read_fdset);

		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;

		//select返回值三态
		//1 若timeout时间到（超时），没有检测到读事件 ret返回=0
		//2 若ret返回<0 &&  errno == EINTR 说明select的过程中被别的信号中断（可中断睡眠原理）
		//  2-1 若返回-1，select出错
		//3 若ret返回值>0 表示有read事件发生，返回事件发生的个数

		do
		{
			ret = select(m_socket + 1, &read_fdset, NULL, NULL, &timeout);

		} while (ret < 0 && errno == EINTR);

		if (ret == 0)		// 超时
		{
			ret = -1;
			errno = ETIMEDOUT;
		}
		else if (ret == 1)		// 没问题
		{
			ret = 0;
		}

	}

	return ret;

}

/*
* writeTimeout - 写超时检测函数，不含写操作
* @wait_seconds: 等待超时秒数，如果为0表示不检测超时
* 成功（未超时）返回0，失败返回-1，超时返回-1并且errno = ETIMEDOUT
*/
int TcpSocket::writeTimeout(unsigned int wait_seconds)
{
	int ret = 0;
	if (wait_seconds > 0)
	{
		fd_set write_fdset;
		timeval timeout;

		FD_ZERO(&write_fdset);
		FD_SET(m_socket, &write_fdset);
		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do
		{
			ret = select(m_socket + 1, NULL, &write_fdset, NULL, &timeout);
		} while (ret < 0 && errno == EINTR);

		// 超时
		if (ret == 0)
		{
			ret = -1;
			errno = ETIMEDOUT;
		}
		else if (ret == 1)
		{
			ret = 0;	// 没超时
		}
	}

	return ret;
}

/*
* connectTimeout - connect
* @addr: 要连接的对方地址
* @wait_seconds: 等待超时秒数，如果为0表示正常模式
* 成功（未超时）返回0，失败返回-1，超时返回-1并且errno = ETIMEDOUT
*/
int TcpSocket::connectTimeout(struct sockaddr_in* addr, unsigned int wait_seconds)
{
	int ret;
	socklen_t addrlen = sizeof(sockaddr_in);

	if (wait_seconds > 0)
	{
		setNoBlock(m_socket);	// 设置非阻塞IO
	}

	ret = connect(m_socket, (struct sockaddr*)addr, addrlen);

	if (ret < 0 && errno == EINPROGRESS)
	{
		fd_set connect_fdset;
		timeval timeout;
		FD_ZERO(&connect_fdset);
		FD_SET(m_socket, &connect_fdset);
		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do
		{
			// 一但连接建立，则套接字就可写 所以connect_fdset放在了写集合中
			ret = select(m_socket + 1, NULL, &connect_fdset, NULL, &timeout);
		} while (ret < 0 && errno == EINTR);

		if (ret == 0)
		{
			// 超时
			ret = -1;
			errno = ETIMEDOUT;
		}
		else if (ret < 0)
		{
			// 异常, select调用失败, 返回值为 -1
			return -1;
		}
		else if (ret == 1)
		{

			/* ret返回为1（表示套接字可写），可能有两种情况，一种是连接建立成功，一种是套接字产生错误，*/
			/* 此时错误信息不会保存至errno变量中，因此，需要调用getsockopt来获取。 */
			int err;
			socklen_t sockLen = sizeof(err);
			int sockoptret = getsockopt(m_socket, SOL_SOCKET, SO_ERROR, &err, &sockLen);
			if (sockoptret == -1)
			{
				// getsockopt 出错了
				return -1;
			}
			if (err == 0)
			{
				// 成功建立连接
				ret = 0;
			}
			else
			{
				// 连接失败
				errno = err;
				ret = -1;
			}
		}
	}
	if (wait_seconds > 0)
	{
		setBlock(m_socket);	// 套接字设置回阻塞模式
	}
	return ret;

}
/*
* readn - 读取固定字节数
* @fd: 文件描述符
* @buf: 接收缓冲区
* @count: 要读取的字节数
* 成功返回已经 读取的字节数，失败返回-1，读到EOF返回<count
*/
int TcpSocket::readn(void* buffer, int count)
{
	size_t nleft = count;
	ssize_t nread;
	char* bufp = (char*)buffer;

	while (nleft > 0)
	{
		if ((nread = read(m_socket, bufp, nleft)) < 0)
		{
			if (errno == EINTR)
			{
				continue;
			}
			return -1;
		}
		else if (nread == 0)
		{
			return count - nleft;
		}

		bufp += nread;
		nleft -= nread;
	}

	return count;
}
/*
* writen - 发送固定字节数
* @buf: 发送缓冲区
* @count: 要写入的字节数
* 成功返回 已经写入的字节数，失败返回-1
*/
int TcpSocket::writen(const void* buffer, int count)
{
	size_t nleft = count;
	ssize_t nwritten;
	char* bufp = (char*)buffer;

	while (nleft > 0)
	{
		if ((nwritten = write(m_socket, bufp, nleft)) < 0)
		{
			if (errno == EINTR)	// 被信号打断
			{
				continue;
			}
			return -1;
		}
		else if (nwritten == 0)
		{
			return count - nleft;
		}

		bufp += nwritten;
		nleft -= nwritten;
	}

	return count;
}