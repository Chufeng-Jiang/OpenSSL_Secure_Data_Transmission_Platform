#include "teacher.h"
#include "itcast_asn1_der.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	typedef struct _Teacher
	{
		char name[64];
		int age;
		char *p;
		long plen;
	}Teacher;
*/
int encodeTeacher(Teacher * p, char ** outData, int * outlen)
{
	ITCAST_ANYBUF * head = NULL;
	ITCAST_ANYBUF * temp = NULL;
	ITCAST_ANYBUF * next = NULL;

	//Encode the name
	//DER_ITCAST_String_To_AnyBuf(ITCAST_ANYBUF **pOriginBuf,unsigned char* strOrigin,int strOriginLen)
	DER_ITCAST_String_To_AnyBuf(&temp, p->name, strlen(p->name)+1); //把Char类型转换成了ITCAST_AnyBuf，放到了temp里
	DER_ItAsn1_WritePrintableString(temp, &head); // temp传给head
	DER_ITCAST_FreeQueue(temp);
	next = head; //next指向head

	//Encode the age
	//head不变，新编码的接到next->next位置
	DER_ItAsn1_WriteInteger(p->age, &next->next);
	next = next->next; //head不变，next后移一位

	//Encode p
	EncodeChar(p->p,strlen(p->p) + 1, &next->next);
	next = next->next;

	//Encode plen
	DER_ItAsn1_WriteInteger(p->plen, &next->next);

	//Sequence
	DER_ItAsn1_WriteSequence(head, &temp);

	//Value
	*outData = temp->pData;
	*outlen = temp->dataLen;

	//Free
	DER_ITCAST_FreeQueue(head);

	return 0;
}

/*
	typedef struct _Teacher
	{
		char name[64];
		int age;
		char *p;
		long plen;
	}Teacher;
*/
int decodeTeacher(char * inData, int inLen, Teacher ** p)
{
	ITCAST_ANYBUF * head = NULL;
	ITCAST_ANYBUF * temp = NULL;
	ITCAST_ANYBUF * next = NULL;

	Teacher *pt = (Teacher*)malloc(sizeof(Teacher));
	if (pt == NULL)
	{
		return -1;
	}

	//将inData反序列化成链表
	DER_ITCAST_String_To_AnyBuf(&temp,inData, inLen);
	DER_ItAsn1_ReadSequence(temp, &head);
	DER_ITCAST_FreeQueue(temp);
	next = head;

	//解码name
	DER_ItAsn1_ReadPrintableString(next, &temp);
	memcpy(pt->name, temp->pData, temp->dataLen);
	DER_ITCAST_FreeQueue(temp);
	next = next->next;

	//解码age
	//此处不能用Decode，因为常量不能作为左值
	DER_ItAsn1_ReadInteger(next, &pt->age);
	next = next->next;

	//解码p
	int len = 0;
	DecodeChar(next, &pt->p, &len);
	next = next->next;

	//解码plen
	DER_ItAsn1_ReadInteger(next, &pt->plen);

	//给输出参数赋值
	*p = pt;

	//释放内存
	DER_ITCAST_FreeQueue(head);

	return 0;
}

void freeTeacher(Teacher ** p)
{
	if (*p != NULL)
	{
		if ((*p)->p != NULL)
		{
			free((*p)->p);
		}
		free((*p));
	}
}
