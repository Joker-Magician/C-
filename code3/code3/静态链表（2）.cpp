//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//#define MaxSize 11
//typedef char ElementType[8];
//
//typedef struct _node {
//	ElementType Data;		//节点中的数据
//	int curr;				//下一个节点的下标（相当于指针）
//}NodeType;					//节点类型
//
//NodeType space[MaxSize];
//
//void insert(NodeType* space, ElementType e, int a, int q);
//void search(ElementType e, NodeType* space);
//void show(NodeType* space);
//void Delete(NodeType* space, int a, int q);
//
//int main()
//{
//	const char* str1 = "insert";
//	const char* str2 = "delete";
//	const char* str3 = "search";
//	const char* str4 = "show";
//	NodeType space[MaxSize];
//	int q = 0;
//	memset(space, 0, sizeof(space));
//	for (int i = 0; i < MaxSize - 1; i++)
//	{
//		space[i].curr = i + 1;
//
//	}
//	space[MaxSize - 1].curr = 0;
//	//建一个头结点
//	space[0].curr = 2;
//	space[1].curr = 0;
//	char str[10];
//	ElementType e;
//	int a;
//	while (scanf("%s", str) != EOF)
//	{
//		if (strcmp(str, str1) == 0)
//		{
//			scanf("%d%s", &a, e);
//
//			insert(space, e, a, q);
//			if (a < q + 2)
//				q = q + 1;
//		}
//		if (strcmp(str, str2) == 0)
//		{
//			scanf("%d", &a);
//			Delete(space, a, q);
//			if (a < q + 1)
//				q = q - 1;
//		}
//		if (strcmp(str, str3) == 0)
//		{
//			scanf("%s", e);
//			search(e, space);
//		}
//		if (strcmp(str, str4) == 0)
//		{
//			show(space);
//		}
//	}
//	return 0;
//}
//
//
//void insert(NodeType* space, ElementType e, int a,int q)
//{
//	if (a < q + 2) {
//		int t = 0;
//		int k = 1;
//		for (int i = 0; i < a - 1; i++) {
//			k = space[k].curr;
//		}
//		t = space[0].curr;
//		strcpy(space[t].Data, e);
//		space[0].curr = space[t].curr;
//		space[t].curr = space[k].curr;
//		space[k].curr = t;
//	}
//}
//
//void search(ElementType e, NodeType* space)
//{
//	int i;
//	i = space[1].curr;
//	while (i && strcmp(space[i].Data, e)) {
//		i = space[i].curr;
//	}
//	if (i != 0) {
//		printf("%2d\n", i);
//		printf("********************\n");
//	}
//}
//void show(NodeType* space)
//{
//	for (int i = 0; i < MaxSize;i++) {
//		printf("%-8s%2d\n", space[i].Data, space[i].curr);
//	}
//	printf("********************\n");
//}
//void Delete(NodeType* space, int a, int q)
//{
//	if (a < q + 1)
//	{
//		int k = 1;
//		int t;
//		for (int j = 0; j < a - 1; j++)
//		{
//			k = space[k].curr;
//		}
//		t = space[k].curr;
//		space[k].curr = space[t].curr;
//		//释放空间
//		space[t].curr = space[0].curr;
//		space[0].curr = t;
//	}
//}