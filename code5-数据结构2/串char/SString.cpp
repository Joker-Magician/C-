#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100

typedef struct
{
	char ch[MAXLEN];
	int len;
}SString;

int StrInsert(SString* s, int pos, SString t)
{
	if (pos < 0 || pos > s->len || s->len + t.len > MAXLEN || t.len == 0)
		return 0;

	for (int i = s->len - 1; i >= pos; i--)
		s->ch[i + t.len] = s->ch[i];
	for (int i = 0; i < t.len; i++)
		s->ch[pos + i] = t.ch[i];

	s->len += t.len;
	return 1;
}


int StrIndex(SString s, int pos, SString t)
{/*�������s���±�pos�𣬴�t��һ�γ��ֵ�λ�ã��ɹ�����λ����ţ����ɹ�����-1*/
	if (pos < 0 || pos >= s.len || t.len == 0 || t.len > s.len)
		return -1;
	for (int i = pos; i <= s.len - t.len; i++)
	{
		int j;
		for (j = 0; j < t.len; j++)
		{
			if (s.ch[i + j] != t.ch[j])
				break;
		}
		if (j == t.len)
			return i;
	}
	return -1;
}
