#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 100
#define ERROR -1
#define TURE 1
//�������Ĵ洢

//����洢
//�ڵ� A B O ^ ^ M ^ ^ ^ ^  ^  ^  C
//��� 1 2 3 4 5 6 7 8 9 10 11 12 13
//����ʹ�����鵫����ɲ��ֿռ���˷�

//����洢
typedef int ElementType;
typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

//����
//�������
void PreOrderTravereal(BinTree BT)
{										
	if (BT) {							//�������̣�
		printf("%d", BT->Data);			//(1)���ʸ��ڵ㣨����printf��ȥ��
		PreOrderTravereal(BT->Left);	//(2)���������������
		PreOrderTravereal(BT->Right);	//(3)���������������
	}
}
//�������
void InOrderTravereal(BinTree BT)
{										
	if (BT) {							//�������̣�
		InOrderTravereal(BT->Left);		//(1)���������������
		printf("%d", BT->Data);			//(2)���ʸ��ڵ㣨����printf��ȥ��
		InOrderTravereal(BT->Right);	//(3)���������������
	}
}
//�������
void PostOrderTravereal(BinTree BT)
{
	if (BT) {							//�������̣�
		PostOrderTravereal(BT->Left);	//(1)���������������
		PostOrderTravereal(BT->Right);	//(2)���������������
		printf("%d",BT->Data);			//(3)���ʸ��ڵ㣨����printf��ȥ��
	}
}

/*�ܽ᣺
������������ڵ�һ�������ڵ�ʱ����(��ӡ)�ڵ�
������������ڵڶ��������ڵ�ʱ����(��ӡ)�ڵ�
������������ڵ����������ڵ�ʱ����(��ӡ)�ڵ�
ÿ���ڵ㶼���������Σ�ֻ����Ҷ�ڵ���������������
*/



/*��������ǵݹ�����㷨*/
//����һ���ڵ㣬�Ͱ���ѹջ����ȥ����������������
//�����������������󣬴�ջ����������ڵ㲢��������
//Ȼ������ָ����ȥ��������ýڵ��������

//β�ݹ�ķ�������������
typedef struct SNode* Stack;
struct SNode {
	BinTree Data[MaxSize];
	int Top;
};

void Push(Stack PtrS, BinTree item)
{
	if (PtrS->Top == MaxSize - 1) {
		printf("��ջ��"); return;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}
BinTree Pop(Stack PtrS)
{
	if (PtrS->Top == -1) {
		printf("��ջ��");
		return NULL;
	}
	else {
		return (PtrS->Data[(PtrS->Top)--]);
	}
}

Stack CreateStack()
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	if (S == NULL) {
		printf("�ڴ����ʧ��");
		exit(1);
	}
	S->Top = -1;
	return S;
}

int IsEmpty(Stack PtrS)
{
	if (PtrS->Top == -1)
		return ERROR;
	else
		return TURE;
}

void InOrderTravereal_2(BinTree BT){
	BinTree T = BT;
	Stack S = CreateStack();	//��������ʼ����ջS*
	while (T || !IsEmpty(S)) {
		while (T) {					//һֱ���󲢽���;�ڵ�ѹ���ջ
			Push(S, T);/*��һ�������ڵ�*/
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);			//�ڵ㵯����ջ
			printf("%5d", T->Data); //(����)��ӡ�ڵ� PS���ڶ��������ڵ�
			T = T->Right;			//ת��������
		}
	}
}