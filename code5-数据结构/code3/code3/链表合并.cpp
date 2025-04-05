#define _CRT_SECURE_NO_WARNINGS
/*����a��b��������ÿ�������еĽ�����ѧ�š��ɼ���Ҫ�����������ϲ�����ѧ���������С�
��һ�У�a��b��������Ԫ�ص�����N��M, �ÿո������ ������N����a������ Ȼ��M����b������ ÿ��������ѧ�źͳɼ����������
����ѧ���������е�����*/
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
//	//�ͷ��ѷ�����ڴ�
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
//			p = p->next;//��ָ��ָ�����һ��
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
//	Node* sorted = NULL;// ��ʼ������������Ϊ��
//	Node* curr = pLista->head;// ��ʼ����ǰ�ڵ�Ϊԭ����ͷ�ڵ�
//	while (curr) {// ����ԭ�����ÿ���ڵ�
//		Node* nextNode = curr->next;// ���浱ǰ�ڵ����һ���ڵ�
//		// �������������Ϊ�ջ�ǰ�ڵ�С�������������ͷ�ڵ�
//		if (sorted == NULL || curr->value_number < sorted->value_number) {
//			curr->next = sorted; // ����ǰ�ڵ���뵽�����������ͷ��
//			sorted = curr;
//		}
//		else {
//			// �ҵ������������е�һ�����ڻ���ڵ�ǰ�ڵ��λ��
//			Node* temp = sorted;
//			while (temp->next && temp->next->value_number < curr->value_number) {
//				temp = temp->next;
//			}
//			curr->next = temp->next;// ����ǰ�ڵ���뵽���ʵ�λ��
//			temp->next = curr;
//		}
//		curr = nextNode; // ���µ�ǰ�ڵ�Ϊ��һ���ڵ�
//	}
//	pLista->head = sorted;// ����ԭ�����ͷ�ڵ�Ϊ����������ͷ�ڵ�
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