#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN 255

typedef struct {
	char ch[MAXLEN + 1]; //存储串的一维数组，从1号位置开始存储
	int length; //串的当前长度
}SString;

/*串的链式存储*/
/*#define CHUNKSIZE 80 //块的大小可由用户定义
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct {
	Chunk* head, * tail;
	int curlen;
}LString;*/

/*串的模式匹配算法*/
/*BF算法，简单粗暴，效率较低*/

/*将主串的第pos个字符和模式串的第一个字符比较：
	若相等，继续逐个比较后续字符
	若不等，从主串的下一字符起，重新与模式串的第一个字符比较*/

int main()
{


	return 0;
}