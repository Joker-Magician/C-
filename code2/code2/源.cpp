#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>// 引入该头文件用于使用abs函数求绝对值
//int main()
//{
//	int a[10];
//	int i,j;
//	for (i = 0; i < 10; i++)
//		scanf("%d", &a[i]);
//	int min = a[0];
//	for (i = 0; i < 10; i++) {
//		if (abs(min) > abs(a[i])) {
//			min = a[i];
//			j = i;
//		}
//	}
//		int temp = a[9];
//		a[9] = min;
//		a[j] = temp;
//		for (i = 0; i < 10; i++)
//			printf("%d ", a[i]);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//double fact(int);
//double mypow(double, int);
//int main()
//{
//	double x;
//	int n;
//	scanf("%lf%d", &x, &n);
//	printf("%.4lf", mypow(x, n));
//	return 0;
//}
//double fact(int n)
//{
//	if (n == 0)
//		return 1;
//	else
//		return n * fact(n - 1);
//}
//double mypow(double x, int n)
//{
//	int i;
//	double sum = 0;
//	for (i = 1; i <= n; i++) {
//		sum += (pow((-1), i - 1) * pow(x, i)) / fact(i);
//	}
//	return sum;
//}

//#include<stdio.h>
//#include<math.h>
//double f(int);
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	printf("%.2lf", f(x));
//	return 0;
//}
//double f(int x)
//{
//	if (x < 0)
//		return fabs(x);
//	else if (x >= 0 && x < 2)
//		return sqrt(x + 1);
//	else if (x >= 2 && x < 4)
//		return pow(x + 2, 5);
//	else
//		return 2 * x + 5;
//}

//#include<stdio.h>
//int ctof(int);
//int main()
//{
//	int c=-100;
//	while (c <= 150) {
//		printf("c=%d->f=%d\n", c, ctof(c));
//		c += 5;
//	}
//	return 0;
//}
//int ctof(int c)
//{
//	int f;
//	f = 32 + c * 9 / 5;
//	return f;
//}

//#include<stdio.h>
//int main()
//{
//	int n,i,j;
//	int a[100][100];
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n; j++) {
//			scanf("%d", &a[i][j]);
//		}
//	}
//	int cnt1, cnt2;
//	int max = a[0][0];
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n; j++) {
//			if (a[i][j] > max) {
//				max = a[i][j];
//				cnt1 = i;
//				cnt2 = j;
//			}
//		}
//	}
//	printf("%d %d %d", max, cnt1+1, cnt2+1);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a[100];
//	int b[3] = {0};
//	int j;
//	int i=0;
//	do {
//		scanf("%d", &a[i]);
//		i++;
//	} while (a[i-1] != 0);
//	for (j = 0; j < i-1;j++) {
//		if (a[j] >= 85)
//			b[0]++;
//		else if (a[j] >= 60 && a[j] < 85)
//			b[1]++;
//		else
//			b[2]++;
//	}
//	printf(">=85:%d\n", b[0]);
//	printf("60-84:%d\n", b[1]);
//	printf("<60:%d", b[2]);
//	return 0;
//}

//#include<stdio.h>
//double fact(int);
//int main()
//{
//	double k;
//	int i;
//	double sum = 0;
//	scanf("%lf", &k);
//	for (i = 1; i <= k; i++) {
//		sum += 1.0 / fact(i);
//	}
//	printf("sum=%.5lf", sum);
//	return 0;
//}
//double fact(int k)
//{
//	double n=1;
//	int i;
//	for (i = 1; i <= k; i++) {
//		n *= i;
//	}
//	return n;
//}

//#include<stdio.h>
//void swap(int*a, int*b);
//int main()
//{
//	int a,  b;
//	scanf("%d%d", &a, &b);
//	swap(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}
//void swap(int* a, int* b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}