//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//void classify(char a[100], int b[4])
//{
//	int i;
//	int len = 0;
//	len = strlen(a);
//	for (i = 0; i<len; i++) {
//		if (a[i] == '\n') {
//			continue;
//		}
//		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
//			b[0]++;
//		else if (a[i] >= '0' && a[i] <= '9')
//			b[1]++;
//		else if (a[i] == ' ')
//			b[2]++;
//		else
//			b[3]++;
//	}
//}
//int main()
//{
//	char a[100];
//	int b[4] = { 0 };
//	int i = 0;
//	fgets(a, sizeof(a), stdin);
//	classify(a, b);
//	for (i = 0; i < 4; i++) {
//		printf("%d ", b[i]);
//	}
//	return 0;
//}

