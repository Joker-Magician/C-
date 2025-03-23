//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
///*二叉搜索树*/
//// 1.非空左子树的所有键值小于其根节点的键值
//// 2.非空右子树的所有键值大于其根节点的键值
//// 3.左、右子树都是二叉搜索树
//typedef int ElementType;
//typedef struct TreeNode* BinTree;
//typedef BinTree Position;
//struct TreeNode {
//	ElementType Data;
//	BinTree Left;
//	BinTree Right;
//};
//
////尾递归实现
//Position Find(ElementType X, BinTree BST)
//{
//	if (!BST) return NULL;/*查找失败*/
//	if (X > BST->Data)
//		return Find(X, BST->Right);/*在右子树中继续查找*/
//	else if (X < BST->Data)
//		return Find(X, BST->Left);/*在左子树中继续查找*/
//	else/* X == BST ->Data */
//		return BST;/*查找成功，返回结点的找到结点的地址*/
//}
////将尾递归函数改为利用循环的迭代函数
//Position IterFind(ElementType X, BinTree BST)
//{
//	while (BST) {
//		if (X > BST->Data)
//			BST = BST->Right;/*向右子树移动，继续查找*/
//		else if (X < BST->Data)
//			BST = BST->Left;/*向左子树移动，继续查找*/
//		else/* X == BST->Data */
//			return BST;/*查找成功，返回结点的找到结点的地址*/
//	}
//	return NULL;/*查找失败*/
//}
////查找最小元素的递归函数
//Position FindMin(BinTree BST)
//{
//	if (!BST) return NULL;
//	else if (!BST->Left)
//		return BST;
//	else
//		return FindMin(BST->Left);
//}
////查找最大元素的迭代函数
//Position FindMax(BinTree BST)
//{
//	if (BST)
//		while (BST->Right) BST = BST->Right;
//	return BST;
//<<<<<<< HEAD
//}
//
////二叉搜索树的插入
//BinTree Insert(ElementType X, BinTree BST)
//{
//	if (!BST) {/*若原树为空，生成并返回一个结点的二叉搜索树*/
//		BST = (BinTree)malloc(sizeof(struct TreeNode));
//		BST->Data = X;
//		BST->Left = BST->Right = NULL;
//	}
//	else if (X < BST->Data)					//开始找要插入元素的位置
//		BST->Left = Insert(X, BST->Left);	//递归插入左子树
//	else if (X > BST->Data)
//		BST->Right = Insert(X, BST->Right);	//递归插入右子树
//	/* else X已经存在，什么都不做*/
//	return BST;
//}
//
////二叉搜索树的删除
//BinTree Delete(ElementType X, BinTree BST)
//{
//	Position Tmp;
//	if (!BST) printf("要删除的元素未找到");
//	else if (X < BST->Data)
//		BST->Left = Delete(X, BST->Left);//左子树递归删除
//	else if (X > BST->Data)
//		BST->Right = Delete(X, BST->Right);//右子树递归删除
//	else /*找到要删除的结点*/
//			if (BST->Left && BST->Right) {/*被删除结点有左右两个子节点*/
//			Tmp = FindMin(BST->Right);/*在右子树中找最小的元素填充删除结点*/
//			BST->Data = Tmp->Data;
//			BST->Right = Delete(BST->Data, BST->Right);/*在删除结点的右子树中删除最小元素*/
//		}
//		else {/*被删除结点有一个或无子节点*/
//			Tmp = BST;
//			if (!BST->Left)/*有右孩子或无子节点*/
//				BST = BST->Right;
//			else if (!BST->Right)/*有左孩子或无子节点*/
//				BST = BST->Left;
//			free(Tmp);
//		}
//	return BST;
//}