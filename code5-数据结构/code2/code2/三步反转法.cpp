#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void fun(int*, int, int);
//int main()
//{
//	int n,i,x;
//	int a[100];
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%d", &a[i]);
//	}
//	scanf("%d", &x);
//	fun(a, x, n);
//	for (i = 0; i < n; i++) {
//		printf("%d ", a[i]);
//	}
//	return 0;
//}
//void fun(int* a, int x, int n)
//{
//	x %= n;
//	int left = 0;
//	int right = n - 1;
//	while (left < right) {
//		int temp = a[left];
//		a[left] = a[right];
//		a[right] = temp;
//		left++;
//		right--;
//	}
//	left = 0;
//	right = x - 1;
//	while (left < right) {
//		int temp = a[left];
//		a[left] = a[right];
//		a[right] = temp;
//		left++;
//		right--;
//	}
//	left = x;
//	right = n - 1;
//	while (left < right) {
//		int temp = a[left];
//		a[left] = a[right];
//		a[right] = temp;
//		left++;
//		right--;
//	}
//}