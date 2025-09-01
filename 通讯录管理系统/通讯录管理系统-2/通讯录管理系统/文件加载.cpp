#define _CRT_SECURE_NO_WARNINGS
#include"list.h"

void saveToFile(List* pList, const char* filename)
{
	FILE* file = fopen(filename, "w");
	if (!file) {
		displayMessage("数据保存失败！");
		return;
	}
	Node* p;
	for (p = pList->head; p; p = p->next) {
		fprintf(file, "%s,%s\n", p->name, p->phone);
	}
	fclose(file);
	displayMessage("数据保存成功！");
}
void loadFromFile(List* pList, const char* filename)
{
	FILE* file = fopen(filename, "r");
	if (!file) {
		displayMessage("数据加载失败：无法打开文件或文件不存在！");
		return;
	}
	char line[100];
	while (fgets(line, sizeof(line), file)) {
		char* name = strtok(line, ",");
		char* phone = strtok(NULL, "\n");
		if (name && phone) {
			add(pList, name, phone);
		}
		else {
			displayMessage("数据加载失败：文件格式不正确！");
			fclose(file);
			return;
		}
	}
	fclose(file);
	displayMessage("数据加载成功！");
}