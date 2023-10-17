#ifndef _TEACHER_H
#define _TEACHER_H
typedef struct _Teacher
{
	char name[64]; 
	int age;   
	char *p;
	long plen;
}Teacher;

// 编码结构体
int encodeTeacher(Teacher* p, char** outData, int* outlen);
// 解码结构体
int decodeTeacher(char* inData, int inLen, Teacher**p);
// 释放内存函数
void freeTeacher(Teacher** p);

#endif	// _TEACHER_H
