#define _CRT_SECURE_NO_WARNINGS
#include"list.h"

void saveToFile(List* pList, const char* filename)
{
	FILE* file = fopen(filename, "w");
	if (!file) {
		displayMessage("���ݱ���ʧ�ܣ�");
		return;
	}
	Node* p;
	for (p = pList->head; p; p = p->next) {
		fprintf(file, "%s,%s\n", p->name, p->phone);
	}
	fclose(file);
	displayMessage("���ݱ���ɹ���");
}
void loadFromFile(List* pList, const char* filename)
{
	FILE* file = fopen(filename, "r");
	if (!file) {
		displayMessage("���ݼ���ʧ�ܣ��޷����ļ����ļ������ڣ�");
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
			displayMessage("���ݼ���ʧ�ܣ��ļ���ʽ����ȷ��");
			fclose(file);
			return;
		}
	}
	fclose(file);
	displayMessage("���ݼ��سɹ���");
}