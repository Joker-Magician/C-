#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <vector>

std::vector<MenuItem> menuItems;

void InitializeMenuItems()
{
	int y = start_y;
	const char* labels[] = {
		"1. �����ϵ��", "2. ������ϵ��", "3. ������ϵ��",
		"4. ɾ����ϵ��", "5. ��ʾ������ϵ��", "6. ������ϵ�˵绰",
		"7. ����������", "8. ���绰����", "9. ��ҳ��ʾ��ϵ��", "0. �˳�ϵͳ"
	};
	const char* icons[] = {
		"./res/add_contact.png", "./res/get_contact.png", "./res/insert_contact.png", 
		"./res/delete_contact.png", "./res/show_contacts.png", "./res/update_phone.png",
		"./res/sort_name.png", "./res/sort_phone.png", "./res/show_paged.png", "./res/exit.png"
	};

	int numItems = 10;
	menuItems.clear(); // ��վɵĲ˵���

	for (int i = 0; i < 10; ++i) {
		MenuItem item;
		item.id = i + 1;
		item.text = labels[i];
		item.iconPath = icons[i];
		item.rect = { start_x - 30, y, start_x + 300, y + item_height };
		menuItems.push_back(item);
		y += item_height + spacing;
	}
}

void drawMenu(int hoverItem = -1, int clickItem = -1)
{
	cleardevice();

	// ����
	settextcolor(0x4299E1);
	settextstyle(36, 0, "΢���ź�");
	drawCenteredText(0, 20, x_graph, "ͨѶ¼����ϵͳ");

	// �������в˵���
	for (const auto& item : menuItems) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfWeight = FW_NORMAL;//������ϸ
		settextstyle(&f);
		settextcolor(COLOR_NORMAL);

		if (item.id == hoverItem) {
			f.lfWeight = FW_BOLD;
			settextstyle(&f);
			settextcolor(COLOR_HOVER);
		}

		if (item.id == clickItem) { settextcolor(COLOR_CLICK); }

		settextstyle(20, 0, "����");
		outtextxy(start_x, item.rect.top + (item_height - textheight('A')) / 2, item.text);
		outimage(start_x - 25, item.rect.top + (item_height - 20) / 2, item.iconPath);
	}

	settextcolor(0x4299E1);
	settextstyle(16, 0, "����");
	outtextxy(20, 455, "************************************************************************************************");
	settextstyle(25, 0, "����");
	outtextxy(20, 475, "��ʹ��������˵�����в�����");
}

//��ͼ�λ������
void GraphicalInput(char* buffer, int bufferSize, int x, int y, int width, int height)
{
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	rectangle(x, y, x + width, y + height);

	int index = 0;
	buffer[0] = '\0';

	while (true) {
		//���Ƶ�ǰ������ı�
		char displayBuffer[102] = { 0 };
		strncpy(displayBuffer, buffer, 100);

		//ģ����
		strcat(displayBuffer, "_");

		setfillcolor(WHITE);
		solidrectangle(x + 2, y + 2, x + width - 2, y + height - 2);//���������ڲ�

		settextcolor(BLACK);
		settextstyle(20, 0, "����");
		outtextxy(x + 5, y + (height - textheight('A')) / 2, displayBuffer);

		FlushBatchDraw();

		if (_kbhit()) {
			int key = _getch();
			if (key == '\r') break;//�س�������������
			else if (key == '\b') { //�˸��
				if (index > 0) {
					index--;
					buffer[index] = '\0';
				}
			}
			else if (index < bufferSize - 1) { //�����ɴ�ӡ�ַ�
				buffer[index++] = key;
				buffer[index] = '\0';
			}
		}
		Sleep(50);
	}
}

//����������¼�
void handkeMouseClick(List* pList, int clickX, int clickY)
{
	for (const auto& item : menuItems) {
		//�жϵ�������Ƿ���ĳ���˵���ľ���������
		if (clickX >= item.rect.left && clickX <= item.rect.right &&
			clickY >= item.rect.top && clickY <= item.rect.bottom)
		{
			//���Ƶ��Ч��
			drawMenu(-1, item.id);
			Sleep(150);//������ʱ����ʾ���Ч��

			//����IDִ����Ӧ����
			switch (item.id) {
			case 1:  addContactUI(pList);				break;
			case 2:  searchContactUI(pList);				break;
			case 3:  insertContactUI(pList);			break;
			case 4:  deleteContactUI(pList);			break;
			case 5:  showContactsUI(pList);				break;
			case 6:  updateContactUI(pList);			break;
			case 7:  cleardevice(); displayMessage("����������"); sortByName(pList);	break;
			case 8:  cleardevice(); displayMessage("���绰����"); sortByPhone(pList);	break;
			case 9: showPagedUI(pList);				break;
			case 10:
				saveToFile(pList, "��ϵ��.txt");
				freeList(pList);
				closegraph();
				exit(0);
				break;
			}
			return;
		}
	}
}

