#define _CRT_SECURE_NO_WARNINGS
#include"list.h"

void drawMenu()
{
	cleardevice();

	//标题
	settextcolor(0x4299E1);
	settextstyle(36, 0, "微软雅黑");
	drawCenteredText(0, 20, x_graph, "通讯录管理系统");

	//菜单
	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	int y = start_y;
	outtextxy(start_x, y, "1. 添加联系人");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./add_contact.png");
	outtextxy(start_x, y, "2. 按姓名查找联系人");	y += item_height + spacing;  outimage(start_x - 25, y - 35, "./get_contact.png");
	outtextxy(start_x, y, "3. 插入联系人");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./insert_contact.png");
	outtextxy(start_x, y, "4. 删除联系人");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./delete_contact.png");
	outtextxy(start_x, y, "5  显示所有联系人");		y += item_height + spacing;  outimage(start_x - 25, y - 35, "./show_contacts.png");
	outtextxy(start_x, y, "6. 按电话查找联系人");	y += item_height + spacing;  outimage(start_x - 25, y - 35, "./search_phone.png");
	outtextxy(start_x, y, "7. 更新联系人电话");		y += item_height + spacing;  outimage(start_x - 25, y - 35, "./update_phone.png");
	outtextxy(start_x, y, "8. 按姓名排序");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./sort_name.png");
	outtextxy(start_x, y, "9. 按电话排序");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./sort_phone.png");
	outtextxy(start_x, y, "0. 退出系统");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./exit.png");

	//提示信息
	settextcolor(0x4299E1);
	settextstyle(16, 0, "宋体");
	outtextxy(20, 450, "************************************************************************************************");
	settextstyle(25, 0, "宋体");
	outtextxy(20, 470, "请在控制台输入操作编号:");
}//将字符集改为多字节字符集使用 

void drawCenteredText(int x, int y, int width, const char* text)
{
	int textWidth = textwidth(text);
	outtextxy(x + (width - textWidth) / 2, y, text);
}

void outimage(const int x, const int y, const char* postion)
{
	IMAGE img;
	loadimage(&img, postion, 20, 20);
	putimage(x, y, &img);
}

void handleInput(List* pList)
{
	char choice = _getch();//读取一个字符且不将其显示在屏幕上
	char name[50], phone[20], newPhone[20];
	int position;

	fflush(stdin);
	//getchar();// 清除缓冲区中的换行符
	switch (choice) {
	case '1':
		cleardevice();
		displayMessage("添加联系人");
		outtextxy(50, 100, "请输入姓名:");
		Sleep(1000);
		safeFgets(name, sizeof(name));// 去除换行符
		outtextxy(50, 150, "请输入电话:");
		Sleep(1000);
		safeFgets(phone, sizeof(phone));
		add(pList, name, phone);
		break;
	case '2':
		cleardevice();
		displayMessage("查找联系人");
		outtextxy(50, 100, "请输入姓名: ");
		Sleep(1000);
		safeFgets(name, sizeof(name));
		get(pList, name);
		break;
	case '3':
		cleardevice();
		displayMessage("插入联系人");
		outtextxy(50, 100, "请输入插入位置：");
		Sleep(1000);
		scanf("%d", &position);
		//getchar();
		//fflush(stdin);
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		outtextxy(50, 150, "请输入姓名: ");
		Sleep(1000);
		safeFgets(name, sizeof(name));
		outtextxy(50, 200, "请输入电话: ");
		Sleep(1000);
		safeFgets(phone, sizeof(phone));
		insert(pList, position, name, phone);
		break;
	case '4':
		cleardevice();
		displayMessage("删除联系人");
		outtextxy(50, 100, "请输入姓名：");
		Sleep(1000);
		safeFgets(name, sizeof(name));
		del(pList, name);
		break;
	case '5':
		cleardevice();
		displayMessage("所有联系人");
		show(pList);
		Sleep(5000);
		break;
	case '6':
		cleardevice();
		displayMessage("按电话查找联系人");
		outtextxy(50, 100, "请输入电话：");
		Sleep(1000);
		safeFgets(phone, sizeof(phone));
		searchByPhone(pList, phone);
		break;
	case '7':
		cleardevice();
		displayMessage("更新联系人电话");
		outtextxy(50, 100, "请输入姓名：");
		Sleep(1000);
		safeFgets(name, sizeof(name));
		outtextxy(50, 150, "请输入新的电话：");
		Sleep(1000);
		safeFgets(newPhone, sizeof(newPhone));
		update(pList, name, newPhone);
		break;
	case '8':
		cleardevice();
		displayMessage("按姓名排序");
		sortByName(pList);
		break;
	case '9':
		cleardevice();
		displayMessage("按电话排序");
		sortByPhone(pList);
		break;
	case '0':
		saveToFile(pList, "联系人.txt");
		freeList(pList);
		closegraph();
		exit(0);
	default:
		outtextxy(50, 550, "无效选择，请重试.\n");
		Sleep(1000);
	}
}

void safeFgets(char* str, int size)
{
	if (fgets(str, size, stdin)) {
		str[strcspn(str, "\n")] = 0;
	}
}

void displayMessage(const char* message)
{
	cleardevice();
	settextcolor(0x4299E1);
	settextstyle(20, 0, "宋体");
	outtextxy(50, 50, message);
	Sleep(1000);
}