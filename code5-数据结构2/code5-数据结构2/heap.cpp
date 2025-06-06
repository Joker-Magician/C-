#define _CRT_SECURE_NO_WARNINGS
//�ѣ������ȶ��У�Priority Queue),����Ķ��У�ȡ��Ԫ�ص�˳��������Ԫ�ص�����Ȩ(�ؼ���)��С��������Ԫ�ؽ�����е��Ⱥ�˳��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxData 100

typedef int ElementType;

typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
	ElementType* Elements;	/*�洢��Ԫ�ص�����*/
	int Size;				/*�ѵĵ�ǰԪ�ظ���*/
	int Capacity;			/*�ѵ��������*/
};

MaxHeap Creat(int MaxSize)
{		/*��������ΪMaxSize�Ŀյ�����(�󶥶�)*/
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType*)malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;
	/*���塰�ڱ���Ϊ���ڶ������п���Ԫ�ص�ֵ���Ա����Ժ�������*/
	return H;
}

bool IsFull(MaxHeap H)
{
	return (MaxData == H->Size) ? true : false;
}

bool IsEmpty(MaxHeap H)
{
	return (H->Size == 0) ? false : true;
}

void Insert(MaxHeap H, ElementType item)
{	/* ��Ԫ��item��������H,����H->Elements[0]�Ѿ�����Ϊ�ڱ� */
	int i;
	if (IsFull(H))
	{
		printf("��������");
		return;
	}
	i = ++H->Size;/* iָ��������е����һ��Ԫ�ص�λ�� */
	for (; H->Elements[i / 2] < item; i /= 2)
		H->Elements[i] = H->Elements[i / 2];/* ���¹��˽ڵ� */
	H->Elements[i] = item;	/* ��item���� */
}

ElementType Delete( MaxHeap H )
{/*������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ���ڵ�*/
	int Parent, Child;
	ElementType MaxItem, temp;
	if (IsEmpty(H))
	{
		printf("������Ϊ��");
		return;
	}
	MaxItem = H->Elements[1];/*ȡ�����ڵ����ֵ*/
	/*�����������һ��Ԫ�شӸ��ڵ㿪ʼ���Ϲ����²�ڵ�*/
	temp = H->Elements[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent == Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
			Child++;	/*Childָ�������ӽڵ�Ľϴ���*/
		if (temp >= H->Elements[Child])
			break;
		else  /*�ƶ�tempԪ�ص���һ��*/
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}


int main()
{


	return 0;
}


//���ö����������洢�ѣ��������һ����ȫ������