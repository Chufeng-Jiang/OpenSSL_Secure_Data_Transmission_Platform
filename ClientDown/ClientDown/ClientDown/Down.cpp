#include "Down.h"

long Down::downLoad(long& FileLength)
{
	long lastLength = GetFileSize(m_dirName);			// 获取已经下载的长度
	FileLength = lastLength;

	//开始正式下载
	m_hadDown = lastLength;//记录已经下载的长度

	int memSize = 8192;//缓冲区大小8K
	int bufLen = memSize;//理想状态每次读取8K大小的字节流
	int len;

	//创建文件描述符，准备写入文件
	int fd = open(m_fileName.c_str(), O_CREAT | O_WRONLY, S_IRWXG | S_IRWXO | S_IRWXU);
	if (fd < 0)
	{
		cout << "文件创建失败!" << endl;
		exit(0);
	}
	lseek(fd, m_fileLength, SEEK_SET);		// 将文件偏移到fileLength	

	//struct timeval t_start, t_end;//记录一次读取的时间起点和终点
	//long diff = 0;
	//long prelen = 0;
	//double speed = 0;
	//int cnt;//计数，如果多次速度小于10 kb 就杀了线程连接重连


	while (m_hadDown < m_fileLength)
	{
		//gettimeofday(&t_start, NULL); //获取开始时间
		//socket读取
		string buf = m_socket.recvMsg();
		//写入文件
		if (write(fd, buf.data(), len) == -1)
		{
			perror("write fail：");
			exit(0);
		}
		//gettimeofday(&t_end, NULL); //获取结束时间

		/*
		//计算速度
		if (t_end.tv_usec - t_start.tv_usec >= 0 && t_end.tv_sec - t_start.tv_sec >= 0)
			diff += 1000000 * (t_end.tv_sec - t_start.tv_sec) + (t_end.tv_usec - t_start.tv_usec);//us

		if (diff >= 1000000)//当一个时间段大于1s=1000000us时, 计算一次速度
		{
			speed = (double)(m_hadDown - prelen) / (double)diff * (1000000.0 / 1024.0);
			if (speed < 10)
			{
				cnt++;
			}
			else if (speed > 50)
			{
				cnt++;
			}
			prelen = m_hadDown;
			diff = 0;//清零时间段长度
		}

		if (cnt >= 5)
		{
			return 1;
		}
		*/
		m_hadDown += len;//更新已经下载的长度
		FileLength = m_hadDown;

		if (m_hadDown == m_fileLength)
			return 0;
	}

	if (m_hadDown == m_fileLength)
	{
		// cout << 下载完成
		return 0;
	}
}



void  Down::GetFileSize()
{
	//通过系统调用直接得到文件的大小
	struct stat buf;
	if (stat(m_fileName.c_str(), &buf) < 0)
		m_fileLength = -1;
	m_fileLength = (unsigned long)buf.st_size;
}



long  Down::GetFileSize(string dirName)
{
	//通过系统调用直接得到文件的大小
	struct stat buf;
	if (stat(dirName.c_str(), &buf) < 0)
		return 0;
	return  (unsigned long)buf.st_size;
}
