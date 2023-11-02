#pragma once
#include <string>
#include <iostream>
#include <openssl/aes.h>
using namespace std;
// AES: 每组明文和加密之后的密文长度相同
// 对称加密 AES 类
class AesCrypto
{
public:
	// 可使用 16byte, 24byte, 32byte 的秘钥
	AesCrypto(string key);
	~AesCrypto() = default;
	// cbc 加密
	string aesCBCEncrypt(string text);
	// cbc 解密
	string aesCBCDecrypt(string encStr);

private:
	// cbc 方式加解密
	string aesCrypto(string data, int crypto);
	// 初始化向量
	void generateIvec(unsigned char* ivec);

private:
	AES_KEY m_encKey;
	AES_KEY m_decKey;
	string m_key;	// 秘钥
};

