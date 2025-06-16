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
int Index_BF(SString S, SString T) 
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]){
			++i;
			++j;
		}
		else {
			i = i - j + 2; 
			j = 1;
		}
	}
	if (j >= T.length) return i - T.length;
	else return 0;
}

/*�������ĵ�pos���ַ���ģʽ���ĵ�һ���ַ��Ƚϣ�
����ȣ���������ȽϺ����ַ�
�����ȣ�����������һ�ַ���������ģʽ���ĵ�һ���ַ��Ƚ�
 ֱ��������һ�������Ӵ��ַ�������ģʽ����ȡ�����ֵΪS����Tƥ��������е�һ���ַ�����ţ���ƥ��ɹ�
 ����ƥ��ʧ�ܣ�����ֵ0*/

/*KMP�㷨*/
void get_nextval(SString T, int nextval[])
{
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			if (T.ch[i] != T.ch[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	}
}

int main()
{


	return 0;
}