void UIMainLoop(List* pList)
{
	ExMessage msg;
	int hoverItemId = -1;

	//������������ģʽ(˫����)�������������
	BeginBatchDraw();

	while (true) {
		//��ȡ�����Ϣ
		if (peekmessage(&msg, EM_MOUSE)) {
			//�������Ƿ���ĳ���˵�����
			int currentHover = -1;
			for (const auto& item : menuItems) {
				if (msg.x >= item.rect.left && msg.x <= item.rect.right &&
					msg.y >= item.rect.top && msg.y <= item.rect.bottom)
				{
					currentHover = item.id;
					break;
				}
			}

			//�����ͣ��ı䣬���ػ�˵�
			if (currentHover != hoverItemId) {
				hoverItemId = currentHover;
				drawMenu(hoverItemId);

				FlushBatchDraw();
			}

			//��������������¼�
			if (msg.message == WM_LBUTTONDOWN) {
				handkeMouseClick(pList, msg.x, msg.y);
				//������ɺ�������ͣ���ػ�˵�
				hoverItemId = -1;
				drawMenu();

				FlushBatchDraw();
			}
		}
		Sleep(1);
	}
	//�ر���������ģʽ
	EndBatchDraw();
}


int main()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);

	List list;
	list.head = NULL;

	initgraph(x_graph, y_graph);
	setbkcolor(WHITE);

	displayMessage("���ڼ�����ϵ������...");
	loadFromFile(&list, "��ϵ��.txt");

	InitializeMenuItems();
	drawMenu();

	UIMainLoop(&list);

	closegraph();
	return 0;
}



//����ÿ���˵����ܶ�Ӧ��UI���溯��
void addContactUI(List* pList)
{
	char name[50], phone[20];
	cleardevice();
	displayMessage("�����ϵ��");

	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	outtextxy(50, 100, "������������");
	FlushBatchDraw();
	GraphicalInput(name, sizeof(name), 200, 95, 300, 30);

	outtextxy(50, 150, "������绰��");
	FlushBatchDraw();
	GraphicalInput(phone, sizeof(phone), 200, 145, 300, 30);

	add(pList, name, phone);
	Sleep(1000);
}


void insertContactUI(List* pList) {
	char name[50], phone[20], pos_str[10];
	int position;
	cleardevice();
	displayMessage("������ϵ��");

	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	outtextxy(50, 100, "���������λ��(����):");
	FlushBatchDraw();
	GraphicalInput(pos_str, sizeof(pos_str), 300, 95, 100, 30);
	position = atoi(pos_str);

	outtextxy(50, 150, "����������:");
	FlushBatchDraw();
	GraphicalInput(name, sizeof(name), 200, 145, 300, 30);

	outtextxy(50, 200, "������绰:");
	FlushBatchDraw();
	GraphicalInput(phone, sizeof(phone), 200, 195, 300, 30);

	insert(pList, position, name, phone);
	Sleep(1000);
}

void deleteContactUI(List* pList) {
	char name[50];
	cleardevice();
	displayMessage("ɾ����ϵ��");

	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	outtextxy(50, 100, "������Ҫɾ��������:");
	FlushBatchDraw();
	GraphicalInput(name, sizeof(name), 280, 95, 300, 30);

	del(pList, name);
	Sleep(1000);
}

void showContactsUI(List* pList) {
	cleardevice();
	displayMessage("������ϵ�� (�����������)");
	cleardevice();
	show(pList); // ԭ�е�show�����������ͼ�λ����

	FlushBatchDraw();

	ExMessage msg;
	while (true) {
		// ��ȡ������Ϣ
		if (peekmessage(&msg, EX_KEY)) {
			// ����ǰ�����Ϣ��������ѭ��
			if (msg.message == WM_KEYDOWN) {
				break;
			}
		}
		Sleep(10); // �������ߣ�����CPUռ�ù���
	}
}

void showPagedUI(List* pList) {
	cleardevice();
	displayMessage("��ҳ��ʾ��ϵ��");
	showPaged(pList, 5); // ԭ�к�����֧�ּ��̷�ҳ
}


void updateContactUI(List* pList) {
	char name[50], newPhone[20];
	cleardevice();
	displayMessage("������ϵ�˵绰");

	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	outtextxy(50, 100, "����������:");
	FlushBatchDraw();
	GraphicalInput(name, sizeof(name), 200, 95, 300, 30);

	outtextxy(50, 150, "�������µĵ绰:");
	FlushBatchDraw();
	GraphicalInput(newPhone, sizeof(newPhone), 250, 145, 300, 30);

	update(pList, name, newPhone);
	Sleep(1000);
}

