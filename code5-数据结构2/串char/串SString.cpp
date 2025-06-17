#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	char ch[100];
	int len;
}SString;

int StrLength(SString* s)
/* 返回串的长度*/
{
	return(s->len);
}

void CreateStr(SString* r)
{
	int i = 0;
	fgets(r->ch,sizeof(r->ch),stdin);
	while (r->ch[i] != '\0')
	{
		i++;
	}
	r->len = i;
}

void ShowStr(SString* r)
{
	int i;
	if (r->len == 0)
	{
		printf("\n\t\t空串! \n");
	}
	else
	{
		printf("\n\t\t该串值为: ");
		for (i = 0; i < r->len; i++)
			putchar(r->ch[i]);
	}
}

int StrInsert(SString* s, int pos, SString t)
/*在串s中下标为pos的字符之前插入串t */
{
	int i;
	if (pos<0 || pos>s->len)
		return(0); /*插入位置不合法*/
	if (s->len + t.len <= 100)
	{   /*插入后串长≤MAXLEN*/
		for (i = s->len + t.len - 1; i >= t.len + pos; i--)
			s->ch[i] = s->ch[i - t.len];
		for (i = 0; i < t.len; i++)
			s->ch[i + pos] = t.ch[i];
		s->len = s->len + t.len;
	}
	else if (pos + t.len <= 100)
	{/*插入后串长>MAXLEN,但串t的字符序列可以全部插入*/
		for (i = 100 - 1; i > t.len + pos - 1; i--)
			s->ch[i] = s->ch[i - t.len];
		for (i = 0; i < t.len; i++)
			s->ch[i + pos] = t.ch[i];
		s->len = 100;
	}
	else
	{  /*插入后串长>MAXLEN,并且串t的部分字符也要舍弃*/
		for (i = 0; i < 100 - pos; i++)
			s->ch[i + pos] = t.ch[i];
		s->len = 100;
	}
	return(1);
}


int StrDelete(SString* s, int pos, int len)
/*在串s中删除从下标pos起len个字符*/
{
	int i;
	if (pos<0 || pos>(s->len - len))
		return(0);   /*删除参数不合法*/
	for (i = pos + len; i < s->len; i++)
		s->ch[i - len] = s->ch[i]; /*从pos+len开始至串尾依次向前移动，实现删除len个字符*/
	s->len = s->len - len; /*s串长减len*/
	return(1);
}


int StrIndex(SString s, int pos, SString t)
/*求从主串s的下标pos起，串t第一次出现的位置，成功返回位置序号，不成功返回-1*/
{
	int i, j, start;
	if (t.len == 0)
		return(0);   /* 模式串为空串时，是任意串的匹配串 */
	start = pos;  i = start;  j = 0;  /* 主串从pos开始，模式串从头（0）开始 */
	while (i < s.len && j < t.len)
		if (s.ch[i] == t.ch[j])
		{
			i++; j++;
		}   /* 当前对应字符相等时推进 */
		else
		{
			start++;        /* 当前对应字符不等时回溯 */
			i = start;  j = 0;   /* 主串从start+1开始，模式串从头（0）开始*/
		}
	if (j >= t.len)
		return(start);    /* 匹配成功时，返回匹配起始位置 */
	else
		return(-1);    /* 匹配不成功时，返回-1 */
}


int main()
{
	SString a, b;
	char choice, p;
	int n;
	int i, j, ch = 1;
	a.ch[0] = '\0';
	a.len = 0;
	while (ch != 0)
	{
		printf("\n");
		printf("\n\t\t*            串子系统              *");
		printf("\n\t\t************************************");
		printf("\n\t\t*   1------输入字符串              *");
		printf("\n\t\t*   2------删除子串                *");
		printf("\n\t\t*   3------插入子串                *");
		printf("\n\t\t*   4------查找子串                *");
		printf("\n\t\t*   5------显示字符串              *");
		printf("\n\t\t*   6------查找子串出现的次数和位置*");
		printf("\n\t\t*   0------退    出                *");
		printf("\n\t\t************************************");
		printf("\n\t\t*       请选择菜单号(0-9)：       *");
		scanf("%c", &choice);
		getchar();
		if (choice == '1')
		{
			printf("\n\t\t请输入一个字符串: ");
			CreateStr(&a);
		}
		else if (choice == '2')
		{
			printf("\n\t\t请输入从第几个字符开始: ");
			scanf("%d", &i);
			getchar();
			printf("\n\t\t请输入删除的连续字符数: ");
			scanf("%d", &j);
			getchar();
			StrDelete(&a, i - 1, j);
		}
		else if (choice == '3')
		{
			printf("\n\t\t请输入从第几个字符开始插入: ");
			scanf("%d", &i);
			getchar();
			printf("\n\t\t请输入所要插入的字符串: ");
			CreateStr(&b);
			if (StrInsert(&a, i - 1, b) == 1)
			{
				printf("\n\t\t新串值: ");
				ShowStr(&a);
			}
		}
		else if (choice == '4')
		{
			printf("\n\t\t请输入所要查找的字符串: ");
			CreateStr(&b);
			i = StrIndex(a, 0, b);
			if (i != -1)
			{
				printf("\n\t\t第一次出现的位置是%d.\n ", i + 1);
			}
			else
			{
				printf("\n\t\t该子串不在其中!");
			}

		}
		else if (choice == '5')
		{
			ShowStr(&a);
			n = StrLength(&a);
			printf("\n\t\t串长度为:%d", n);
		}
		else if (choice == '6')
		{
			int pos = 0, num = 0;
			printf("\n\t\t请输入所要查找的字符串: ");
			CreateStr(&b);
			while (pos < a.len - 1)
			{
				i = StrIndex(a, pos, b);
				if (i != -1)
				{
					num++;
					printf("\n\t\t第%d次出现的位置是第%d个.\n ", num, i + 1);
				}
				else
					break;
				pos = i + b.len;
			}
			if (num == 0)
				printf("\n\t\t该子串不在其中!");
			else
				printf("\n\t\t该子串共出现了%d次!", num);
		}
		else if (choice == '0')
		{
			break;
		}
		else
		{
			printf("\n\t\t请注意:输入有误! \n");
			printf("\n\t\t按任意键返回主菜单\n");
			p = getchar();
		}
	}
	return 0;
}
