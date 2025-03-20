#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//struct student {
//	char number[20];
//	char name[50];
//	int score1, score2, score3;
//};
//
//void input(struct student*,int);
//void print(struct student*,int);
//
////int main()
////{
////	int N;
////	struct student stu[100];
////	scanf("%d", &N);
////	input(stu, N);
////	print(stu, N);
////	return 0;
////}
//
//void input(struct student *stu, int N)
//{
//	int i;
//	for (i = 0; i < N; i++) 
//		scanf("%s%s%d%d%d", stu[i].number, stu[i].name, &stu[i].score1, &stu[i].score2, &stu[i].score3);
//}
//
//void print(struct student* stu, int N)
//{
//	int i;
//	for (i = 0; i < N; i++)
//		printf("%s,%s,%d,%d,%d\n", stu[i].number, stu[i].name, stu[i].score1, stu[i].score2, stu[i].score3);
//}