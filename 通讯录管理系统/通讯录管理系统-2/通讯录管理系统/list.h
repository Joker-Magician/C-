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

#define x_graph 905
#define y_graph 678.75
#define start_x 295
#define start_y 75
#define item_height 30
#define spacing 5

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

void drawMenu();
void handleInput(List* pList);
void safeFgets(char* str, int size);
void displayMessage(const char* message);
void drawCenteredText(int x, int y, int width, const char* text);
void outimage(const int x, const int y, const char* postion);

void saveToFile(List* pList, const char* filename);
void loadFromFile(List* pList, const char* filename);
void showPaged(List* pList, int pageSize);

#endif