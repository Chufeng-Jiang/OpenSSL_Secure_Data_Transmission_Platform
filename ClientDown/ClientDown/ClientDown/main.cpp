#include "Client.h"
#include <string>
using namespace std;

string down();
string up();
string save();
int usage();


int main()
{
	// 创建客户端操作类对象
	Client op(string{ "client.json" });
	op.start();
	int res = 0;
	while (1)
	{
		int sel = usage();
		switch (sel)
		{
		case 1:
		{
			// 文件下载
			int ret = op.m_socket->sendMsg(op.m_aes->aesCBCEncrypt(string{ "down" }));
			{

			}
			if (op.m_aes->aesCBCDecrypt(op.m_socket->recvMsg()).compare(string{ "OK" }) != 0)
			{
				break;
			}
			cout << "OK" << endl;
			string fileName = down();
			string dirName = save();
			op.m_socket->sendMsg(op.m_aes->aesCBCEncrypt(fileName));		// 发送你要下载的文件
			string length = op.m_aes->aesCBCDecrypt(op.m_socket->recvMsg());		// 读取数据
			if (length.compare(string{ "文件没找到" }) == 0)
			{
				cout << length << endl;
				break;
			}
			cout << "文件大小为 " << length << endl;
			op.m_len = atoi(length.c_str());
			op.load(dirName);
			break;
		}
		case 2:
		{
			//// 文件上传
			//op.m_socket->sendMsg(op.m_aes->aesCBCEncrypt(string{ "up" }));
			//string fileName = up();
			//op.up(fileName);
			break;
		}

		case 3:
		{
			// 聊天
			op.msg();
			break;
		}
		case 0:
		{
			res = 1; break;
		}
		default:
		{

			break;
		}

		}
		if (res == 1)
		{
			break;
		}

	}
	return 0;
}




int usage()
{
	int nSel = -1;
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n  /*     1.文件下载                                            */");
	printf("\n  /*     2.文件上传                                           */");
	printf("\n  /*     3.查看文件                                            */");
	printf("\n  /*     0.退出系统                                            */");
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n\n  选择:");

	scanf("%d", &nSel);
	while (getchar() != '\n');

	return nSel;
}


string down()
{
	int nSel = -1;
	cout << "|||输入你要下载的文件名称:" << endl << ">";

	string fileName;
	cin >> fileName;

	return fileName;
}


string up()
{
	int nSel = -1;
	cout << "|||输入你要上传的文件名称:" << endl << ">";

	string fileName;
	cin >> fileName;

	return fileName;
}


string save()
{
	int nSel = -1;
	cout << "|||输入你要保存的路径:" << endl << ">";

	string fileName;
	cin >> fileName;

	return fileName;
}

