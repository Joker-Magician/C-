#define _CRT_SECURE_NO_WARNINGS
#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<unordered_map>
#include<string>
#include<cstring>
#include<vector>

#define x_graph 800
#define y_graph 600
#define start_x 295
#define start_y 75
#define item_height 30
#define spacing 5

#define COLOR_NORMAL BLACK
#define COLOR_HOVER BLUE
#define COLOR_CLICK RED

typedef struct _node {
	char name[50];
	char phone[20];
	struct _node* next;
}Node;

typedef struct _list {
	Node* head;
	std::unordered_map<std::string, Node*> nameMap;
	std::unordered_map<std::string, Node*> phoneMap;
}List;

//定义菜单项结构体
struct MenuItem {
	RECT rect;// 菜单项的可点击区域
	const char* text;// 菜单文本
	const char* iconPath;// 图标路径
	int id;// 唯一标识符
};

void add(List* pList, const char* name, const char* phone);
void freeList(List* pList);
void get(List* pList, const char* name);
void insert(List* pList, int a, const char* name, const char* phone);
void del(List* pList, const char* name);
void show(List* pList);
void searchByPhone(List* pList, const char* phone);
void update(List* pList, const char* name, const char* newPhone);
void sortByName(List* pList);
void sortByPhone(List* pList);

void fuzzySearchByName(List* pList, const char* part);
void fuzzySearchByPhone(List* pList, const char* party);
void showPaged(List* pList, int pageSize);

void saveToFile(List* pList, const char* filename);
void loadFromFile(List* pList, const char* filename);

//void drawMenu();
//void handleInput(List* pList);

void safeFgets(char* str, int size);
void displayMessage(const char* message);
void drawCenteredText(int x, int y, int width, const char* text);
void outimage(const int x, const int y, const char* postion);

// 核心UI函数
void UIMainLoop(List* pList);
void InitializeMenuItems();
void drawMenu(int hoverItem, int clickItem);
void handkeMouseClick(List* pList, int x, int y);
void GraphicalInput(char* buffer, int bufferSize, int x, int y, int width, int height);

// 各功能界面的入口函数
void addContactUI(List* pList);
void getContactUI(List* pList);
void insertContactUI(List* pList);
void deleteContactUI(List* pList);
void showContactsUI(List* pList);
void searchByPhoneUI(List* pList);
void updateContactUI(List* pList);
void fuzzySearchByNameUI(List* pList);
void fuzzySearchByPhoneUI(List* pList);
void showPagedUI(List* pList);


// 辅助绘图函数
void safeFgets(char* str, int size); // 这个函数现在不再需要，但保留以兼容旧代码
void displayMessage(const char* message); // 增加了默认延时参数
void drawCenteredText(int x, int y, int width, const char* text);
void outimage(const int x, const int y, const char* postion);

#endif