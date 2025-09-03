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
		"a. 按姓名模糊查找", "b. 按电话模糊查找", "c. 分页显示联系人", "0. 退出系统"
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
			case 1: addContactUI(pList); break;
			case 2: getContactUI(pList); break;
			case 3: insertContactUI(pList); break;
			case 4: deleteContactUI(pList); break;
			case 5: showContactsUI(pList); break;
			case 6: searchByPhoneUI(pList); break;
			case 7: updateContactUI(pList); break;
			case 8: cleardevice(); displayMessage("按姓名排序"); sortByName(pList);
			case 9: cleardevice(); displayMessage("按电话排序"); sortByPhone(pList);
			case 10: fuzzySearchByNameUI(pList); break;
			case 11: fuzzySearchByPhoneUI(pList); break;
			case 12: showPagedUI(pList); break;
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