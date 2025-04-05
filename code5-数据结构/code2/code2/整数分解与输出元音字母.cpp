#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void trans(int);
//int main()
//{
//	
//	int i, j;
//	int a[3][3];
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 3; j++) {
//			scanf_s("%d", &a[i][j]);
//		}
//	}
//	trans(a);
//	return 0;
//
//}
//void trans(int a[3][3])
//{
//	int i, j;
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 3; j++) {
//			printf("%d", a[j][i]);
//		}
//	}
//}
//#include<stdio.h>
//void define(char* a, char* b);
//int main()
//{
//	char a[1000];
//	char b[100];
//	scanf("%s", a);
//	define(a, b);
//	printf("%s", b);
//	return 0;
//}
//void define(char* a, char* b)
//{
//	while (*a != 0) {
//		switch (*a) {
//			case'a':
//			case'e':
//			case'i':
//			case'o':
//			case'u':
//				*(b++) = *a;
//			default:
//				break;
//		}
//		a++;
//	}
//	*(b++) = '\0';
//}
//#include<stdio.h>
////int main()
//{
//	int n;
//	int mask = 1;
//	scanf_s("%d", &n);
//	int t = n;
//	while (t > 9) {
//		t /= 10;
//		mask *= 10;
//	}
//	do {
//		int d = n / mask;
//		printf("%d", d);
//		if (mask > 9) {
//			printf(" ");
//		}
//		n %= mask;
//		mask /= 10;
//	} while (mask > 0);
//	return 0;
//}