void searchContactUI(List* pList)
{
	std::vector<MenuItem> searchItems;
	const char* labels[] = {
	   "1. ��������ȷ����",
	   "2. ���绰��ȷ����",
	   "3. ������ģ������",
	   "4. ���绰ģ������"
	};

	int y = search_start_y;
	for (int i = 0; i < 4; ++i) {
		MenuItem item;
		item.id = i + 1;
		item.text = labels[i];
		item.rect = { search_start_x, y, search_start_x + search_item_width, y + search_item_height };
		searchItems.push_back(item);
		y += search_item_height + search_spacing;
	}

	drawSearchMenu(searchItems);

	ExMessage msg;
	int hoverItemId = -1;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {
			int currentHover = -1;
			for (const auto& item : searchItems) {
				if (msg.x >= item.rect.left && msg.x <= item.rect.right &&
					msg.y >= item.rect.top && msg.y <= item.rect.bottom) {
					currentHover = item.id;
					break; 
				}
			}

			if (currentHover != hoverItemId) {
				hoverItemId = currentHover;
				drawSearchMenu(searchItems, hoverItemId);
			}

			//���Ч��
			if (msg.message == WM_LBUTTONDOWN && hoverItemId != -1) {
				drawSearchMenu(searchItems, -1, hoverItemId);
				Sleep(150);

				char inputBuffer[50] = { 0 };
				switch (hoverItemId) {
				case 1:
					cleardevice();
					displayMessage("��ȷ����(����)");
					outtextxy(50, 100, "������Ҫ��ȷ���ҵ�������");
					GraphicalInput(inputBuffer, sizeof(inputBuffer), 300, 95, 300, 30);
					get(pList, inputBuffer);
					Sleep(2000);
					return;
				case 2:
					cleardevice();
					displayMessage("��ȷ����(�绰)");
					outtextxy(50, 100, "������Ҫ��ȷ���ҵĵ绰:");
					GraphicalInput(inputBuffer, sizeof(inputBuffer), 300, 95, 300, 30);
					searchByPhone(pList, inputBuffer);
					Sleep(2000);
					return;
				case 3:
					cleardevice();
					displayMessage("ģ������(����)");
					outtextxy(50, 100, "�����벿����������ģ������:");
					GraphicalInput(inputBuffer, sizeof(inputBuffer), 350, 95, 300, 30);
					fuzzySearchByName(pList, inputBuffer);

					settextcolor(RED);
					outtextxy(50, 500, "��������������˵�...");
					FlushBatchDraw();
					_getch();
					return;
				case 4:
					cleardevice();
					displayMessage("ģ������(�绰)");
					outtextxy(50, 100, "�����벿�ֵ绰����ģ������:");
					GraphicalInput(inputBuffer, sizeof(inputBuffer), 350, 95, 300, 30);
					fuzzySearchByPhone(pList, inputBuffer);

					settextcolor(RED);
					outtextxy(50, 500, "��������������˵�...");
					FlushBatchDraw();
					_getch();
					return;
				}
			}
		}
		if (_kbhit()) {
			if (_getch() == 27) { //27ΪESC����ASCII��
				return;
			}
		}
		Sleep(1);
	}
}


void drawSearchMenu(const std::vector<MenuItem>& items, int hoverId, int clickId)
{
	cleardevice();
	//���Ʊ���
	settextcolor(0x4299E1);
	settextstyle(28, 0, "΢���ź�");
	drawCenteredText(0, 50, x_graph, "������ϵ�� - ��ѡ��ʽ");

	//�������������а�ť
	for (const auto& item : items) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfWeight = FW_NORMAL;
		settextstyle(&f);
		settextcolor(COLOR_NORMAL);

		//�����ͣ���ı���ɫ����ʽ
		if (item.id == hoverId) {
			f.lfWeight = FW_BOLD;
			settextstyle(&f);
			settextcolor(COLOR_HOVER);//��ɫ
		}

		if (item.id == clickId) {
			settextcolor(COLOR_CLICK);
		}

		settextstyle(20, 0, "����");
		setfillcolor(WHITE);
		solidrectangle(item.rect.left, item.rect.top, item.rect.right, item.rect.bottom);
		rectangle(item.rect.left, item.rect.top, item.rect.right, item.rect.bottom);
		outtextxy(item.rect.left + 20, item.rect.top + (search_item_height - textheight('A')) / 2, item.text);
	}
	FlushBatchDraw();
}