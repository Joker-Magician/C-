#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include"list.h"

int main()
{
	// ���ؿ���̨����
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);

	List list;
	list.head = NULL;

	initgraph(x_graph, y_graph, SHOWCONSOLE);
	//���ñ�����ɫΪ��ɫ
	setbkcolor(WHITE);
	cleardevice();

	displayMessage("���ڼ�����ϵ������...");
	loadFromFile(&list, "��ϵ��.txt");

	while (1) {
		drawMenu();
		handleInput(&list);
	}

	closegraph();
	saveToFile(&list, "��ϵ��.txt");
	freeList(&list);
	return 0;
}
