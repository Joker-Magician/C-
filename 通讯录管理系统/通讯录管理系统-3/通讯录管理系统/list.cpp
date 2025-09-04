#define _CRT_SECURE_NO_WARNINGS
#include"list.h"



void add(List* pList, const char* name, const char* phone)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p) {
		/*fprintf(stderr, "Memory allocation failed!\n");
		exit(1);*/
		displayMessage("内存分配失败！");
		return;
	}
	strcpy(p->name, name);
	strcpy(p->phone, phone);
	p->next = pList->head;
	pList->head = p;//正序输入，逆序输出
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
	//}//正序输入，正序输出

/*插入哈希表*/
	pList->nameMap[std::string(name)] = p;
	pList->phoneMap[std::string(phone)] = p;

	displayMessage("联系人添加成功.");
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
		sprintf(buffer, "姓名：%s,电话：%s\n", p->name, p->phone);
		displayMessage(buffer);
		return;
	}
	displayMessage("查找失败：姓名不存在");
}

void insert(List* pList, int a, const char* name, const char* phone)
{
	int cnt = 1;
	Node* p = pList->head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		displayMessage("内存分配失败!");
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
		displayMessage("插入成功");
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
		displayMessage("插入成功");
	}
	else {
		//printf("insert fail:Position not found\n");
		displayMessage("插入失败：位置不存在");
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
		displayMessage("删除成功");
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
		displayMessage("删除成功");
	}
	else {
		//printf("delete fail:Name not found\n");
		displayMessage("删除失败：姓名不存在");
	}
}
void show(List* pList)
{
	Node* p = pList->head;
	if (p) {
		int index = 1;
		int y = 50;
		settextcolor(BLACK);
		settextstyle(20, 0, "宋体");
		for (p = pList->head; p; p = p->next) {
			char buffer[100];
			sprintf(buffer, "%d. 姓名: %s, 电话: %s", index++, p->name, p->phone);
			outtextxy(50, y, buffer);
			y += 50;
		}
	}
	else {
		//printf("Link list is empty\n");
		displayMessage("联系人列表为空");
	}
}

void searchByPhone(List* pList, const char* phone)
{
	auto it = pList->phoneMap.find(std::string(phone));
	if (it != pList->phoneMap.end()) {
		Node* p = it->second;
		char buffer[100];
		sprintf(buffer, "姓名：%s,电话：%s\n", p->name, p->phone);
		displayMessage(buffer);
		return;
	}
	displayMessage("查找失败：电话不存在");
}

void update(List* pList, const char* name, const char* newPhone)
{
	auto it = pList->nameMap.find(std::string(name));
	if (it != pList->nameMap.end()) {
		Node* p = it->second;
		pList->phoneMap.erase(std::string(p->phone));
		strcpy(p->phone, newPhone);
		pList->phoneMap[std::string(newPhone)] = p;
		displayMessage("更新成功");
		return;
	}
	displayMessage("更新失败：姓名不存在");
}

void sortByName(List* pList)//插入排序
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
	displayMessage("按姓名排序成功");
}

void sortByPhone(List* pList)//插入排序
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
	displayMessage("按电话排序成功");
}

//按姓名模糊查找
void fuzzySearchByName(List* pList, const char* part)
{
	Node* p = pList->head;
	int found = 0, y = 50, index = 1;
	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	for (; p; p = p->next) {
		if (strstr(p->name, part)) {
			cleardevice();
			char buffer[100];
			sprintf(buffer, "%d. 姓名：%s，电话：%s", index++, p->name, p->phone);
			outtextxy(50, y, buffer);
			y += 50;
			found = 1;
		}
	}
	if (!found) {
		displayMessage("未找到相关联系人");
	}
}

//按电话模糊查找
void fuzzySearchByPhone(List* pList, const char* part)
{
	Node* p = pList->head;
	int found = 0, y = 50, index = 1;
	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	for (; p; p = p->next) {
		if (strstr(p->phone, part)) {
			cleardevice();
			char buffer[100];
			sprintf(buffer, "%d. 姓名：%s，电话：%s", index++, p->name, p->phone);
			outtextxy(50, y, buffer);
			y += 50;
			found = 1;
		}
	}
	if (!found) {
		displayMessage("未找到相关联系人");
	}
}

void showPaged(List* pList, int pageSize)
{
	Node* p = pList->head;
	int total = 0;
	for (Node* temp = p; temp; temp = temp->next) total++;//统计总数
	if (total == 0) {
		displayMessage("联系人列表为空");
		return;
	}

	int page = 0;
	int totalPages = (total + pageSize - 1) / pageSize;
	while (true) {
		cleardevice();
		settextcolor(BLACK);
		settextstyle(20, 0, "宋体");
		int y = 50, index = 1 + page * pageSize;
		Node* curr = p;
		// 跳到当前页起始
		for (int i = 0; i < page * pageSize && curr; ++i) curr = curr->next;
		//显示当前页
		for (int i = 0; i < pageSize && curr; ++i, curr = curr->next, ++index) {
			char buffer[100];
			sprintf(buffer, "%d. 姓名：%s，电话：%s", index, curr->name, curr->phone);
			outtextxy(50, y, buffer);
			y += 50;
		}
		//页脚显示
		settextcolor(0x4299E1);
		settextstyle(16, 0, "宋体");
		char footer[100];
		sprintf(footer, "第 %d/%d 页，n:下一页 p:上一页 q:退出", page + 1, totalPages);
		outtextxy(50, 400, footer);

		//等待用户输入
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