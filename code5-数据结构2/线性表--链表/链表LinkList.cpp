#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef struct node
{
	int  data;
	struct node* next;
} Node, * linklist;


/*��ʼ������*/
void InitList(linklist* L)
{
	*L = (linklist)malloc(sizeof(Node));/*Ϊͷ������洢�ռ�*/
	(*L)->next = NULL;
}

/*��������*/
linklist  CreateList()
{
	int d;
	linklist L;
	Node* p, * s;
	L = (linklist)malloc(sizeof(Node));
	L->next = NULL;
	printf("please input the integer!(0---return):  ");
	scanf("%d", &d);
	while (d != 0)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = d;
		p = L;
		while (p->next != NULL)
			if (p->next->data < d)
				p = p->next;
			else break;
		s->next = p->next;
		p->next = s;
		printf("please input the integer!(0---return):  ");
		scanf("%d", &d);
	}
	return L;
}
/*��������*/
int	ListLength(linklist L) /*LΪ��ͷ���ĵ�����*/
{
	Node* p;
	int j;
	p = L->next;
	j = 0;   /*������ŵ�����ĳ���*/
	while (p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

/*��������е�����Ԫ��*/
void OutList(linklist L) /*LΪ��ͷ���ĵ�����*/
{
	Node* p; p = L->next;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
	return;
}

/*�ڴ�ͷ���ĵ�����L�в��ҵ�i����㣬���ҵ�(1��i��n)���򷵻ظý��Ĵ洢λ��;  ���򷵻�NULL */
Node* GetData(linklist  L, int i)
{
	int j;
	Node* p;
	p = L;
	j = 0;       /* ��ͷ��㿪ʼɨ�� */
	while ((p->next != NULL) && (j < i))
	{
		p = p->next;
		j++;   /* ɨ����һ��� */
	}        /* ��ɨ��������� */
	if (i == j)
		return p;   /* �ҵ��˵�i����� */
	else
		return NULL;   /* �Ҳ�����i��0��i>n */
}
//��ֵ����
Node* Locate(linklist L, int key)
{
	Node* p;
	p = L->next;   /* �ӱ��е�һ�����Ƚ� */
	while (p != NULL)
	{
		if (p->data != key)
			p = p->next;
		else  break;     /* �ҵ����key���˳�ѭ�� */
	}
	return p;
}

void InsList(linklist L, int e)
{  /*�ڴ�ͷ���ĵ�����L�в���ֵΪe���½�㡣 */
	Node* pre, * s;
	int  k = 0;
	pre = L;

	s = (Node*)malloc(sizeof(Node));
	s->data = e;

	pre = L;
	while ((pre->next != NULL) && (pre->next->data < e))
	{
		pre = pre->next;
	}
	s->next = pre->next;
	pre->next = s;
}

int DelList(linklist L, int* pos, int e)
/*�ڴ�ͷ���ĵ�����L��ɾ��ֵΪe��Ԫ�أ���������λ�õ�����*pos��*/
{
	Node* pre, * r;
	int k = 0; pre = L;

	if (pre->next == NULL)
		return ERROR;

	while ((pre->next != NULL) && (pre->next->data != e)) /*Ѱ�ұ�ɾ������ǰ�����*/
	{
		pre = pre->next;
		k = k + 1;
	}
	if (pre->next == NULL)    /*δ�ҵ�*/
	{
		return ERROR;
	}
	r = pre->next;
	pre->next = r->next;    /*ɾ�����r*/
	free(r);    /*�ͷű�ɾ���Ľ����ռ���ڴ�ռ�*/
	*pos = k + 1;
	return OK;
}

void Mergelinklist(linklist LA, linklist LB)
/*����������ĵ�����LA��LB�ϲ���һ����������ĵ�����*/
{
	Node* pa, * pb;
	linklist r;
	/*pa��pb�ֱ�ָ������������LA��LB�еĵ�һ�����*/
	pa = LA->next;
	pb = LB->next;

	r = LA;
	r->next = NULL;/*rָ��ձ�*/

	/*���������о�δ������ʱ���Ƚ�ѡ�񽫽�Сֵ�����뵽�±��С�*/
	while (pa != NULL && pb != NULL)
	{
		if (pa->data <= pb->data)
		{
			r->next = pa;
			r = pa;
			pa = pa->next;
		}
		else
		{
			r->next = pb;
			r = pb;
			pb = pb->next;
		}
	}
	if (pa) /*����LAδ�꣬����LA�к���Ԫ�������±��β*/
		r->next = pa;
	else	 /*���򽫱�LB�к���Ԫ�������±��β*/
		r->next = pb;
	free(LB);
}  /* Mergelinklist */

int main()
{
	linklist head, p;
	linklist B;
	int pos;
	int x;
	int choice = 10;
	int merged = 0;

	head = CreateList();

	while (choice != 0)
	{
		system("cls");
		printf("1-----�������!\n");
		printf("2-----����Ų���!\n");
		printf("3-----��ֵ����!\n");
		printf("4-----����!\n");
		printf("5-----ɾ��!\n");
		printf("6-----�ϲ�!\n");
		printf("7-----��������!\n");
		printf("0-----�˳�!\n");
		printf("input your choice(0-----7):");
		scanf("%d", &choice);
		printf("\n");
		switch (choice)
		{
		case 1:
			OutList(head);
			system("pause");
			break;
		case 2:
			printf("������Ҫ��ѯ�����:");
			scanf("%d", &pos);
			p = GetData(head, pos);
			if (p != NULL)
				printf("�ҵ���%d��Ԫ��%d!\n", pos, p->data);
			else
				printf("δ�ҵ�%d��Ԫ��!\n", pos);
			system("pause");
			break;
		case 3:
			printf("������Ҫ���ҵ�Ԫ��:");
			scanf("%d", &x);
			p = Locate(head, x);
			if (p != NULL)
				printf("�ҵ���%d!\n", p->data);
			else
				printf("δ�ҵ�%d!\n", x);
			system("pause");
			break;
		case 4:
			printf("������Ҫ�����Ԫ��:");
			scanf("%d", &x);
			InsList(head, x);
			system("pause");
			break;
		case 5:
			printf("������Ҫɾ����Ԫ��:");
			scanf("%d", &x);
			if (DelList(head, &pos, x) == OK)//��ͬ��ֵ��ֻɾ����һ��
				printf("��ɾ����%d��Ԫ��,ֵΪ%d\n", pos, x);
			else
				printf("ɾ��ʧ��\n");
			system("pause");
			break;
		case 6:
			printf("�����ڶ���������:\n");
			B = CreateList();

			printf("��һ�������е�Ԫ��Ϊ:\n");
			OutList(head);
			printf("�ڶ��������е�Ԫ��Ϊ:\n");
			OutList(B);

			Mergelinklist(head, B);
			printf("�ϲ��������е�Ԫ��Ϊ:\n");
			OutList(head);
			system("pause");
			break;
		case 7:
			printf("������Ϊ:%d\n", ListLength(head));
			system("pause");
			break;
		case 0:
			break;
		}
	}
	return 0;
}

