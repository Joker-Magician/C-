#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//
//struct student{
//	char name[101];
//	int age;
//	int score;
//}stu[1001];
//
//void swap(struct student* a, struct student* b) {
//	struct student temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		scanf("%s %d %d", stu[i].name, &stu[i].age, &stu[i].score);
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j < n - i; j++) {
//			if (stu[j].score > stu[j+1].score) {
//				struct student* p1 = &stu[j];
//				struct student* p2 = &stu[j + 1];
//				swap(p1, p2);
//			}
//			else if (stu[j].score == stu[j + 1].score) {
//				struct student* p1 = &stu[j];
//				struct student* p2 = &stu[j + 1];
//				if (strcmp(p1->name, p2->name) > 0) {
//					swap(p1, p2);
//				}
//				else if (strcmp(p1->name, p2->name) == 0) {
//					if (p1->age > p2->age) {
//						swap(p1, p2);
//					}
//				}
//			/*	if ((p1->name[0]) > (p2->name[0])) {
//					swap(p1, p2);
//				}
//				else if ((p1->name[0]) > (p2->name[0])) {
//					if (p1->age > p2->age) {
//						swap(p1, p2);
//					}
//				}*/
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//		printf("%s %d %d\n", stu[i].name, stu[i].age, stu[i].score);
//	return 0;
//}Ã°ÅÝÅÅÐòËã·¨ÅÅ³É¼¨

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//struct student {
//	char name[101];
//	int age;
//	int score;
//}stu[1001];
//
//int main()
//{
//	int n,min,temp;
//	scanf("%d", &n);
//	int* a = (int*)malloc(n * sizeof(int));
//	if (a == NULL) {
//		printf("Memory allocation failed!\n");
//		return 1;
//	}
//	for (int i = 0; i < n; i++) {
//		a[i] = i;
//		scanf("%s %d %d", stu[i].name, &stu[i].age, &stu[i].score);
//	}
//	for (int i = 0; i < n; i++) {
//		min = i;
//		for (int j = i + 1; j < n; j++) {
//			if (stu[a[j]].score < stu[a[min]].score)
//				min = j;
//			else if (stu[a[j]].score == stu[a[min]].score) {
//				if (strcmp(stu[a[j]].name, stu[a[min]].name) < 0)
//					min = j;
//				else if (strcmp(stu[a[j]].name, stu[a[min]].name) == 0)
//					if (stu[a[j]].age < stu[a[min]].age)
//						min = j;
//			}
//		}
//		temp = a[i];
//		a[i] = a[min];
//		a[min] = temp;
//	}
//	for (int i = 0; i < n; i++) {
//		printf("%s %d %d\n", stu[a[i]].name, stu[a[i]].age, stu[a[i]].score);
//	}
//	free(a);
//	return 0;
//}	Ñ¡ÔñËã·¨ÅÅÐò