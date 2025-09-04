#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <vector>

std::vector<MenuItem> menuItems;

void InitializeMenuItems()
{
	int y = start_y;
	const char* labels[] = {
		"1. 添加联系人", "2. 按姓名查找联系人", "3. 插入联系人",
		"4. 删除联系人", "5. 显示所有联系人", "6. 按电话查找联系人",
		"7. 更新联系人电话", "8. 按姓名排序", "9. 按电话排序",
		"10. 按姓名模糊查找", "11. 按电话模糊查找", "12. 分页显示联系人", "0. 退出系统"
	};
	const char* icons[] = {
		"./add_contact.png", "./get_contact.png", "./insert_contact.png",
		"./delete_contact.png", "./show_contacts.png", "./search_phone.png",
		"./update_phone.png", "./sort_name.png", "./sort_phone.png",
		"./fuzzy_name.png", "./fuzzy_phone.png", "./show_paged.png", "./exit.png"
	};

	for (int i = 0; i < 13; ++i) {
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

	// 标题
	settextcolor(0x4299E1);
	settextstyle(36, 0, "微软雅黑");
	drawCenteredText(0, 20, x_graph, "通讯录管理系统");

	// 绘制所有菜单项
	for (const auto& item : menuItems) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfWeight = FW_NORMAL;//正常粗细
		settextstyle(&f);
		settextcolor(COLOR_NORMAL);

		if (item.id == hoverItem) {
			f.lfWeight = FW_BOLD;
			settextstyle(&f);
			settextcolor(COLOR_HOVER);
		}

		if (item.id == clickItem) { settextcolor(COLOR_CLICK); }

		settextstyle(20, 0, "宋体");
		outtextxy(start_x, item.rect.top + (item_height - textheight('A')) / 2, item.text);
		outimage(start_x - 25, item.rect.top + (item_height - 20) / 2, item.iconPath);
	}

	settextcolor(0x4299E1);
	settextstyle(16, 0, "宋体");
	outtextxy(20, 555, "************************************************************************************************");
	settextstyle(25, 0, "宋体");
	outtextxy(20, 575, "请使用鼠标点击菜单项进行操作。");
}

//纯图形化输入框
void GraphicalInput(char* buffer, int bufferSize, int x, int y, int width, int height)
{
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	rectangle(x, y, x + width, y + height);

	int index = 0;
	buffer[0] = '\0';

	while (true) {
		//绘制当前输入的文本
		char displayBuffer[102] = { 0 };
		strncpy(displayBuffer, buffer, 100);

		//模拟光标
		strcat(displayBuffer, "_");

		setfillcolor(WHITE);
		solidrectangle(x + 2, y + 2, x + width - 2, y + height - 2);//清空输入框内部

		settextcolor(BLACK);
		settextstyle(20, 0, "宋体");
		outtextxy(x + 5, y + (height - textheight('A')) / 2, displayBuffer);

		if (_kbhit()) {
			int key = _getch();
			if (key == '\r') break;//回车键，结束输入
			else if (key == '\b') { //退格键
				if (index > 0) {
					index--;
					buffer[index] = '\0';
				}
			}
			else if (index < bufferSize - 1) { //其他可打印字符
				buffer[index++] = key;
				buffer[index] = '\0';
			}
		}
		Sleep(50);
	}
}

