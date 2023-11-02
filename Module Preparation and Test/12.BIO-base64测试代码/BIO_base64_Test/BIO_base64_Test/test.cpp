#include <iostream>
#include <string>
#include <stdlib.h>  
#include <openssl/rsa.h>
#include <openssl/pem.h>
using namespace std;


void WriteEncode()
{
	char  data[] = "hello, world";
	// 创建base64编码的bio对象
	BIO* b64 = BIO_new(BIO_f_base64());

	// 最终在内存中得到一个base64编码之后的字符串
	BIO* mem = BIO_new(BIO_s_mem());

	// 将两个bio对象串联, 结构: b64->mem
	BIO_push(b64, mem);

	// 将要编码的数据写入到bio对象中
	BIO_write(b64, &data, strlen(data) + 1);

	// 将数据从bio对象对应的内存中取出 -> char*
	BUF_MEM* ptr = NULL;

	// 数据通过ptr指针传出
	BIO_get_mem_ptr(b64, &ptr);
	char* buf = new char[ptr->length+1];
	memcpy(buf, ptr->data, ptr->length);

	printf("编码之后的数据: %s\n", buf);
	printf("==============================\n");

}

void ReadDecode()
{
	// 要解码的数据
	char  data[] = "Good evening, California";
	// 创建base64解码的bio对象
	BIO* b64 = BIO_new(BIO_f_base64());

#if 0
	// 存储要解码的数据
	BIO* mem = BIO_new(BIO_s_mem());
	// 将数据写到mem对应的内存中
	BIO_write(mem, data, strlen(data));
#else
	BIO* mem = BIO_new_mem_buf(&data, strlen(data) + 1);
#endif
	// 组织bio链
	BIO_push(b64, mem);
	// 读数据
	char buf[1024];
	BIO_read(b64, buf, 1024);
	printf("base64解码的数据：%s\n", buf);
}


// 编码
char* Base64Encode(char* input, int length)
{
	BIO* bmem = NULL;
	BIO* b64 = NULL;
	BUF_MEM* bptr = NULL;
	b64 = BIO_new(BIO_f_base64());

	bmem = BIO_new(BIO_s_mem());
	b64 = BIO_push(b64, bmem);
	BIO_write(b64, input, length);
	BIO_flush(b64);
	BIO_get_mem_ptr(b64, &bptr);
	char* buff = (char*)malloc(bptr->length + 1);
	memcpy(buff, bptr->data, bptr->length);
	buff[bptr->length] = 0;
	BIO_free_all(b64);
	return buff;
}

// 解码
char* Base64Decode(char* input, int length)
{
	BIO* b64 = NULL;
	BIO* bmem = NULL;
	char* buffer = (char*)malloc(length);
	memset(buffer, 0, length);
	b64 = BIO_new(BIO_f_base64());
	bmem = BIO_new_mem_buf(input, length);
	bmem = BIO_push(b64, bmem);
	BIO_read(bmem, buffer, length);
	BIO_free_all(bmem);
	return buffer;
}

int main()
{
	
	WriteEncode();
	ReadDecode();
	
	char data[] = "hello, world";
	char*  str = Base64Encode(data, strlen(data)+1);
	printf("\n带参数____编码后的字符串为：%s \n", str);
	return 0;
}