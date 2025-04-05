//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct _node {
//	int value_real;
//	int value_imaginary;
//	struct _node* next;
//}Node;             
//
//typedef struct _list {
//	Node* head;
//	Node* tail;
//}List;
//
//void add(List* pList, int real,int imaginary);
//void freeList(List* pList);
//
//int main()
//{
//	List list;
//	int n;
//	int j = 0, k = 0;
//	int value_real, value_imaginary;
//	list.head = NULL;
//	list.tail = NULL;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d%d", &value_real, &value_imaginary);
//		add(&list, value_real, value_imaginary);
//	}
//	Node* q = list.head;
//	for (q = list.head; q; q = q->next) {
//		j += q->value_real;
//		k += q->value_imaginary;
//	}
//	printf("%d+%di", j, k);
//	freeList(&list);
//	return 0;
//}
//
//void add(List* pList, int real, int imaginary)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	if (!p) {
//		fprintf(stderr, "Memory allocation failed\n");
//		exit(1);
//	}
//	p->value_real = real;
//	p->value_imaginary = imaginary;
//	p->next = NULL;
//	Node* last = pList->head;
//	if (pList->head) {
//		pList->tail->next = p;// 直接在尾部添加节点
//		pList->tail = p;
//	}
//	else {
//		pList->head = p;
//		pList->tail = p; // 同时更新尾指针
//	}
//}
//void freeList(List* pList)
//{
//	Node* curr = pList->head;
//	while (curr) {
//		Node* temp = curr;
//		curr = curr->next;
//		free(temp);
//	}
//	pList->head = NULL;
//	pList->tail = NULL;
//}