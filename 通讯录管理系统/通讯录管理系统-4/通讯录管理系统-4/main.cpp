#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <vector>

std::vector<MenuItem> menuItems;

void InitializeMenuItems()
{
	int y = start_y;
	const char* labels[] = {
		"1. 添加联系人", "2. 查找联系人", "3. 插入联系人",
		"4. 删除联系人", "5. 显示所有联系人", "6. 更新联系人电话",
		"7. 按姓名排序", "8. 按电话排序", "9. 分页显示联系人", "0. 退出系统"
	};
	const char* icons[] = {
		"./res/add_contact.png", "./res/get_contact.png", "./res/insert_contact.png", 
		"./res/delete_contact.png", "./res/show_contacts.png", "./res/update_phone.png",
		"./res/sort_name.png", "./res/sort_phone.png", "./res/show_paged.png", "./res/exit.png"
	};

	int numItems = 10;
	menuItems.clear(); // 清空旧的菜单项

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
	outtextxy(20, 455, "************************************************************************************************");
	settextstyle(25, 0, "宋体");
	outtextxy(20, 475, "请使用鼠标点击菜单项进行操作。");
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

		FlushBatchDraw();

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
			case 1:  addContactUI(pList);				break;
			case 2:  searchContactUI(pList);				break;
			case 3:  insertContactUI(pList);			break;
			case 4:  deleteContactUI(pList);			break;
			case 5:  showContactsUI(pList);				break;
			case 6:  updateContactUI(pList);			break;
			case 7:  cleardevice(); displayMessage("按姓名排序"); sortByName(pList);	break;
			case 8:  cleardevice(); displayMessage("按电话排序"); sortByPhone(pList);	break;
			case 9: showPagedUI(pList);				break;
			case 10:
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
	FlushBatchDraw();
	GraphicalInput(name, sizeof(name), 200, 95, 300, 30);

	outtextxy(50, 150, "请输入电话：");
	FlushBatchDraw();
	GraphicalInput(phone, sizeof(phone), 200, 145, 300, 30);

	add(pList, name, phone);
	Sleep(1000);
}


void insertContactUI(List* pList) {
	char name[50], phone[20], pos_str[10];
	int position;
	cleardevice();
	displayMessage("插入联系人");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入插入位置(数字):");
	FlushBatchDraw();
	GraphicalInput(pos_str, sizeof(pos_str), 300, 95, 100, 30);
	position = atoi(pos_str);

	outtextxy(50, 150, "请输入姓名:");
	FlushBatchDraw();
	GraphicalInput(name, sizeof(name), 200, 145, 300, 30);

	outtextxy(50, 200, "请输入电话:");
	FlushBatchDraw();
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
	FlushBatchDraw();
	GraphicalInput(name, sizeof(name), 280, 95, 300, 30);

	del(pList, name);
	Sleep(1000);
}

void showContactsUI(List* pList) {
	cleardevice();
	displayMessage("所有联系人 (按任意键返回)");
	cleardevice();
	show(pList); // 原有的show函数本身就是图形化输出

	FlushBatchDraw();

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


void updateContactUI(List* pList) {
	char name[50], newPhone[20];
	cleardevice();
	displayMessage("更新联系人电话");

	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 100, "请输入姓名:");
	FlushBatchDraw();
	GraphicalInput(name, sizeof(name), 200, 95, 300, 30);

	outtextxy(50, 150, "请输入新的电话:");
	FlushBatchDraw();
	GraphicalInput(newPhone, sizeof(newPhone), 250, 145, 300, 30);

	update(pList, name, newPhone);
	Sleep(1000);
}

void searchContactUI(List* pList)
{
	std::vector<MenuItem> searchItems;
	const char* labels[] = {
	   "1. 按姓名精确查找",
	   "2. 按电话精确查找",
	   "3. 按姓名模糊查找",
	   "4. 按电话模糊查找"
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

			//点击效果
			if (msg.message == WM_LBUTTONDOWN && hoverItemId != -1) {
				drawSearchMenu(searchItems, -1, hoverItemId);
				Sleep(150);

				char inputBuffer[50] = { 0 };
				switch (hoverItemId) {
				case 1:
					cleardevice();
					displayMessage("精确查找(姓名)");
					outtextxy(50, 100, "请输入要精确查找的姓名：");
					GraphicalInput(inputBuffer, sizeof(inputBuffer), 300, 95, 300, 30);
					get(pList, inputBuffer);
					Sleep(2000);
					return;
				case 2:
					cleardevice();
					displayMessage("精确查找(电话)");
					outtextxy(50, 100, "请输入要精确查找的电话:");
					GraphicalInput(inputBuffer, sizeof(inputBuffer), 300, 95, 300, 30);
					searchByPhone(pList, inputBuffer);
					Sleep(2000);
					return;
				case 3:
					cleardevice();
					displayMessage("模糊查找(姓名)");
					outtextxy(50, 100, "请输入部分姓名进行模糊查找:");
					GraphicalInput(inputBuffer, sizeof(inputBuffer), 350, 95, 300, 30);
					fuzzySearchByName(pList, inputBuffer);

					settextcolor(RED);
					outtextxy(50, 500, "按任意键返回主菜单...");
					FlushBatchDraw();
					_getch();
					return;
				case 4:
					cleardevice();
					displayMessage("模糊查找(电话)");
					outtextxy(50, 100, "请输入部分电话进行模糊查找:");
					GraphicalInput(inputBuffer, sizeof(inputBuffer), 350, 95, 300, 30);
					fuzzySearchByPhone(pList, inputBuffer);

					settextcolor(RED);
					outtextxy(50, 500, "按任意键返回主菜单...");
					FlushBatchDraw();
					_getch();
					return;
				}
			}
		}
		if (_kbhit()) {
			if (_getch() == 27) { //27为ESC键的ASCII码
				return;
			}
		}
		Sleep(1);
	}
}


void drawSearchMenu(const std::vector<MenuItem>& items, int hoverId, int clickId)
{
	cleardevice();
	//绘制标题
	settextcolor(0x4299E1);
	settextstyle(28, 0, "微软雅黑");
	drawCenteredText(0, 50, x_graph, "查找联系人 - 请选择方式");

	//遍历并绘制所有按钮
	for (const auto& item : items) {
		LOGFONT f;
		gettextstyle(&f);
		f.lfWeight = FW_NORMAL;
		settextstyle(&f);
		settextcolor(COLOR_NORMAL);

		//如果悬停，改变颜色和样式
		if (item.id == hoverId) {
			f.lfWeight = FW_BOLD;
			settextstyle(&f);
			settextcolor(COLOR_HOVER);//蓝色
		}

		if (item.id == clickId) {
			settextcolor(COLOR_CLICK);
		}

		settextstyle(20, 0, "宋体");
		setfillcolor(WHITE);
		solidrectangle(item.rect.left, item.rect.top, item.rect.right, item.rect.bottom);
		rectangle(item.rect.left, item.rect.top, item.rect.right, item.rect.bottom);
		outtextxy(item.rect.left + 20, item.rect.top + (search_item_height - textheight('A')) / 2, item.text);
	}
	FlushBatchDraw();
}