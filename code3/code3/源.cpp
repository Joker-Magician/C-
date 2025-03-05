#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MaxSize 11
typedef char ElementType[8];

typedef struct _node {
	ElementType Data;
	int curr;
}NodeType;

NodeType space[MaxSize];

typedef struct _list {
	int elem;			//��̬����洢�ռ��ַ����ʼԪ�ص��±꣩
	int length;			//��̬�����е�Ԫ����Ŀ
	int listSize;		//��̬����ǰ�ĳ��ȣ�������Ԫ����Ŀ
}List;					

void InitSpace_SL() {
	memset(space, 0, sizeof(space));//��ָ��space��ָ����ڴ������ǰsizeof(space)���ֽ�����Ϊָ��ֵ0���ɸ�Ϊ�������֣�
	for (int i = 0; i < MaxSize - 1; ++i) {//�����ڳ�ʼ�����顢�ṹ���Ϊ�ض���ֵ
		space[i].curr = i + 1;
	}
	space[MaxSize - 1].curr = 0;
}

int LocateElem_SL(List& S, ElementType e)
{
	int i;
	i = S.elem;
	while (i && strcmp(space[i].Data, e)) {
		i = space[i].curr;
	}
	return i;
}
int Malloc_SL() {
	int i = space[0].curr;
	if (space[0].curr) {
		space[0].curr = space[space[0].curr].curr;
	}
	return i;
}

void Free_SL(int k) {
	space[k].curr = space[0].curr;
	space[0].curr = k;
}

void insert(List& S, ElementType e, int a)
{
	if (S.length >= S.listSize) {
		printf("List is full.\n");
		return;
	}
	int newIndex = Malloc_SL();
	if (newIndex == 0) {
		printf("No space available.\n");
		return;
	}
	strcpy(space[newIndex].Data, e);
	if (a == 0) {
		space[newIndex].curr = S.elem;
		S.elem = newIndex;
	}
	else {
		int prevIndex = S.elem;
		for (int i = 0; i < a; ++i) {
			prevIndex = space[prevIndex].curr;
		}
		space[newIndex].curr = space[prevIndex].curr;
		space[prevIndex].curr = newIndex;
	}
	S.length++;
}

int main()
{
	return 0;
}