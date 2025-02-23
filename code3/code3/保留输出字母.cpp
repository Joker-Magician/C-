#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//void isword(char*);
//int main()
//{
//	char a[80] = { 0 };
//	scanf("%s", a);
//	isword(a);
//	printf("%s", a);
//	return 0;
//}
//void isword(char* a)
//{
//	int n = strlen(a);
//	int i;
//	int j = 0;
//	for (i = 0; i < n; i++) {
//		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
//			a[j] = a[i];
//			j++;
//		}
//	}
//	a[j] = '\0';
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//char* isword(char*);
//int main()
//{
//	char a[80] = { 0 };
//	fgets(a, sizeof(a), stdin);
//	char* result = isword(a);
//	printf("%s", result);
//	free(result);
//	return 0;
//}
//char* isword(char* a)
//{
//	int n = strlen(a);
//	int i, j = 0;
//	char* new_str = (char*)malloc((n + 1) * sizeof(char));
//	if (new_str == NULL)
//		return NULL;
//	for (i = 0; i < n; i++) {
//		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
//			new_str[j] = a[i];
//			j++;
//		}
//	}
//	new_str[j] = '\0';
//	return new_str;
//}