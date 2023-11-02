#include <iostream>
#include "ClientOP.h"

using namespace std;

int usage();
int main()
{
	// 创建客户端操作类对象
	ClientOP op("client.json");
	while (1)
	{
		int sel = usage();
		switch (sel)
		{
		case CONSULT:
			// 秘钥协商
			op.secKeyConsult();
			break;
		case CHECK:
			// 秘钥校验
			op.seckeyCheck();
			break;
		case Logout:
			// 秘钥注销
			op.seckeyLogout();
		default:
			cout << "客户端退出, bye,byte..." << endl;
			return 0;
		}
	}
	return 0;

}



int usage()
{
	int nSel = -1;
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n  /*     1.密钥协商                                            */");
	printf("\n  /*     2.密钥校验                                            */");
	printf("\n  /*     3.密钥注销                                            */");
	printf("\n  /*     0.退出系统                                            */");
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n\n  选择:");

	scanf("%d", &nSel);
	while (getchar() != '\n');

	return nSel;
}