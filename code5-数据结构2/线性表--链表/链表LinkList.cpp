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


/*初始化链表*/
void InitList(linklist* L)
{
	*L = (linklist)malloc(sizeof(Node));/*为头结点分配存储空间*/
	(*L)->next = NULL;
}

/*创建链表*/
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
/*求链表长度*/
int	ListLength(linklist L) /*L为带头结点的单链表*/
{
	Node* p;
	int j;
	p = L->next;
	j = 0;   /*用来存放单链表的长度*/
	while (p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

/*输出链表中的所有元素*/
void OutList(linklist L) /*L为带头结点的单链表*/
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

/*在带头结点的单链表L中查找第i个结点，若找到(1≤i≤n)，则返回该结点的存储位置;  否则返回NULL */
Node* GetData(linklist  L, int i)
{
	int j;
	Node* p;
	p = L;
	j = 0;       /* 从头结点开始扫描 */
	while ((p->next != NULL) && (j < i))
	{
		p = p->next;
		j++;   /* 扫描下一结点 */
	}        /* 已扫描结点计数器 */
	if (i == j)
		return p;   /* 找到了第i个结点 */
	else
		return NULL;   /* 找不到，i≤0或i>n */
}
//按值查找
Node* Locate(linklist L, int key)
{
	Node* p;
	p = L->next;   /* 从表中第一个结点比较 */
	while (p != NULL)
	{
		if (p->data != key)
			p = p->next;
		else  break;     /* 找到结点key，退出循环 */
	}
	return p;
}

void InsList(linklist L, int e)
{  /*在带头结点的单链表L中插入值为e的新结点。 */
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
/*在带头结点的单链表L中删除值为e的元素，并保存其位置到变量*pos中*/
{
	Node* pre, * r;
	int k = 0; pre = L;

	if (pre->next == NULL)
		return ERROR;

	while ((pre->next != NULL) && (pre->next->data != e)) /*寻找被删除结点的前驱结点*/
	{
		pre = pre->next;
		k = k + 1;
	}
	if (pre->next == NULL)    /*未找到*/
	{
		return ERROR;
	}
	r = pre->next;
	pre->next = r->next;    /*删除结点r*/
	free(r);    /*释放被删除的结点所占的内存空间*/
	*pos = k + 1;
	return OK;
}

void Mergelinklist(linklist LA, linklist LB)
/*将递增有序的单链表LA和LB合并成一个递增有序的单链表*/
{
	Node* pa, * pb;
	linklist r;
	/*pa和pb分别指向两个单链表LA和LB中的第一个结点*/
	pa = LA->next;
	pb = LB->next;

	r = LA;
	r->next = NULL;/*r指向空表*/

	/*当两个表中均未处理完时，比较选择将较小值结点插入到新表中。*/
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
	if (pa) /*若表LA未完，将表LA中后续元素链到新表表尾*/
		r->next = pa;
	else	 /*否则将表LB中后续元素链到新表表尾*/
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
		printf("1-----链表输出!\n");
		printf("2-----按序号查找!\n");
		printf("3-----按值查找!\n");
		printf("4-----插入!\n");
		printf("5-----删除!\n");
		printf("6-----合并!\n");
		printf("7-----求链表长度!\n");
		printf("0-----退出!\n");
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
			printf("请输入要查询的序号:");
			scanf("%d", &pos);
			p = GetData(head, pos);
			if (p != NULL)
				printf("找到了%d号元素%d!\n", pos, p->data);
			else
				printf("未找到%d号元素!\n", pos);
			system("pause");
			break;
		case 3:
			printf("请输入要查找的元素:");
			scanf("%d", &x);
			p = Locate(head, x);
			if (p != NULL)
				printf("找到了%d!\n", p->data);
			else
				printf("未找到%d!\n", x);
			system("pause");
			break;
		case 4:
			printf("请输入要插入的元素:");
			scanf("%d", &x);
			InsList(head, x);
			system("pause");
			break;
		case 5:
			printf("请输入要删除的元素:");
			scanf("%d", &x);
			if (DelList(head, &pos, x) == OK)//相同的值，只删除第一个
				printf("已删除第%d个元素,值为%d\n", pos, x);
			else
				printf("删除失败\n");
			system("pause");
			break;
		case 6:
			printf("创建第二个单链表:\n");
			B = CreateList();

			printf("第一个链表中的元素为:\n");
			OutList(head);
			printf("第二个链表中的元素为:\n");
			OutList(B);

			Mergelinklist(head, B);
			printf("合并后链表中的元素为:\n");
			OutList(head);
			system("pause");
			break;
		case 7:
			printf("链表长度为:%d\n", ListLength(head));
			system("pause");
			break;
		case 0:
			break;
		}
	}
	return 0;
}

