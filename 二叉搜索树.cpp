#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*����������*/
// 1.�ǿ������������м�ֵС������ڵ�ļ�ֵ
// 2.�ǿ������������м�ֵ��������ڵ�ļ�ֵ
// 3.�����������Ƕ���������
typedef int ElementType;
typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

//β�ݹ�ʵ��
Position Find(ElementType X, BinTree BST)
{
	if (!BST) return NULL;/*����ʧ��*/
	if (X > BST->Data)
		return Find(X, BST->Right);/*���������м�������*/
	else if (X < BST->Data)
		return Find(X, BST->Left);/*���������м�������*/
	else/* X == BST ->Data */
		return BST;/*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
}
//��β�ݹ麯����Ϊ����ѭ���ĵ�������
Position IterFind(ElementType X, BinTree BST)
{
	while (BST) {
		if (X > BST->Data)
			BST = BST->Right;/*���������ƶ�����������*/
		else if (X < BST->Data)
			BST = BST->Left;/*���������ƶ�����������*/
		else/* X == BST->Data */
			return BST;/*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
	}
	return NULL;/*����ʧ��*/
}
//������СԪ�صĵݹ麯��
Position FindMin(BinTree BST)
{
	if (!BST) return NULL;
	else if (!BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}
//�������Ԫ�صĵ�������
Position FindMax(BinTree BST)
{
	if (BST)
		while (BST->Right) BST = BST->Right;
	return BST;
}