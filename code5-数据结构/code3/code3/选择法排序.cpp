#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void swap(int*, int*);
//void selectionSort(int*, int);
//int main()
//{
//	int a[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//		scanf("%d", &a[i]);
//	selectionSort(a, 10);
//	for (int i = 0; i < 10; i++)
//		printf("%d\n", a[i]);
//	return 0;
//}
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void selectionSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++) {
//		int min_index = i;
//		for (int j = i ; j < n; j++) {
//			if (a[j] < a[min_index]) {
//				min_index = j;
//			}
//		}
//		if (min_index != i) {
//			swap(&a[i], &a[min_index]);
//		}
//	}
//}
