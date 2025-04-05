#define _CRT_SECURE_NO_WARNINGS
/*已有a、b两个链表，每个链表中的结点包括学号、成绩。要求把两个链表合并，按学号升序排列。
第一行，a、b两个链表元素的数量N、M, 用空格隔开。 接下来N行是a的数据 然后M行是b的数据 每行数据由学号和成绩两部分组成
按照学号升序排列的数据*/
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct _node {
//	int value_number;
//	int value_score;
//	struct _node* next;
//}Node;
//
//typedef struct _list {
//	Node* head;
//}List;
//
//void add(List* pList, int number, int score);
//void attach(List* pLista, List* pListb);
//void insertionSort(List* pLista);
//void freeList(List* pList);
//
//int main()
//{
//	List lista,listb;
//	int N, M;
//	int number, score;
//	lista.head = NULL;
//	listb.head = NULL;
//	scanf("%d%d", &N, &M);
//	for (int i = 0; i < N; i++) {
//		scanf("%d%d", &number, &score);
//		add(&lista, number, score);
//	}
//	for (int i = 0; i < M; i++) {
//		scanf("%d%d", &number, &score);
//		add(&listb, number, score);
//	}
//	attach(&lista, &listb);
//	insertionSort(&lista);
//	Node* q = lista.head;
//	while (q) {
//		printf("%d %d\n", q->value_number, q->value_score);
//		q = q->next;
//	}
//
//	//释放已分配的内存
//	freeList(&lista);
//	freeList(&listb);
//	return 0;
//}
//
//void add(List* pList, int number, int score)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->value_number = number;
//	p->value_score = score;
//	Node* last = pList->head;
//	if (last) {
//		while (last->next) {
//			last = last->next;
//		}
//		last->next = p;
//	}
//	else {
//		pList->head = p;
//	}
//}
//void attach(List* pLista, List* pListb)
//{
//	if (pLista->head) {
//		Node* p = pLista->head;
//		while (p->next) {
//			p = p->next;//将指针指向最后一个
//		}
//		p->next = pListb->head;
//	}
//	else {
//			pLista->head = pLista->head;	
//	}
//	pListb->head = NULL;
//}
//void insertionSort(List* pLista)
//{
//	Node* sorted = NULL;// 初始化已排序链表为空
//	Node* curr = pLista->head;// 初始化当前节点为原链表头节点
//	while (curr) {// 遍历原链表的每个节点
//		Node* nextNode = curr->next;// 保存当前节点的下一个节点
//		// 如果已排序链表为空或当前节点小于已排序链表的头节点
//		if (sorted == NULL || curr->value_number < sorted->value_number) {
//			curr->next = sorted; // 将当前节点插入到已排序链表的头部
//			sorted = curr;
//		}
//		else {
//			// 找到已排序链表中第一个大于或等于当前节点的位置
//			Node* temp = sorted;
//			while (temp->next && temp->next->value_number < curr->value_number) {
//				temp = temp->next;
//			}
//			curr->next = temp->next;// 将当前节点插入到合适的位置
//			temp->next = curr;
//		}
//		curr = nextNode; // 更新当前节点为下一个节点
//	}
//	pLista->head = sorted;// 更新原链表的头节点为排序后的链表头节点
//}
//void freeList(List* pList) {
//	Node* curr = pList->head;
//	while (curr) {
//		Node* temp = curr;
//		curr = curr->next;
//		free(temp);
//	}
//	pList->head = NULL;
//}