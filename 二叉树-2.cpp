#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1		//因为NULL在传统C语言中代表0，而0也是下表的一部分，所以用Null表示-1为空

//使用静态链表的方式表示二叉树
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
	if ((R1 == Null) && (R2 == Null))/*均为空时*/
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0;/*其中一边为空*/
	if (T1[R1].Element != T2[R2].Element)
		return 0;/*两个根不同*/
	if ((T1[R1].Left = Null) && (T2[R2].Left == Null))/*都没有左子树*/
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null) && ((T1[T1[R1].Left].Element)) == (T2[T2[R2].Left].Element)))/*无需交换左右*/
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else/*无需交换左右*/
		return (Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));
}

//程序框架搭建
int main()
{
	Tree R1, R2;

	//建二叉树1
	R1 = BuildTree(T1);
	//建二叉树2
	R2 = BuildTree(T2);
	//判别是否同构并输出
	if (Isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");

	return 0;
}