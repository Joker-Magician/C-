#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	char ch[100];
	int len;
}SString;

int StrLength(SString* s)
/* ���ش��ĳ���*/
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
		printf("\n\t\t�մ�! \n");
	}
	else
	{
		printf("\n\t\t�ô�ֵΪ: ");
		for (i = 0; i < r->len; i++)
			putchar(r->ch[i]);
	}
}

int StrInsert(SString* s, int pos, SString t)
/*�ڴ�s���±�Ϊpos���ַ�֮ǰ���봮t */
{
	int i;
	if (pos<0 || pos>s->len)
		return(0); /*����λ�ò��Ϸ�*/
	if (s->len + t.len <= 100)
	{   /*����󴮳���MAXLEN*/
		for (i = s->len + t.len - 1; i >= t.len + pos; i--)
			s->ch[i] = s->ch[i - t.len];
		for (i = 0; i < t.len; i++)
			s->ch[i + pos] = t.ch[i];
		s->len = s->len + t.len;
	}
	else if (pos + t.len <= 100)
	{/*����󴮳�>MAXLEN,����t���ַ����п���ȫ������*/
		for (i = 100 - 1; i > t.len + pos - 1; i--)
			s->ch[i] = s->ch[i - t.len];
		for (i = 0; i < t.len; i++)
			s->ch[i + pos] = t.ch[i];
		s->len = 100;
	}
	else
	{  /*����󴮳�>MAXLEN,���Ҵ�t�Ĳ����ַ�ҲҪ����*/
		for (i = 0; i < 100 - pos; i++)
			s->ch[i + pos] = t.ch[i];
		s->len = 100;
	}
	return(1);
}


int StrDelete(SString* s, int pos, int len)
/*�ڴ�s��ɾ�����±�pos��len���ַ�*/
{
	int i;
	if (pos<0 || pos>(s->len - len))
		return(0);   /*ɾ���������Ϸ�*/
	for (i = pos + len; i < s->len; i++)
		s->ch[i - len] = s->ch[i]; /*��pos+len��ʼ����β������ǰ�ƶ���ʵ��ɾ��len���ַ�*/
	s->len = s->len - len; /*s������len*/
	return(1);
}


int StrIndex(SString s, int pos, SString t)
/*�������s���±�pos�𣬴�t��һ�γ��ֵ�λ�ã��ɹ�����λ����ţ����ɹ�����-1*/
{
	int i, j, start;
	if (t.len == 0)
		return(0);   /* ģʽ��Ϊ�մ�ʱ�������⴮��ƥ�䴮 */
	start = pos;  i = start;  j = 0;  /* ������pos��ʼ��ģʽ����ͷ��0����ʼ */
	while (i < s.len && j < t.len)
		if (s.ch[i] == t.ch[j])
		{
			i++; j++;
		}   /* ��ǰ��Ӧ�ַ����ʱ�ƽ� */
		else
		{
			start++;        /* ��ǰ��Ӧ�ַ�����ʱ���� */
			i = start;  j = 0;   /* ������start+1��ʼ��ģʽ����ͷ��0����ʼ*/
		}
	if (j >= t.len)
		return(start);    /* ƥ��ɹ�ʱ������ƥ����ʼλ�� */
	else
		return(-1);    /* ƥ�䲻�ɹ�ʱ������-1 */
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
		printf("\n\t\t*            ����ϵͳ              *");
		printf("\n\t\t************************************");
		printf("\n\t\t*   1------�����ַ���              *");
		printf("\n\t\t*   2------ɾ���Ӵ�                *");
		printf("\n\t\t*   3------�����Ӵ�                *");
		printf("\n\t\t*   4------�����Ӵ�                *");
		printf("\n\t\t*   5------��ʾ�ַ���              *");
		printf("\n\t\t*   6------�����Ӵ����ֵĴ�����λ��*");
		printf("\n\t\t*   0------��    ��                *");
		printf("\n\t\t************************************");
		printf("\n\t\t*       ��ѡ��˵���(0-9)��       *");
		scanf("%c", &choice);
		getchar();
		if (choice == '1')
		{
			printf("\n\t\t������һ���ַ���: ");
			CreateStr(&a);
		}
		else if (choice == '2')
		{
			printf("\n\t\t������ӵڼ����ַ���ʼ: ");
			scanf("%d", &i);
			getchar();
			printf("\n\t\t������ɾ���������ַ���: ");
			scanf("%d", &j);
			getchar();
			StrDelete(&a, i - 1, j);
		}
		else if (choice == '3')
		{
			printf("\n\t\t������ӵڼ����ַ���ʼ����: ");
			scanf("%d", &i);
			getchar();
			printf("\n\t\t��������Ҫ������ַ���: ");
			CreateStr(&b);
			if (StrInsert(&a, i - 1, b) == 1)
			{
				printf("\n\t\t�´�ֵ: ");
				ShowStr(&a);
			}
		}
		else if (choice == '4')
		{
			printf("\n\t\t��������Ҫ���ҵ��ַ���: ");
			CreateStr(&b);
			i = StrIndex(a, 0, b);
			if (i != -1)
			{
				printf("\n\t\t��һ�γ��ֵ�λ����%d.\n ", i + 1);
			}
			else
			{
				printf("\n\t\t���Ӵ���������!");
			}

		}
		else if (choice == '5')
		{
			ShowStr(&a);
			n = StrLength(&a);
			printf("\n\t\t������Ϊ:%d", n);
		}
		else if (choice == '6')
		{
			int pos = 0, num = 0;
			printf("\n\t\t��������Ҫ���ҵ��ַ���: ");
			CreateStr(&b);
			while (pos < a.len - 1)
			{
				i = StrIndex(a, pos, b);
				if (i != -1)
				{
					num++;
					printf("\n\t\t��%d�γ��ֵ�λ���ǵ�%d��.\n ", num, i + 1);
				}
				else
					break;
				pos = i + b.len;
			}
			if (num == 0)
				printf("\n\t\t���Ӵ���������!");
			else
				printf("\n\t\t���Ӵ���������%d��!", num);
		}
		else if (choice == '0')
		{
			break;
		}
		else
		{
			printf("\n\t\t��ע��:��������! \n");
			printf("\n\t\t��������������˵�\n");
			p = getchar();
		}
	}
	return 0;
}
