#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN 255

typedef struct {
	char ch[MAXLEN + 1]; //�洢����һά���飬��1��λ�ÿ�ʼ�洢
	int length; //���ĵ�ǰ����
}SString;

/*������ʽ�洢*/
/*#define CHUNKSIZE 80 //��Ĵ�С�����û�����
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct {
	Chunk* head, * tail;
	int curlen;
}LString;*/

/*����ģʽƥ���㷨*/
/*BF�㷨���򵥴ֱ���Ч�ʽϵ�*/

/*�������ĵ�pos���ַ���ģʽ���ĵ�һ���ַ��Ƚϣ�
	����ȣ���������ȽϺ����ַ�
	�����ȣ�����������һ�ַ���������ģʽ���ĵ�һ���ַ��Ƚ�*/

int main()
{


	return 0;
}