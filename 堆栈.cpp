#define _CRT_SECURE_NO_WARNINGS
//#define MaxSize 100//储存数据元素的最大个数
//#include<stdio.h>
////栈的顺序存储实现
////栈的顺序存储结构通常由一个一维数组和一个记录栈顶元素位置的变量组成
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
////入栈
//void Push(Stack PtrS, ElementType item)
//{
//	if (PtrS->Top == MaxSize - 1) {
//		printf("堆栈满"); return;
//	}
//	else {
//		PtrS->Data[++(PtrS->Top)] = item;
//		return;
//	}
//}
////出栈
//ElementType Pop(Stack PtrS)
//{
//	if (PtrS->Top == -1) {
//		printf("堆栈空");
//		return -1;
//	}
//	else {
//		return (PtrS->Data[(PtrS->Top)--]);
//	}
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define MaxSize 100
////堆栈的链式存储实现
////栈的链式存储结构实际上就是一个单链表，叫做链栈
////插入和删除操作只能在链栈的栈顶进行。栈顶指针Top应该在链表的头部
//
//typedef struct SNode* Stack;
//struct SNode {
//	int Data;
//	struct SNode* Next;
//};
//
//Stack CreateStack()
//{/*构建一个堆栈的头节点，返回指针*/
//	Stack S;
//	S = (Stack)malloc(sizeof(struct SNode));
//	S->Next = NULL;
//	return S;
//}
//int IsEmpty(Stack S)
//{/*判断堆栈s是否为空，若为空函数返回整数1，否则返回0*/
//	return (S->Next == NULL);
//}
//void Push(int item, Stack S)
//{/*将元素item压入堆栈S*/
//	Stack TmpCell;
//	TmpCell = (Stack)malloc(sizeof(Stack));
//	TmpCell->Data = item;
//	TmpCell->Next = S->Next;
//	S->Next = TmpCell;
//}
//int Pop(Stack S)
//{/*删除并返回堆栈s的栈顶元素*/
//	Stack FirstCell;
//	int TopElem;
//	if (IsEmpty(S)) {
//		printf("堆栈空"); return NULL;
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
