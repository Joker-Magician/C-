#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#define MaxSize 100//��������Ԫ�ص�������
///*���е�˳��洢�ṹ ͨ����һ��һά�����һ����¼����ͷԪ��λ�õ�
//����front�Լ�һ����¼����βԪ��λ�õı���rear���*/
//
//struct QNode {
//	int Data[MaxSize];
//	int rear;
//	int front;
//};
//typedef struct QNode* Queue;
//
//void AddQ(Queue PtrQ, int item)
//{
//	if ((PtrQ->rear + 1) % MaxSize == PtrQ->front) {
//		printf("������");
//		return;
//	}
//	PtrQ->rear = (PtrQ->rear + 1) % MaxSize;//ͨ��ȡ�๹��ѭ������
//	PtrQ->Data[PtrQ->rear] = item;
//}//�����
//int Delete(Queue PtrQ)
//{
//	if (PtrQ->front == PtrQ->rear) {
//		printf("���п�");
//		return -1;
//	}
//	else {
//		PtrQ->front = (PtrQ->front + 1) % MaxSize;
//		return PtrQ->Data[PtrQ->front];
//	}
//}//������
//
//int main()
//{
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define MaxSize 100
///*���е���ʽ�洢�ṹ ������һ��������ʵ�֣������ɾ�������ֱ���
//�������ͷ����*/
//
//struct Node {
//	int Data;
//	struct Node* Next;
//};
//struct QNode {  /*�����нṹ*/
//	struct Node* rear;/*ָ���β�ڵ�*/
//	struct Node* front;/*ָ���ͷ�ڵ�*/
//};
//typedef struct QNode* Queue;
//Queue PtrQ;
//
//int Delete(Queue PtrQ)
//{
//	struct Node* FrontCell;
//	int FrontElem;
//
//	if (PtrQ->front == NULL) {
//		printf("���п�"); return -1;//���ش�����Ϣ
//	}
//	FrontCell = PtrQ->front;
//	if (PtrQ->front == PtrQ->rear)
//		PtrQ->front = PtrQ->rear = NULL;//�б�����Ƿ�ֻ��һ��Ԫ��
//	else
//		PtrQ->front = PtrQ->front->Next = NULL;
//	FrontElem = FrontCell->Data;
//	free(FrontCell);
//	return FrontElem;
//}//�����