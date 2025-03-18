#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1		//��ΪNULL�ڴ�ͳC�����д���0����0Ҳ���±��һ���֣�������Null��ʾ-1Ϊ��

//ʹ�þ�̬����ķ�ʽ��ʾ������
struct TreeNode {
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
	Tree N,Root;
	int check[MaxTree],i=0;
	ElementType cl, cr;
	scanf("%d\n", &N);
	if (N) {
		for (i = 0; i < N; i++) check[i] = 0;
		for (i = 0; i < N; i++) {
			scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
			if (cl != '-') {
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else T[i].Right = Null;
		}
		for (i = 0; i < N; i++) 
			if (!check[i]) break;
		Root = i;
	}
	return Root;
}

int Isomorphic(Tree R1, Tree R2)
{
	if ((R1 == Null) && (R2 == Null))/*��Ϊ��ʱ*/
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0;/*����һ��Ϊ��*/
	if (T1[R1].Element != T2[R2].Element)
		return 0;/*��������ͬ*/
	if ((T1[R1].Left = Null) && (T2[R2].Left == Null))/*��û��������*/
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null) && ((T1[T1[R1].Left].Element)) == (T2[T2[R2].Left].Element)))/*���轻������*/
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else/*���轻������*/
		return (Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));
}

//�����ܴ
int main()
{
	Tree R1, R2;

	//��������1
	R1 = BuildTree(T1);
	//��������2
	R2 = BuildTree(T2);
	//�б��Ƿ�ͬ�������
	if (Isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");

	return 0;
}