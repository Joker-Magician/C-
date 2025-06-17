#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}Node, * LinkList;

//void CreateList(LinkList L)
//{
//	Node* tail = L;
//	int x;
//	while (1)
//	{
//		scanf("%d", &x);
//		if (x == -1) 
//			break;
//		Node* newNode = (Node*)malloc(sizeof(Node));
//		newNode->data = x;
//		newNode->next = NULL;
//		tail->next = newNode;
//		tail = newNode;
//	}
//}

void MergeLinkList(LinkList LC,LinkList LA, LinkList LB)
{
	Node* pa = LA->next;
	Node* pb = LB->next;
	Node* tail = LC;

	while (pa != NULL && pb != NULL)
	{
		if (pa->data <= pb->data) {
			tail->next = pa;
			tail = pa;
			pa = pa->next;
		}
		else {
			tail->next = pb;
			tail = pb;
			pb = pb->next;
		}
	}
	tail->next = pa ? pa : pb;
	/*if (pa != NULL) {
		tail->next = pa;
	}
	if (pb != NULL) {
		tail->next = pb;
	}*/
	free(LA);//释放表头
	free(LB);
}


void InsList(LinkList L, int e)
{
	Node* p = L;
	while (p->next != NULL && p->data < e)
		p = p->next;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("内存分配失败！\n");
		return;
	}
	newNode->data = e;
	newNode->next = p->next;
	p->next = newNode;
}

void CreateSortedList(LinkList L)
{
	int x;
	while (1)
	{
		scanf("%d", &x);
		if (x == 0)
			break;
		InsList(L, x);
	}
}
