#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//void remove_spaces(char*);
////int main()
////{
////	char a[100];
////	while (fgets(a, sizeof(a), stdin) != NULL) {
////		if (a[strlen(a) - 1] == '\n') {
////			a[strlen(a) - 1] = '\0';
////		}
////		remove_spaces(a);
////		printf("%s\n", a);
////	}
////	return 0;
////}
//void remove_spaces(char* a)
//{
//	int i = 0;
//	int j = 0;
//	while (a[i] != '\0') {
//		if (a[i] != ' '&&a[i]!='\n') {
//			a[j++] = a[i];
//		}
//		i++;
//	}
//	a[j] = '\0';
//}