//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct _node {
//	int value;
//	struct _node* next;
//}Node;
//
//typedef struct _list {
//	Node* head;
//}List;
//
//void add(List* pList, int number);
//void freeList(List* pList);
//void get(List* pList,int a);
//void insert(List* pList, int a, int e);
//void del(List* pList, int a);
//void show(List* pList);
//
//int main()
//{
//	List list;
//	int n,m;
//	int number;
//	list.head = NULL;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &number);
//		add(&list, number);
//	}
//
//	scanf("%d", &m);
//	for (int i = 0; i < m; i++) {
//		char command[10];
//		scanf("%s", command);
//		if (strcmp(command, "get") == 0) {
//			int a;
//			scanf("%d", &a);
//			get(&list, a);
//		}
//		else if (strcmp(command, "insert") == 0) {
//			int a, e;
//			scanf("%d %d", &a, &e);
//			insert(&list, a, e);
//		}
//		else if (strcmp(command, "delete") == 0) {
//			int a;
//			scanf("%d", &a);
//			del(&list, a);
//		}
//		else if (strcmp(command, "show") == 0) {
//			show(&list);
//		}
//	}
//	freeList(&list);
//	return 0;
//}
//
//void add(List* pList, int number)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	if (!p) {
//		fprintf(stderr, "Memory allocation failed!\n");
//		exit(1);
//	}
//	p->value = number;
//	p->next = pList->head;
//	pList->head = p;
//	/*Node* last = pList->head;
//	if (last) {
//		while (last->next) {
//			last = last->next;
//		}
//		last->next = p;
//	}
//	else {
//		pList->head = p; 
//	}*/
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
//}
//void get(List* pList,int a)
//{
//	int cnt = 1,isFound=0;
//	Node* p;
//	for (p = pList->head; p; p = p->next) {
//		if (cnt == a) {
//			isFound = 1;
//			break;
//		}
//		cnt++;
//	}
//	if (isFound == 1) {
//		printf("%d\n", p->value);
//	}
//	else {
//		printf("get fail\n");
//	}
//}
//void insert(List* pList, int a, int e)
//{
//	int cnt = 1, isFound = 0;
//	Node* p = pList->head;
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	if (!newNode) {
//		fprintf(stderr, "Memory allocation failed!\n");
//		exit(1);
//	}
//	newNode->value = e;
//	newNode->next = NULL;
//	if (a == 1) {
//		newNode->next = pList->head;
//		pList->head = newNode;
//		printf("insert OK\n");
//		return;
//	}
//	for (p = pList->head; p; p = p->next) {
//		if (cnt == a - 1) {
//			isFound = 1;
//			break;
//		}
//		cnt++;
//	}
//	if (isFound == 1) {
//		newNode->next = p->next;
//		p->next = newNode;
//		printf("insert OK\n");
//	}
//	else if (isFound == 0) {
//		printf("insert fail\n");
//		free(newNode);
//	}
//}
//void del(List* pList, int a)
//{
//	Node* temp;
//	if (a == 1) {
//		temp = pList->head;
//		pList->head = pList->head->next;
//		free(temp);
//		printf("delete OK\n");
//		return;
//	}
//	Node* p = pList->head;
//	int cnt = 1;
//	while(p && cnt < a - 1) {
//		p = p->next;
//		cnt++;
//	}
//	if (p && p->next) {
//		temp = p->next;
//		p->next = p->next->next;
//		free(temp);
//		printf("delete OK\n");
//	}
//	else {
//		printf("delete fail\n");
//	}
//}
//void show(List* pList)
//{
//	Node* p = pList->head;
//	if (p) {
//		for (p = pList->head; p; p = p->next) {
//			printf("%d ", p->value);
//		}
//		printf("\n");
//	}
//	else {
//		printf("Link list is empty\n");
//		}
//}