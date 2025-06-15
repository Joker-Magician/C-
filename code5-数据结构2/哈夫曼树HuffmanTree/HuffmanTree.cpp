#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
#define MinData -1

typedef HuffmanTree ElementType;

typedef struct TreeNode* HuffmanTree;
typedef struct HeapStruct* MinHeap;

struct TreeNode {
	int Weight;
	HuffmanTree Left, Right;
};

struct HeapStruct {
	ElementType* Elements;	/*�洢��Ԫ�ص�����*/
	int Size;				/*�ѵĵ�ǰԪ�ظ���*/
	int Capacity;			/*�ѵ��������*/
};


MinHeap BuildMinHeap(MinHeap H);
void Insert(MinHeap H, HuffmanTree T);
ElementType DeleteMin(MinHeap H);

HuffmanTree Huffman(MinHeap H)/*���������Ĺ�����ǰ�������С�Ѻϲ��γ�һ���µ���С��*/
{ /*����H->Size��Ȩֵ�Ѿ�����H->Elemenets[]->Weight��*/
	int i;
	HuffmanTree T;
	BuildMinHeap(H);/*��H->Elements[]��Ȩֵ����Ϊ��Сֵ*/
	for (i = 1; i < H->Size; i++) { /*��H->Size-1�κϲ�*/
		T = (TreeNode*)malloc(sizeof(struct TreeNode)); /*�����½ڵ�*/
		T->Left = DeleteMin(H); /*����С����ɾ��һ����㣬��Ϊ��T�����ӽڵ�*/
		T->Right = DeleteMin(H); /*����С����ɾ��һ����㣬��Ϊ��T�����ӽڵ�*/
		T->Weight = T->Left->Weight + T->Right->Weight; /*������Ȩֵ*/

		Insert(H, T);	/*����T������С��*/
	}
	T = DeleteMin(H);
	return T;
}


int main()
{

	return 0;
}

MinHeap BuildMinHeap(MinHeap H)
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType*)malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MinData;
	return H;
}

bool IsFull(MinHeap H)
{
	return (MinData == H->Size) ? true : false;
}

bool IsEmpty(MinHeap H)
{
	return (H->Size == 0) ? false : true;
}

void Insert(MinHeap H, ElementType item)
{
	int i;
	if (IsFull(H)) {
		printf("��С������");
		return;
	}
	i = ++H->Size;
	for (; H->Elements[i / 2] < item; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = item;
}

ElementType DeleteMin(MinHeap H)
{ 
	int Parent, Child;
	ElementType MinItem, temp;
	if (IsEmpty(H))
	{
		printf("������Ϊ��");
		return;
	}
	MinItem = H->Elements[1]; 
	temp = H->Elements[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent == Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
			Child++; 
		if (temp >= H->Elements[Child])
			break;
		else 
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MinItem;
}



/*
�����������ص�:
	û�ж�Ϊ1�Ľ��
	n��Ҷ�ӽڵ�Ĺ�����������2n-1�����
	���������������Ҷ�ӽڵ�������������������ǹ�������
	��ͬһȨֵ{w1,w2,......,wn},���ڲ�ͬ�������ù��������������ߵ�WPL(Ȩֵ��)����ͬ��
*/