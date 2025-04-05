#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void minmax(int* a, int* b);
//int main()
//{
//	int a, b;
//	int a1, b1;
//	int t;
//	scanf_s("%d%d", &a, &b);
//	a1 = a, b1 = b;
//	while (b1 != 0) {
//		t = a1 % b1;
//		a1 = b1;
//		b1 = t;
//	}
//	printf("%d  ", a1);
//	minmax(&a, &b);
//	int i,ret=0;
//	for (i = a; i <= a * b; i++) {
//		if (i % a == 0 && i % b == 0) {
//				ret = i;
//				break;
//		}
//	}
//	printf("%d", ret);
//	return 0;
//}
//
//void minmax(int *a, int *b)
//{
//	int t;
//	if (*a > *b) {
//		t = *a;
//		*a = *b;
//		*b = t;
//	}
//}  