#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//void swap(int* , int* );
//int compare(int, int);
//void bubbleSort(int*, int);
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF || n != 0) {
//		int arr[n];
//		for (int i = 0; i < n; i++)
//			scanf("%d", &arr[i]);
//		bubbleSort(arr, n);
//		for (int i = 0; i < n; i++)
//			printf("%d ", arr[i]);
//		printf("\n");
//	}
//	return 0;
//}
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int compare(int a, int b)
//{
//	return labs(a) > labs(b);
//}
//void bubbleSort(int* arr, int n)
//{
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - 1; j++) {
//			if (compare(arr[j], arr[j + 1]) == 0) {
//				swap(&arr[j], &arr[j + 1]);
//			}
//		}
//	}
//}