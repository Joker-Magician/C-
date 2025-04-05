//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdbool.h>
//
//struct date {
//	int year;
//	int month;
//	int day;
//};
//
//bool isLeap(struct date d);
//int numberOfDays(struct date d);
//
////int main()
////{
////	struct date time;
////	int days;
////	scanf("%i%i%i", &time.year, &time.month, &time.day);
////	if ((time.month > 2 && isLeap(time))||(time.month==2&&time.day>28))
////		days = numberOfDays(time) + 1;
////	else
////		days = numberOfDays(time);
////	printf("%d", days);
////	return 0;
////}
//int numberOfDays(struct date d)
//{
//	
//	//int days;
//	int i;
//	int sum = 0;
//	const int daysPerMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	//if (d.month == 2 && isLeap(d))
//	//	days = 29;
//	//else
//	//	days = daysPerMonth[d.month - 1];
//	for (i = 0; i < (d.month - 1); i++) 
//		sum += daysPerMonth[i];
//	sum += d.day;
//	return sum;
// }
//bool isLeap(struct date d)
//{
//	bool leap = false;
//	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
//		leap = true;
//	return leap;
//}