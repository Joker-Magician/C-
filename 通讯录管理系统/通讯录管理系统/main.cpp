#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include"list.h"

int main()
{
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
	freeList(&list);
	return 0;
}
