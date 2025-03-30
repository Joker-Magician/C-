#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#define MaxSize 100//储存数据元素的最大个数
///*队列的顺序存储结构 通常由一个一维数组和一个记录队列头元素位置的
//变量front以及一个记录队列尾元素位置的变量rear组成*/
//
//struct QNode {
//	int Data[MaxSize];
//	int rear;
//	int front;
//};
//typedef struct QNode* Queue;
//
//void AddQ(Queue PtrQ, int item)
//{
//	if ((PtrQ->rear + 1) % MaxSize == PtrQ->front) {
//		printf("队列满");
//		return;
//	}
//	PtrQ->rear = (PtrQ->rear + 1) % MaxSize;//通过取余构成循环队列
//	PtrQ->Data[PtrQ->rear] = item;
//}//入队列
//int Delete(Queue PtrQ)
//{
//	if (PtrQ->front == PtrQ->rear) {
//		printf("队列空");
//		return -1;
//	}
//	else {
//		PtrQ->front = (PtrQ->front + 1) % MaxSize;
//		return PtrQ->Data[PtrQ->front];
//	}
//}//出队列
//
//int main()
//{
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define MaxSize 100
///*队列的链式存储结构 可以用一个单链表实现，插入和删除操作分别在
//链表的两头进行*/
//
//struct Node {
//	int Data;
//	struct Node* Next;
//};
//struct QNode {  /*链队列结构*/
//	struct Node* rear;/*指向队尾节点*/
//	struct Node* front;/*指向队头节点*/
//};
//typedef struct QNode* Queue;
//Queue PtrQ;
//
//int Delete(Queue PtrQ)
//{
//	struct Node* FrontCell;
//	int FrontElem;
//
//	if (PtrQ->front == NULL) {
//		printf("队列空"); return -1;//返回错误信息
//	}
//	FrontCell = PtrQ->front;
//	if (PtrQ->front == PtrQ->rear)
//		PtrQ->front = PtrQ->rear = NULL;//判别队列是否只有一个元素
//	else
//		PtrQ->front = PtrQ->front->Next = NULL;
//	FrontElem = FrontCell->Data;
//	free(FrontCell);
//	return FrontElem;
//}//入队列