#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*二叉搜索树*/
// 1.非空左子树的所有键值小于其根节点的键值
// 2.非空右子树的所有键值大于其根节点的键值
// 3.左、右子树都是二叉搜索树
typedef int ElementType;
typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

//尾递归实现
Position Find(ElementType X, BinTree BST)
{
	if (!BST) return NULL;/*查找失败*/
	if (X > BST->Data)
		return Find(X, BST->Right);/*在右子树中继续查找*/
	else if (X < BST->Data)
		return Find(X, BST->Left);/*在左子树中继续查找*/
	else/* X == BST ->Data */
		return BST;/*查找成功，返回结点的找到结点的地址*/
}
//将尾递归函数改为利用循环的迭代函数
Position IterFind(ElementType X, BinTree BST)
{
	while (BST) {
		if (X > BST->Data)
			BST = BST->Right;/*向右子树移动，继续查找*/
		else if (X < BST->Data)
			BST = BST->Left;/*向左子树移动，继续查找*/
		else/* X == BST->Data */
			return BST;/*查找成功，返回结点的找到结点的地址*/
	}
	return NULL;/*查找失败*/
}
//查找最小元素的递归函数
Position FindMin(BinTree BST)
{
	if (!BST) return NULL;
	else if (!BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}
//查找最大元素的迭代函数
Position FindMax(BinTree BST)
{
	if (BST)
		while (BST->Right) BST = BST->Right;
	return BST;
}