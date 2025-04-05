#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct _node {
//	int value;
//	struct _node* next;
//}Node;
//
//int main()
//{
//	Node* head = NULL;
//	int number;
//	do {
//		scanf("%d", &number);
//		if (number != -1) {
//			//add to linked-list
//			Node* p = (Node*)malloc(sizeof(Node));
//			p->value = number;
//			p->next = NULL;
//			//find the last
//			Node* last = head;
//			if (last) {
//				while (last->next) {
//					last = last->next;
//				}
//				//attach
//				last->next = p;
//			}
//			else {
//				head = p;
//			}
//		}
//	} while (number != -1);
//	Node* temp;
//	while (head) {
//		temp = head;
//		head = head->next;
//		free(temp);
//	}
//	return 0;
//}基础定义链表

//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct _node {
//	int value;
//	struct _node* next;
//}Node;
//
//typedef struct _list {
//	Node* head;
//	//Node* tail; 
//}List;
//
//void add(List* pList, int number);
//
//int main()
//{
//	List list;
//	int number;
//	list.head = NULL;
//	do {
//		scanf("%d", &number);
//		if (number != -1) {
//			add(&list, number);
//		}
//	} while (number != -1);
//	return 0;
//}
//
//void add(List* pList, int number)
//{
//	// add to linked-list
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->value = number;
//	p->next = NULL;
//	// find the last
//	Node* last = pList->head;
//	if (last) {
//		while (last->next) {
//			last = last->next;
//		}
//		//attach
//		last->next = p;
//	}
//	else {
//		pList->head = p;
//	}
//}链表函数的形成

//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct _node {
//	int value;
//	struct _node* next;
//}Node;
//
//typedef struct _list {
//	Node* head;
//	//Node* tail
//}List;
//
//void add(List* pList, int number);
//void print(List* pList);
//
//int main()
//{
//	List list;
//	int number;
//	list.head = NULL;
//	do {
//		scanf("%d", &number);
//		if (number != -1) {
//			add(&list, number);
//		}
//	} while (number != -1);
//	Node* p;
//	print(&list);
//	scanf("%d", &number);
//	int isFound = 0;
//	for (p = list.head; p; p = p->next) {
//		if (p->value == number) {
//			printf("找到了\n");
//			isFound = 1;
//			break;
//		}
//		if (isFound) {
//			printf("没找到\n");
//		}
//	}链表的搜索
//	Node* q;
//	for (q=NULL,p = list.head; p;  q=p, p = p->next) {
//		if (p->value == number) {
//			if (q) {
//				q->next = p->next;
//			}
//			else {
//				list.head = p->next;
//			}
//			free(p);
//			break;
//		}
//	}链表的删除
//	return 0;
//}
//
//void add(List* pList, int number)
//{
//	// add to linker-list
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->value = number;
//	p->next = NULL;
//	//find the last
//	Node* last = pList->head;
//	if (last) {
//		while (last->next) {
//			last = last->next;
//		}
//		//attach
//		last->next = p;
//	}
//	else {
//		pList->head = p;
//	}
//}
//
//void print(List* pList)
//{
//	Node* p;
//	for (p = pList->head; p; p = p->next) {
//		printf("%d\t", p->value);
//	}
//	printf("\n");
//}