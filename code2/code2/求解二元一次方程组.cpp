#include<stdio.h>
#include<math.h>
//void greater(double, double, double);
//void equal(double, double, double);
//void less(double, double, double);
////int main()
////{
////	double a, b, c;
////	double data;
////	scanf_s("%lf%lf%lf", &a, &b, &c);
////	data = b * b - 4 * a * c;
////	if (data > 0)
////		greater(a, b, c);
////	else if (data == 0)
////		equal(a, b, c);
////	else
////		less(a, b, c);
////	return 0;
////}
//void greater(double a, double b, double c)
//{
//	double x1, x2;
//	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
//	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
//	printf("x1=%0.3lf ", x1);
//	printf("x2=%0.3lf ", x2);
//}
//void equal(double a, double b, double c)
//{
//	double x1, x2;
//	x1 = (-b) / (2 * a);
//	x2 = (-b) / (2 * a);
//	printf("x1=%0.3lf ", x1);
//	printf("x2=%0.3lf ", x2);
//}
//void less(double a, double b, double c)
//{
//	double m, n;
//	m = (-b) / (2 * a);
//	n = sqrt(4 * a * c - b * b)/(2*a);
//	printf("x1=%0.3lf+%0.3lfi x2=%0.3lf-%0.3lfi", m, n, m, n);
//}