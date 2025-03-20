//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//void fun(char* );
//int main()
//{
//	char str[100];
//	printf("请输入一个字符串：\n");
//	fgets(str,sizeof(str),stdin);
//	fun(str);
//	printf("转换后的字符串为：\n");
//	puts(str);
//	return 0;
//}
//void fun(char* str)
//{
//	while (*str != 0) {
//		if (*str >= 'a' && *str <= 'z') {
//			*str = *str - 32;
//		}
//		str++;
//	}
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#define N 10
//struct Student {
//	char name[20];
//	int score1;
//	int score2;
//};
//int main()
//{
//	Student stu[N];
//	int i = 0;
//	int sumScore1 = 0, sumScore2 = 0;
//	for (i = 0; i < N; i++) {
//		printf("请输入第%d个学生的姓名、课程1成绩、课程2成绩：\n", i + 1);
//		scanf("%s%d%d", stu[i].name, &stu[i].score1, &stu[i].score2);
//		sumScore1 += stu[i].score1;
//		sumScore2 += stu[2].score2;
//	}
//	double ave1 = (double)sumScore1 / N;
//	double ave2 = (double)sumScore2 / N;
//	printf("Name\tScore-1\tScore-2\n");
//	for (i = 0; i < N; i++) {
//		printf("%s\t%d\t\t%d\n", stu[i].name, stu[i].score1, stu[i].score2);
//	}
//	printf("Average:\t%.2f\t\t%.2f\n", ave1, ave2);
//	return 0;
//}