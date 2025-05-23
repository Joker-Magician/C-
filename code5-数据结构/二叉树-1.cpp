#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MaxSize 100
//#define ERROR -1
//#define TRUE 1
////二叉树的存储
//
////数组存储
////节点 A B O ^ ^ M ^ ^ ^ ^  ^  ^  C
////序号 1 2 3 4 5 6 7 8 9 10 11 12 13
////可以使用数组但会造成部分空间的浪费
//
////链表存储
//typedef int ElementType;
//typedef struct TreeNode* BinTree;
//typedef BinTree Position;
//struct TreeNode {
//	ElementType Data;
//	BinTree Left;
//	BinTree Right;
//};
//
////遍历
////先序遍历
//void PreOrderTravereal(BinTree BT)
//{										
//	if (BT) {							//遍历过程：
//		printf("%d", BT->Data);			//(1)访问根节点（将其printf出去）
//		PreOrderTravereal(BT->Left);	//(2)先序遍历其左子树
//		PreOrderTravereal(BT->Right);	//(3)先序遍历其右子树
//	}
//}
////中序遍历
//void InOrderTravereal(BinTree BT)
//{										
//	if (BT) {							//遍历过程：
//		InOrderTravereal(BT->Left);		//(1)中序遍历其左子树
//		printf("%d", BT->Data);			//(2)访问根节点（将其printf出去）
//		InOrderTravereal(BT->Right);	//(3)中序遍历其右子树
//	}
//}
////后序遍历
//void PostOrderTravereal(BinTree BT)
//{
//	if (BT) {							//遍历过程：
//		PostOrderTravereal(BT->Left);	//(1)后序遍历其左子树
//		PostOrderTravereal(BT->Right);	//(2)后序遍历其右子树
//		printf("%d",BT->Data);			//(3)访问根节点（将其printf出去）
//	}
//}
//
///*总结：
//先序遍历就是在第一次遇到节点时访问(打印)节点
//中序遍历则是在第二次遇到节点时访问(打印)节点
//后序序遍历是在第三次遇到节点时访问(打印)节点
//每个节点都会遇到三次，只不过叶节点是连着遇到三次
//*/
//
//
//
///*中序遍历非递归遍历算法*/
////遇到一个节点，就把他压栈，并去遍历它的左子树；
////当左子树遍历结束后，从栈顶弹出这个节点并访问它；
////然后按其右指针再去中序遍历该节点的右子树
//
////尾递归的方法遍历二叉树
//typedef struct SNode* Stack;
//struct SNode {
//	BinTree Data[MaxSize];
//	int Top;
//};
//
//void Push(Stack PtrS, BinTree item)
//{
//	if (PtrS->Top == MaxSize - 1) {
//		printf("堆栈满"); return;
//	}
//	else {
//		PtrS->Data[++(PtrS->Top)] = item;
//		return;
//	}
//}
//BinTree Pop(Stack PtrS)
//{
//	if (PtrS->Top == -1) {
//		printf("堆栈空");
//		return NULL;
//	}
//	else {
//		return (PtrS->Data[(PtrS->Top)--]);
//	}
//}
//
//Stack CreateStack()
//{
//	Stack S = (Stack)malloc(sizeof(struct SNode));
//	if (S == NULL) {
//		printf("内存分配失败");
//		exit(1);
//	}
//	S->Top = -1;
//	return S;
//}
//
//int IsEmpty(Stack PtrS)
//{
//	if (PtrS->Top == -1)
//		return ERROR;
//	else
//		return TRUE;
//}
//
//void InOrderTravereal_2(BinTree BT){
//	BinTree T = BT;
//	Stack S = CreateStack();	//创建并初始化堆栈S*
//	while (T || !IsEmpty(S)) {
//		while (T) {					//一直向左并将沿途节点压入堆栈
//			Push(S, T);/*第一次遇到节点*/
//			T = T->Left;
//		}
//		if (!IsEmpty(S)) {
//			T = Pop(S);			//节点弹出堆栈
//			printf("%5d", T->Data); //(访问)打印节点 PS：第二次遇到节点
//			T = T->Right;			//转向右子树
//		}
//	}
//}
//
////层序遍历
//struct QNode {
//	BinTree Data[MaxSize];
//	int rear;
//	int front;
//};
//typedef struct QNode* Queue;
//
//Queue CreatQueue()
//{
//	Queue Q = (Queue)malloc(sizeof(struct QNode));
//	if (Q == NULL) {
//		printf("内存分配失败");
//		exit(1);
//	}
//	Q->rear = -1;
//	Q->front = -1;
//	return Q;
//}
//
//void AddQ(Queue PtrQ, BinTree item)
//{
//	if ((PtrQ->rear + 1) % MaxSize == PtrQ->front) {
//		printf("队列满");
//		return;
//	}
//	PtrQ->rear = (PtrQ->rear + 1) % MaxSize;
//	PtrQ->Data[PtrQ->rear] = item;
//}
//
//ElementType IsEmptyQ(Queue PtrQ){
//	if (PtrQ->rear ==  PtrQ->front)
//		return ERROR;
//	return TRUE;
//}
//
//BinTree DeleteQ(Queue PtrQ)
//{
//	if (PtrQ->front == PtrQ->rear) {
//		printf("队列空");
//		return NULL;
//	}
//	else {
//		PtrQ->front = (PtrQ->front + 1) % MaxSize;
//		return PtrQ->Data[PtrQ->front];
//	}
//}
//
//void LevelOrderTraversal(BinTree BT)
//{
//	Queue Q;
//	BinTree T;
//	Q = CreatQueue();
//	AddQ(Q, BT);
//	while (!IsEmptyQ(Q)) {
//		T = DeleteQ(Q);
//		printf("%d\n", T->Data);
//		if (T->Left) AddQ(Q, T->Left);
//		if (T->Right) AddQ(Q, T->Right);
//	}
//}