//处理鼠标点击事件
void handkeMouseClick(List* pList, int clickX, int clickY)
{
	for (const auto& item : menuItems) {
		//判断点击坐标是否在某个菜单项的矩形区域内
		if (clickX >= item.rect.left && clickX <= item.rect.right &&
			clickY >= item.rect.top && clickY <= item.rect.bottom)
		{
			//绘制点击效果
			drawMenu(-1, item.id);
			Sleep(150);//短暂延时以显示点击效果

			//根据ID执行相应操作
			switch (item.id) {
			case 1: addContactUI(pList);			break;
			case 2: getContactUI(pList);			break;
			case 3: insertContactUI(pList);			break;
			case 4: deleteContactUI(pList);			break;
			case 5: showContactsUI(pList);			break;
			case 6: searchByPhoneUI(pList);			break;
			case 7: updateContactUI(pList);			break;
			case 8: cleardevice(); displayMessage("按姓名排序"); sortByName(pList);	break;
			case 9: cleardevice(); displayMessage("按电话排序"); sortByPhone(pList);	break;
			case 10: fuzzySearchByNameUI(pList);	break;
			case 11: fuzzySearchByPhoneUI(pList);	break;
			case 12: showPagedUI(pList);			break;
			case 13:
				saveToFile(pList, "联系人.txt");
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

	//开启批量绘制模式(双缓冲)，解决闪屏问题
	BeginBatchDraw();

	while (true) {
		//获取鼠标信息
		if (peekmessage(&msg, EM_MOUSE)) {
			//检查鼠标是否在某个菜单项上
			int currentHover = -1;
			for (const auto& item : menuItems) {
				if (msg.x >= item.rect.left && msg.x <= item.rect.right &&
					msg.y >= item.rect.top && msg.y <= item.rect.bottom)
				{
					currentHover = item.id;
					break;
				}
			}

			//如果悬停项改变，则重绘菜单
			if (currentHover != hoverItemId) {
				hoverItemId = currentHover;
				drawMenu(hoverItemId);

				FlushBatchDraw();
			}

			//如果鼠标左键按下事件
			if (msg.message == WM_LBUTTONDOWN) {
				handkeMouseClick(pList, msg.x, msg.y);
				//操作完成后，重置悬停并重绘菜单
				hoverItemId = -1;
				drawMenu();

				FlushBatchDraw();
			}
		}
		Sleep(1);
	}
	//关闭批量绘制模式
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

	displayMessage("正在加载联系人数据...");
	loadFromFile(&list, "联系人.txt");

	InitializeMenuItems();
	drawMenu();

	UIMainLoop(&list);

	closegraph();
	return 0;
}



//绘制每个菜单功能对应的UI界面函数
void addContactUI(List* pList)
{
	char name[50], phone[20];
	cleardevice();
	displayMessage("添加联系人");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入姓名：");
	GraphicalInput(name, sizeof(name), 200, 95, 300, 30);

	outtextxy(50, 150, "请输入电话：");
	GraphicalInput(phone, sizeof(phone), 200, 145, 300, 30);

	add(pList, name, phone);
	Sleep(1000);
}

void getContactUI(List* pList)
{
	char name[50];
	cleardevice();
	displayMessage("查找联系人");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入姓名：");
	GraphicalInput(name, sizeof(name), 200, 95, 300, 30);

	get(pList, name);
	Sleep(2000);
}

void insertContactUI(List* pList) {
	char name[50], phone[20], pos_str[10];
	int position;
	cleardevice();
	displayMessage("插入联系人");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入插入位置(数字):");
	GraphicalInput(pos_str, sizeof(pos_str), 300, 95, 100, 30);
	position = atoi(pos_str);

	outtextxy(50, 150, "请输入姓名:");
	GraphicalInput(name, sizeof(name), 200, 145, 300, 30);

	outtextxy(50, 200, "请输入电话:");
	GraphicalInput(phone, sizeof(phone), 200, 195, 300, 30);

	insert(pList, position, name, phone);
	Sleep(1000);
}

void deleteContactUI(List* pList) {
	char name[50];
	cleardevice();
	displayMessage("删除联系人");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入要删除的姓名:");
	GraphicalInput(name, sizeof(name), 280, 95, 300, 30);

	del(pList, name);
	Sleep(1000);
}

void showContactsUI(List* pList) {
	cleardevice();
	displayMessage("所有联系人 (按任意键返回)");
	show(pList); // 原有的show函数本身就是图形化输出
	
	ExMessage msg;
	while (true) {
		// 获取任意消息
		if (peekmessage(&msg, EX_KEY)) {
			// 如果是按键消息，则跳出循环
			if (msg.message == WM_KEYDOWN) {
				break;
			}
		}
		Sleep(10); // 短暂休眠，避免CPU占用过高
	}
}

void showPagedUI(List* pList) {
	cleardevice();
	displayMessage("分页显示联系人");
	showPaged(pList, 5); // 原有函数已支持键盘翻页
}

void searchByPhoneUI(List* pList) {
	char phone[20];
	cleardevice();
	displayMessage("按电话查找联系人");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入电话号码:");
	GraphicalInput(phone, sizeof(phone), 250, 95, 300, 30);

	searchByPhone(pList, phone);
	Sleep(2000);
}

void updateContactUI(List* pList) {
	char name[50], newPhone[20];
	cleardevice();
	displayMessage("更新联系人电话");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入姓名:");
	GraphicalInput(name, sizeof(name), 200, 95, 300, 30);

	outtextxy(50, 150, "请输入新的电话:");
	GraphicalInput(newPhone, sizeof(newPhone), 250, 145, 300, 30);

	update(pList, name, newPhone);
	Sleep(1000);
}

void fuzzySearchByNameUI(List* pList) {
	char part[50];
	cleardevice();
	displayMessage("模糊查找(姓名)");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入部分姓名:");
	GraphicalInput(part, sizeof(part), 250, 95, 300, 30);

	fuzzySearchByName(pList, part);
	
	ExMessage msg;
	while (true) {
		// 获取任意消息
		if (peekmessage(&msg, EX_KEY)) {
			// 如果是按键消息，则跳出循环
			if (msg.message == WM_KEYDOWN) {
				break;
			}
		}
		Sleep(10); // 短暂休眠，避免CPU占用过高
	}
}

void fuzzySearchByPhoneUI(List* pList) {
	char part[20];
	cleardevice();
	displayMessage("模糊查找(电话)");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入部分电话:");
	GraphicalInput(part, sizeof(part), 250, 95, 300, 30);

	fuzzySearchByPhone(pList, part);
	
	ExMessage msg;
	while (true) {
		// 获取任意消息
		if (peekmessage(&msg, EX_KEY)) {
			// 如果是按键消息，则跳出循环
			if (msg.message == WM_KEYDOWN) {
				break;
			}
		}
		Sleep(10); // 短暂休眠，避免CPU占用过高
	}
}
