//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
///*����������*/
//// 1.�ǿ������������м�ֵС������ڵ�ļ�ֵ
//// 2.�ǿ������������м�ֵ��������ڵ�ļ�ֵ
//// 3.�����������Ƕ���������
//typedef int ElementType;
//typedef struct TreeNode* BinTree;
//typedef BinTree Position;
//struct TreeNode {
//	ElementType Data;
//	BinTree Left;
//	BinTree Right;
//};
//
////β�ݹ�ʵ��
//Position Find(ElementType X, BinTree BST)
//{
//	if (!BST) return NULL;/*����ʧ��*/
//	if (X > BST->Data)
//		return Find(X, BST->Right);/*���������м�������*/
//	else if (X < BST->Data)
//		return Find(X, BST->Left);/*���������м�������*/
//	else/* X == BST ->Data */
//		return BST;/*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
//}
////��β�ݹ麯����Ϊ����ѭ���ĵ�������
//Position IterFind(ElementType X, BinTree BST)
//{
//	while (BST) {
//		if (X > BST->Data)
//			BST = BST->Right;/*���������ƶ�����������*/
//		else if (X < BST->Data)
//			BST = BST->Left;/*���������ƶ�����������*/
//		else/* X == BST->Data */
//			return BST;/*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
//	}
//	return NULL;/*����ʧ��*/
//}
////������СԪ�صĵݹ麯��
//Position FindMin(BinTree BST)
//{
//	if (!BST) return NULL;
//	else if (!BST->Left)
//		return BST;
//	else
//		return FindMin(BST->Left);
//}
////�������Ԫ�صĵ�������
//Position FindMax(BinTree BST)
//{
//	if (BST)
//		while (BST->Right) BST = BST->Right;
//	return BST;
//<<<<<<< HEAD
//}
//
////�����������Ĳ���
//BinTree Insert(ElementType X, BinTree BST)
//{
//	if (!BST) {/*��ԭ��Ϊ�գ����ɲ�����һ�����Ķ���������*/
//		BST = (BinTree)malloc(sizeof(struct TreeNode));
//		BST->Data = X;
//		BST->Left = BST->Right = NULL;
//	}
//	else if (X < BST->Data)					//��ʼ��Ҫ����Ԫ�ص�λ��
//		BST->Left = Insert(X, BST->Left);	//�ݹ����������
//	else if (X > BST->Data)
//		BST->Right = Insert(X, BST->Right);	//�ݹ����������
//	/* else X�Ѿ����ڣ�ʲô������*/
//	return BST;
//}
//
////������������ɾ��
//BinTree Delete(ElementType X, BinTree BST)
//{
//	Position Tmp;
//	if (!BST) printf("Ҫɾ����Ԫ��δ�ҵ�");
//	else if (X < BST->Data)
//		BST->Left = Delete(X, BST->Left);//�������ݹ�ɾ��
//	else if (X > BST->Data)
//		BST->Right = Delete(X, BST->Right);//�������ݹ�ɾ��
//	else /*�ҵ�Ҫɾ���Ľ��*/
//			if (BST->Left && BST->Right) {/*��ɾ����������������ӽڵ�*/
//			Tmp = FindMin(BST->Right);/*��������������С��Ԫ�����ɾ�����*/
//			BST->Data = Tmp->Data;
//			BST->Right = Delete(BST->Data, BST->Right);/*��ɾ��������������ɾ����СԪ��*/
//		}
//		else {/*��ɾ�������һ�������ӽڵ�*/
//			Tmp = BST;
//			if (!BST->Left)/*���Һ��ӻ����ӽڵ�*/
//				BST = BST->Right;
//			else if (!BST->Right)/*�����ӻ����ӽڵ�*/
//				BST = BST->Left;
//			free(Tmp);
//		}
//	return BST;
//}