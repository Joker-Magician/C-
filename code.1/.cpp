#define _CRT_SECURE_NO_WARNINGS


//#include<stdio.h>
//#include<string.h>
//int mycmp(const char* s1, const char* s2)
//{
//	/*int idx = 0;
//	while (s1[idx] == s2[idx] && s1[idx] != '\0') {
//		idx++;
//	}*/
//	while (*s1 == *s2 && *s1 != '\0') {
//		s1++;
//		s2++;
//	}
//	return *s1 - *s2;
//}
//int main(int argc, char const* argv[])
//{
//	char s1[] = "abc";
//	char s2[] = "abc";
//	/*printf("%d\n", strcmp(s1, s2));*/
//	printf("%d\n", mycmp(s1, s2));
//	printf("%d\n", 'a' - 'A');
//	return 0;
//} strcmp�Ƚ�s1��s2�Ĵ�С���������ֵ

#include<stdio.h>
#include<string.h>

char* mycpy(char* dst, const char* src)
{
	/*int idx = 0;
	while (src[idx]) {
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';*/
	char* ret = dst;
	while (*dst++ = *src++)
		;
	*dst = '\0';
	return dst;
}
int main(int argc, char const* argv[])
{
	char s1[] = "abc";
	char s2[] = "abc";
	strcpy(s1, s2);
	return 0;
}  //char*strcpy(cahr*restrict dst,const char*restrict src);
//��src���ַ���������dst
//restrict����src��dst���ص���C99��
//������·
//char*dst=(char*)malloc(strlen(src)+1);
//strcpy(dst,src);

//char* strcat(char* restrict, const char* restrict s2);
//��s2������s1���棬���һ�������ַ���
//����s1����s1�������㹻�Ŀռ�
