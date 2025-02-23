#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
////#define swap(x1,x2) do{int temp=(x1);(x1)=(x2);(x2)=temp;}while(0)
//#define swap(x1,x2) t=x1;x1=x2;x2=t
//int main(void)
//{
//	int x1, x2,t;
//	scanf("%d%d", &x1, &x2);
//	swap(x1, x2);
//	printf("%d %d", x1, x2);
//	return 0;
//}

//#include<stdio.h>
//#define S(a,b) a%b
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	printf("%d", S(a, b));
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//#define S (a+b+c)/2
//#define area sqrt(S*(S-a)*(S-b)*(S-c))
//int main()
//{
//	double a, b, c;
//	scanf("%lf%lf%lf", &a, &b, &c);
//	printf("%lf", area);
//	return 0;
//}

//#include<stdio.h>
//#define isLeapYear(year) (((year)%4==0&&(year)%100!=0)||((year)%400==0)?1:0)
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	printf( "%s",isLeapYear(year)?"L":"N");
//	return 0;
//}

//#include<stdio.h>
//#define MAX(a,b,c) ((a>b)?((a>c)?a:c):((b>c)?b:c))
//double Max(double, double, double);
//int main()
//{
//	double a, b, c;
//	scanf("%lf%lf%lf", &a, &b, &c);
//	printf("%.3lf\n", MAX(a,b,c));
//	printf("%.3lf\n", Max(a,b,c));
//	return 0;
//}
//
//double Max(double a, double b, double c)
//{
//	double max;
//	if (a < b) {
//		max = b;
//			if (b < c)
//				max = c;
//	}
//	else {
//		if (a > c)
//			max = a;
//		else
//			max = c;
//	}
//	return max;
//}