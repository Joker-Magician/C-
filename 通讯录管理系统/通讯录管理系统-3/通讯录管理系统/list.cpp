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

/*�����ϣ��*/
	pList->nameMap[std::string(name)] = p;
	pList->phoneMap[std::string(phone)] = p;

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
	pList->nameMap.clear();
	pList->phoneMap.clear();
}

void get(List* pList, const char* name)
{
	auto it = pList->nameMap.find(std::string(name));
	if (it != pList->nameMap.end()) {
		Node* p = it->second;
		char buffer[100];
		sprintf(buffer, "������%s,�绰��%s\n", p->name, p->phone);
		displayMessage(buffer);
		return;
	}
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
		pList->nameMap[std::string(name)] = newNode;
		pList->phoneMap[std::string(phone)] = newNode;
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
		pList->nameMap[std::string(name)] = newNode;
		pList->phoneMap[std::string(phone)] = newNode;
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
		pList->nameMap.erase(std::string(temp->name));
		pList->phoneMap.erase(std::string(temp->phone));
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
		pList->nameMap.erase(std::string(temp->name));
		pList->phoneMap.erase(std::string(temp->phone));
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
	auto it = pList->phoneMap.find(std::string(phone));
	if (it != pList->phoneMap.end()) {
		Node* p = it->second;
		char buffer[100];
		sprintf(buffer, "������%s,�绰��%s\n", p->name, p->phone);
		displayMessage(buffer);
		return;
	}
	displayMessage("����ʧ�ܣ��绰������");
}

void update(List* pList, const char* name, const char* newPhone)
{
	auto it = pList->nameMap.find(std::string(name));
	if (it != pList->nameMap.end()) {
		Node* p = it->second;
		pList->phoneMap.erase(std::string(p->phone));
		strcpy(p->phone, newPhone);
		pList->phoneMap[std::string(newPhone)] = p;
		displayMessage("���³ɹ�");
		return;
	}
	displayMessage("����ʧ�ܣ�����������");
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

//������ģ������
void fuzzySearchByName(List* pList, const char* part)
{
	Node* p = pList->head;
	int found = 0, y = 50, index = 1;
	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	for (; p; p = p->next) {
		if (strstr(p->name, part)) {
			cleardevice();
			char buffer[100];
			sprintf(buffer, "%d. ������%s���绰��%s", index++, p->name, p->phone);
			outtextxy(50, y, buffer);
			y += 50;
			found = 1;
		}
	}
	if (!found) {
		displayMessage("δ�ҵ������ϵ��");
	}
}

//���绰ģ������
void fuzzySearchByPhone(List* pList, const char* part)
{
	Node* p = pList->head;
	int found = 0, y = 50, index = 1;
	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	for (; p; p = p->next) {
		if (strstr(p->phone, part)) {
			cleardevice();
			char buffer[100];
			sprintf(buffer, "%d. ������%s���绰��%s", index++, p->name, p->phone);
			outtextxy(50, y, buffer);
			y += 50;
			found = 1;
		}
	}
	if (!found) {
		displayMessage("δ�ҵ������ϵ��");
	}
}

void showPaged(List* pList, int pageSize)
{
	Node* p = pList->head;
	int total = 0;
	for (Node* temp = p; temp; temp = temp->next) total++;//ͳ������
	if (total == 0) {
		displayMessage("��ϵ���б�Ϊ��");
		return;
	}

	int page = 0;
	int totalPages = (total + pageSize - 1) / pageSize;
	while (true) {
		cleardevice();
		settextcolor(BLACK);
		settextstyle(20, 0, "����");
		int y = 50, index = 1 + page * pageSize;
		Node* curr = p;
		// ������ǰҳ��ʼ
		for (int i = 0; i < page * pageSize && curr; ++i) curr = curr->next;
		//��ʾ��ǰҳ
		for (int i = 0; i < pageSize && curr; ++i, curr = curr->next, ++index) {
			char buffer[100];
			sprintf(buffer, "%d. ������%s���绰��%s", index, curr->name, curr->phone);
			outtextxy(50, y, buffer);
			y += 50;
		}
		//ҳ����ʾ
		settextcolor(0x4299E1);
		settextstyle(16, 0, "����");
		char footer[100];
		sprintf(footer, "�� %d/%d ҳ��n:��һҳ p:��һҳ q:�˳�", page + 1, totalPages);
		outtextxy(50, 400, footer);

		//�ȴ��û�����
		char ch = _getch();
		if (ch == 'n' || ch == 'N') 
		{ if (page < totalPages - 1) page++; }
		else if (ch == 'p' || ch == 'P')
		{ if (page > 0) page--; }
		else if (ch == 'q' || ch == 'Q') {
			break;
		}
	}
}