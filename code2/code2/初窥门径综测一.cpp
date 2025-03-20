#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int n,i,j;
//	int sum = 0;
//	int SUM = 0;
//	int a = 2;
//	scanf("%d", &n);
//	while (n!=0) {
//		for (i = 0; i < n; i++) {
//			sum += a;
//			a *= 10;
//		}
//		SUM += sum;
//		n--;
//		sum = 0;
//		a = 2;
//	}
//	printf("%d", SUM);
//	return 0;
//}

//#include<stdio.h>
//int func(int n)
//{
//	int sum = 0;
//	if (n == 0)
//		sum = 1;
//	else
//		sum = n * func(n - 1);
//	return sum;
//}
//int main()
//{
//	/*int i,n;
//	long long sum = 1;
//	long long SUM = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++) {
//		sum *= i;
//		SUM += sum;
//	}
//	printf("%lld", SUM);*/
//	int i,n;
//	int sum = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++) 
//		sum += func(i);
//	printf("%d", sum);
//	return 0;
//}

////#include<stdio.h>
////int isperfect(int num) {
////	int i, sum = 0;
////	for (i = 1; i < num; i++) {
////		if (num % i == 0) {
////			sum += i;
////		}
////	}
////	return sum == num;
////}
////void put_factors(int num) {
////	int i;
////	printf("%d its factors are ", num);
////	for (i = 1; i < num; i++) {
////		if (num % i == 0) {
////			printf("%d ", i);
////		}
////	}
////	printf("\n");
////}
////int main()
////{
////	int num,n;
////	scanf("%d", &n);
////	for (num = 1; num <= n; num++) {
////		if (isperfect(num)) {
////			put_factors(num);
////		}
////	}
////	return 0;
////}

//#include<stdio.h>
//int main()
//{
//	int N,i,j;
//	int sum;
//	scanf("%d", &N);
//	for (i = 1; i <= N; i++) {
//		sum = 0;
//		for (j = 1; j < i; j++) {
//			if (i % j == 0) {
//				sum += j;
//			}
//		}
//		if (sum == i) {
//			printf("%d ", i);
//			printf("its factors are");
//			for (j = 1; j < i; j++) {
//				if (i % j == 0)
//					printf(" %d", j);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//#include<stdio.h>
//#include<math.h>
//void square_root(double);
//double func(double, double);
//int main()
//{
//	double a;
//	scanf("%lf", &a);
//	square_root(a);
//	return 0;
//}
//void square_root(double a)
//{
//	double X = 1;
//	double m, n;
//	int i = 1;
//	do {
//		m = func(X, a);
//		n = func(m, a);
//		X = m;
//	} while (fabs(m - n) >= 0.00001);
//	printf("%.3lf", m);
//}
//double func(double X, double a)
//{
//	return X = (X + a / X) / 2;
//}

//#include<stdio.h>
//#include<string.h>
//void recognize(char*, int*);
//int main()
//{
//	char a[100];
//	int b[4] = { 0 };
//	fgets(a, sizeof(a), stdin);
//	int n = strlen(a);
//	if (a[n - 1] == '\n')
//		a[n - 1] = '\0';
//	recognize(a, b);
//	for (int i = 0; i < 4; i++)
//		printf("%d\n", b[i]);
//	return 0;
//}
//void recognize(char* a, int* b)
//{
//	int n = strlen(a);
//	for (int i = 0; i < n; i++) {
//		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
//			b[0]++;
//		else if (a[i] == ' ')
//			b[1]++;
//		else if (a[i] >= '0' && a[i] <= '9')
//			b[2]++;
//		else
//			b[3]++;
//	}
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	double k = 1;
//	double sum = 0;
//	//scanf("%d", &n);
//	n = 30;
//	for (int i = 1; i <= n; i++) {
//		k = 1;
//		for (int j = 1; j <= i; j++) {
//			k *= j;
//		}
//		sum += k;
//	}
//	printf("%.2e\n", sum);
//	return 0;
//}