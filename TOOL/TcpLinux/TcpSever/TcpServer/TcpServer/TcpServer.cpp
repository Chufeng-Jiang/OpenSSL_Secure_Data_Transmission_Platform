#include "TcpServer.h"


int TcpServer::setListen(const unsigned short port)
{
	int ret = 0;
	sockaddr_in saddr;
	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htons(port);
	saddr.sin_family = htonl(AF_INET);

	m_lfd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_lfd == -1)
	{
		ret = errno;
		return ret;
	}

	int on = 1;
	// 设置端口复用
	ret = setsockopt(m_lfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	if (ret == -1)
	{
		ret = errno;
		return ret;
	}

	// 监听的套接字绑定本地IP和端口
	ret = bind(m_lfd, (struct sockaddr*)&saddr, sizeof(saddr));
	if (ret == -1)
	{
		ret = errno;
		return ret;
	}

	ret = listen(m_lfd, 128);
	if (ret == -1)
	{
		ret = errno;
		return ret;
	}

	return ret;

}

TcpSocket* TcpServer::acceptConnet(int wait_seconds)
{

	int ret;
	if (wait_seconds > 0)
	{
		fd_set accept_fdset;
		timeval timeout;
		FD_ZERO(&accept_fdset);
		FD_SET(m_lfd, &accept_fdset);
		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do
		{
			// 检测读集合
			ret = select(m_lfd + 1, &accept_fdset, NULL, NULL, &timeout);
		} while (ret < 0 && errno == EINTR);	// 被信号中断, 再次进入循环
		if (ret <= 0)
		{
			return nullptr;
		}
	}
	// 一但检测出 有select事件发生，表示对等方完成了三次握手，客户端有新连接建立
	// 此时再调用accept将不会堵塞
	sockaddr_in caddr;
	socklen_t addrlen = sizeof(sockaddr_in);
	int connfd = accept(m_lfd, (sockaddr*)&caddr, &addrlen); //返回已连接套接字
	if (connfd == -1)
	{
		return nullptr;
	}

	return new TcpSocket(connfd);
}

void TcpServer::closeFd()
{
	close(m_lfd);
}
