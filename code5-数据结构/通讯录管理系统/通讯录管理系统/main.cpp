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
	//设置背景颜色为白色
	setbkcolor(WHITE);
	cleardevice();

	displayMessage("正在加载联系人数据...");
	loadFromFile(&list, "联系人.txt");

	while (1) {
		drawMenu();
		handleInput(&list);
	}

	closegraph();
	freeList(&list);
	return 0;
}
