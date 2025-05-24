#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct TreeNode* Tree;
struct TreeNode {
	int v;
	Tree Left, Right;
	int flag;//作为有没有被访问过的标记
};

Tree MakeTree(int N);
Tree NewNode(int V);
int check(Tree T, int V);

Tree Insert(Tree T, int V);
void ResetT(Tree T);
void FreeTree(Tree T);

int main()
{/*对每组数据*/
	//读入N和L
	//根据第一行序列建树T
	//依据树T分别判别后面的L个序列是否能与T形成同一搜索树并输出结果

	int N, L,i;
	Tree T;

	scanf("%d", &N);
	while (N) {
		scanf("%d", &L);
		T = MakeTree(N);
		for (i = 0; i < L; i++) {
			if (Judge(T, N)) printf("Yes\n");
			else printf("No\n");
			ResetT(T);	/*清除T中的标记flag*/
		}
		FreeTree(T);
		scanf("%d", &N);
	}

	return 0;
}

Tree MakeTree(int N)
{
	Tree T;
	int i, V;
	scanf("%d", &V);
	for (i = 1; i < N; i++) {
		scanf("%d", &V);
		T = Insert(T, V);
	}
	return T;
}
Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}
Tree Insert(Tree T, int V)
{
	if (!T) T = NewNode(V);
	else {
		if (V > T->v)
			T->Right = Insert(T->Right, V);
		else
			T->Left = Insert(T->Left, V);
	}
	return T;
}
int check(Tree T, int V)
{
	if (T->flag) {
		if (V < T->v) return check(T->Left, V);
		else if (V > T->v) return check(T->Right, V);
		else return 0;
	}
	else {
		if (V == T->v) {
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
}

int Judage_bug(Tree T, int N)		//因为该函数当发现与T不一致时会直接退出
{									//导致把后面的数看成一起的导致错误
	int i, V;

	scanf("%d", &V);
	if (V != T->v) return 0;
	else T->flag = 1;

	for (i = 0; i < N; i++) {
		scanf("%d", &V);
		if (!check(T, V)) return 0;
	}

	return 1;
}
int Judge(Tree T, int N)
{
	int i, V, flag = 0;
	scanf("%d", &V);
	if (V != T->v) flag = 1;
	else T->flag = 1;
	for (i = 1; i < N; i++) {
		scanf("%d", &V);
		if ((!flag) && (!check(T, V))) flag = 1;
	}
	if (flag) return 1;
	else return 1;
}

void ResetT(Tree T)	/*清楚T中各节点的flag标记*/
{
	if (T->Left) ResetT(T->Left);
	if (T->Right) ResetT(T->Right);
	T->flag = 0;
}
void FreeTree(Tree T)	/*释放T的空间*/
{
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}