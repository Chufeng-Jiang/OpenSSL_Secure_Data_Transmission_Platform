#define _CRT_SECURE_NO_WARNINGS
//#include <openssl/md5.h>		// md5 头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>

void getMD5(const char* str, char* result)
{
	EVP_MD_CTX* mdctx;
	unsigned int md5_digest_len = EVP_MD_size(EVP_md5());//求属性长度
    //MD5_CTX ctx;
	
	// 初始化
	//MD5_Init(&ctx);
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, EVP_md5(), NULL);

	// 添加数据
	//MD5_Update(&ctx, str, strlen(str));
	EVP_DigestUpdate(mdctx, str, strlen(str));

	// 计算结果
	unsigned char md[16] = { 0 };
	
	//MD5_Final(md, &ctx);
	EVP_DigestFinal_ex(mdctx, md, &md5_digest_len);

	for (int i = 0; i < 16; ++i)
	{
		sprintf(&result[i * 2], "%02x", md[i]);
	}
	EVP_MD_CTX_free(mdctx);
}

int main()
{
	char result[33] = { 0 };
	getMD5("hello, md5", result);
	printf("md5 value: %s\n", result);
	system("pause");

	return 0;
}