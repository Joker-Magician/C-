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
int Index_BF(SString S, SString T) 
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]){
			++i;
			++j;
		}
		else {
			i = i - j + 2; 
			j = 1;
		}
	}
	if (j >= T.length) return i - T.length;
	else return 0;
}

/*将主串的第pos个字符和模式串的第一个字符比较：
若相等，继续逐个比较后续字符
若不等，从主串的下一字符起，重新与模式串的第一个字符比较
 直到主串的一个连续子串字符序列与模式串相等。返回值为S中与T匹配的子序列第一个字符的序号，即匹配成功
 否则，匹配失败，返回值0*/

/*KMP算法*/
void get_nextval(SString T, int nextval[])
{
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			if (T.ch[i] != T.ch[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	}
}

int main()
{


	return 0;
}