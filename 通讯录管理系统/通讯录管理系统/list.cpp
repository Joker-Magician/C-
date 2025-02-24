#define _CRT_SECURE_NO_WARNINGS
#include"list.h"



void add(List* pList, const char* name, const char* phone)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p) {
		/*fprintf(stderr, "Memory allocation failed!\n");
		exit(1);*/
		displayMessage("�ڴ����ʧ�ܣ�");
		return;
	}
	strcpy(p->name, name);
	strcpy(p->phone, phone);
	p->next = pList->head;
	pList->head = p;//�������룬�������
	//p->next = NULL;
	//if (pList->head == NULL) {
	//	pList->head = p;
	//}
	//else {
	//	Node* curr = pList->head;
	//	while (curr->next) {
	//		curr = curr->next;
	//	}
	//	curr->next = p;
	//}//�������룬�������
	displayMessage("��ϵ����ӳɹ�.");
}
void freeList(List* pList)
{
	Node* curr = pList->head;
	while (curr) {
		Node* temp = curr;
		curr = curr->next;
		free(temp);
	}
	pList->head = NULL;
}
void get(List* pList, const char* name)
{
	Node* p;
	for (p = pList->head; p; p = p->next) {
		if (strcmp(p->name, name) == 0) {
			;
			char buffer[100];
			sprintf(buffer, "����:%s,�绰:%s\n", p->name, p->phone);
			displayMessage(buffer);
			return;
		}
	}
	//printf("get fail��Name not found\n");
	displayMessage("����ʧ�ܣ�����������");
}
void insert(List* pList, int a, const char* name, const char* phone)
{
	int cnt = 1;
	Node* p = pList->head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		displayMessage("�ڴ����ʧ��!");
		return;
	}
	strcpy(newNode->name, name);
	strcpy(newNode->phone, phone);
	newNode->next = NULL;
	if (a == 1) {
		newNode->next = pList->head;
		pList->head = newNode;
		//printf("insert OK\n");
		/*settextstyle(20, 0, "Arial");
		outtextxy(50, 50, "insert OK");*/
		displayMessage("����ɹ�");
		return;
	}
	while (p && cnt < a - 1) {
		p = p->next;
		cnt++;
	}
	if (p && cnt == a - 1) {
		newNode->next = p->next;
		p->next = newNode;
		//printf("insert OK\n");
		displayMessage("����ɹ�");
	}
	else {
		//printf("insert fail:Position not found\n");
		displayMessage("����ʧ�ܣ�λ�ò�����");
		free(newNode);
	}
}
void del(List* pList, const char* name)
{
	Node* temp;
	if (pList->head && strcmp(pList->head->name, name) == 0) {
		temp = pList->head;
		pList->head = pList->head->next;
		free(temp);
		//printf("delete OK\n");
		displayMessage("ɾ���ɹ�");
		return;
	}
	Node* p = pList->head;
	while (p && p->next && strcmp(p->next->name, name) != 0) {
		p = p->next;
	}
	if (p && p->next) {
		temp = p->next;
		p->next = p->next->next;
		free(temp);
		//printf("delete OK\n");
		displayMessage("ɾ���ɹ�");
	}
	else {
		//printf("delete fail:Name not found\n");
		displayMessage("ɾ��ʧ�ܣ�����������");
	}
}
void show(List* pList)
{
	Node* p = pList->head;
	if (p) {
		int index = 1;
		int y = 50;
		settextcolor(BLACK);
		settextstyle(20, 0, "����");
		for (p = pList->head; p; p = p->next) {
			char buffer[100];
			sprintf(buffer, "%d. ����: %s, �绰: %s", index++, p->name, p->phone);
			outtextxy(50, y, buffer);
			y += 50;
		}
	}
	else {
		//printf("Link list is empty\n");
		displayMessage("��ϵ���б�Ϊ��");
	}
}
void searchByPhone(List* pList, const char* phone)
{
	Node* p;
	for (p = pList->head; p; p = p->next) {
		if (strcmp(p->phone, phone) == 0) {
			char buffer[100];
			sprintf(buffer, "����: %s, �绰 %s\n", p->name, p->phone);
			displayMessage(buffer);
			return;
		}
	}
	//printf("searchByPhone fail\n");
	displayMessage("����ʧ��");
}
void update(List* pList, const char* name, const char* newPhone)
{
	Node* p;
	for (p = pList->head; p; p = p->next) {
		if (strcmp(p->name, name) == 0) {
			strcpy(p->phone, newPhone);
			//printf("update OK\n");
			displayMessage("���³ɹ�");
			return;
		}
	}
	//printf("update fail\n");
	displayMessage("����ʧ��");
}

void sortByName(List* pList)//��������
{
	if (!pList->head) return;
	Node* sorted = NULL;
	Node* current = pList->head;
	while (current) {
		Node* next = current->next;
		if (!sorted || strcmp(current->name, sorted->name) < 0) {
			current->next = sorted;
			sorted = current;
		}
		else {
			Node* temp = sorted;
			while (temp->next && strcmp(current->name, temp->next->name) >= 0) {
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}
		current = next;
	}
	pList->head = sorted;
	//printf("soreByName OK\n");
	displayMessage("����������ɹ�");
}
void sortByPhone(List* pList)//��������
{
	if (!pList->head) return;
	Node* sorted = NULL;
	Node* current = pList->head;
	while (current) {
		Node* next = current->next;
		if (!sorted || strcmp(current->phone, sorted->phone) < 0) {
			current->next = sorted;
			sorted = current;
		}
		else {
			Node* temp = sorted;
			while (temp->next && strcmp(current->phone, temp->next->phone) >= 0) {
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}
		current = next;
	}
	pList->head = sorted;
	//printf("sortByPhone OK\n");
	displayMessage("���绰����ɹ�");
}