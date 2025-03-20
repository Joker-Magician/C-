#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int salary[20] = { 0 };
//	int i, j,temp;
//	for (i = 0; i < 20; i++)
//		scanf("%d", &salary[i]);
//	for(i=1;i<20;i++)
//		for(j=0;j<20-i;j++)
//			if (salary[j] < salary[j + 1]) {
//				temp = salary[j];
//				salary[j] = salary[j + 1];
//				salary[j + 1] = temp;
//			}
//	for (i = 0; i < 20; i++)
//		printf("%d ", salary[i]);
//	printf("\n");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i,j;
//	for (i = 100; i <= 200; i++) {
//		int isPrime = 1;
//		for (j = 2; j < i; j++) {
//			if (i % j == 0) {
//				isPrime = 0;
//				break;
//			}
//		}
//		if (isPrime == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//struct student {
//	int num;
//	char name[20];
//	char sex;
//	int score;
//}stu[80];
//int main()
//{
//	int i;
//	for (i = 0; i < 5; i++) {
//		/*scanf("%d", &stu[i].num);
//		fgets(stu[i].name, sizeof(stu[i].name), stdin);
//		stu[i].name[strcspn(stu[i].name, "\n")] = '\0';
//		scanf("%c", &stu[i].sex);
//		scanf("%d", &stu[i].score);*/
//		scanf("%d %s %c %d", &stu[i].num, stu[i].name, &stu[i].sex, &stu[i].score);
//	}
//	for (i = 0; i < 5; i++)
//		printf("%d %s %c %d\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score);
//	return 0;
//}