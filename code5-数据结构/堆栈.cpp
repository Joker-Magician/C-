#define _CRT_SECURE_NO_WARNINGS
//#define MaxSize 100//��������Ԫ�ص�������
//#include<stdio.h>
////ջ��˳��洢ʵ��
////ջ��˳��洢�ṹͨ����һ��һά�����һ����¼ջ��Ԫ��λ�õı������
//typedef struct SNode* Stack;
//typedef ElementType int;
//struct SNode {
//	ElementType Data[MaxSize];
//	int Top;
//};
//
//void Push(Stack PtrS, ElementType item);
//ElementType Pop(Stack PtrS);
// 
//int main()
//{
//	return 0;
//}
//
////��ջ
//void Push(Stack PtrS, ElementType item)
//{
//	if (PtrS->Top == MaxSize - 1) {
//		printf("��ջ��"); return;
//	}
//	else {
//		PtrS->Data[++(PtrS->Top)] = item;
//		return;
//	}
//}
////��ջ
//ElementType Pop(Stack PtrS)
//{
//	if (PtrS->Top == -1) {
//		printf("��ջ��");
//		return -1;
//	}
//	else {
//		return (PtrS->Data[(PtrS->Top)--]);
//	}
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define MaxSize 100
////��ջ����ʽ�洢ʵ��
////ջ����ʽ�洢�ṹʵ���Ͼ���һ��������������ջ
////�����ɾ������ֻ������ջ��ջ�����С�ջ��ָ��TopӦ���������ͷ��
//
//typedef struct SNode* Stack;
//struct SNode {
//	int Data;
//	struct SNode* Next;
//};
//
//Stack CreateStack()
//{/*����һ����ջ��ͷ�ڵ㣬����ָ��*/
//	Stack S;
//	S = (Stack)malloc(sizeof(struct SNode));
//	S->Next = NULL;
//	return S;
//}
//int IsEmpty(Stack S)
//{/*�ж϶�ջs�Ƿ�Ϊ�գ���Ϊ�պ�����������1�����򷵻�0*/
//	return (S->Next == NULL);
//}
//void Push(int item, Stack S)
//{/*��Ԫ��itemѹ���ջS*/
//	Stack TmpCell;
//	TmpCell = (Stack)malloc(sizeof(Stack));
//	TmpCell->Data = item;
//	TmpCell->Next = S->Next;
//	S->Next = TmpCell;
//}
//int Pop(Stack S)
//{/*ɾ�������ض�ջs��ջ��Ԫ��*/
//	Stack FirstCell;
//	int TopElem;
//	if (IsEmpty(S)) {
//		printf("��ջ��"); return NULL;
//	}
//	else {
//		FirstCell = S->Next;
//		S->Next = FirstCell->Next;
//		TopElem = FirstCell->Data;
//		free(FirstCell);
//		return TopElem;
//	}
//}
//
//int main() {
//	return 0;
//}
