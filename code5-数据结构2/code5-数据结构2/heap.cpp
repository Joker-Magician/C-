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

int IsFull(MaxHeap H)
{

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


int main()
{


	return 0;
}


//���ö����������洢�ѣ��������һ����ȫ������