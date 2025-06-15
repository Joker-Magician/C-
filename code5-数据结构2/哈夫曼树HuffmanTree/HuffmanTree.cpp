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
	ElementType* Elements;	/*存储堆元素的数组*/
	int Size;				/*堆的当前元素个数*/
	int Capacity;			/*堆的最大容量*/
};


MinHeap BuildMinHeap(MinHeap H);
void Insert(MinHeap H, HuffmanTree T);
ElementType DeleteMin(MinHeap H);

HuffmanTree Huffman(MinHeap H)/*哈夫曼树的构造就是把两个最小堆合并形成一个新的最小堆*/
{ /*假设H->Size个权值已经存在H->Elemenets[]->Weight里*/
	int i;
	HuffmanTree T;
	BuildMinHeap(H);/*将H->Elements[]按权值调整为最小值*/
	for (i = 1; i < H->Size; i++) { /*做H->Size-1次合并*/
		T = (TreeNode*)malloc(sizeof(struct TreeNode)); /*建立新节点*/
		T->Left = DeleteMin(H); /*从最小堆中删除一个结点，作为新T的左子节点*/
		T->Right = DeleteMin(H); /*从最小堆中删除一个结点，作为新T的右子节点*/
		T->Weight = T->Left->Weight + T->Right->Weight; /*计算新权值*/

		Insert(H, T);	/*将新T插入最小堆*/
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
		printf("最小堆已满");
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
		printf("最大堆已为空");
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
哈夫曼树的特点:
	没有度为1的结点
	n个叶子节点的哈夫曼树共有2n-1个结点
	哈夫曼树的任意非叶子节点的左右子树交换后仍是哈夫曼树
	对同一权值{w1,w2,......,wn},存在不同构的两棵哈夫曼树，但二者的WPL(权值和)是相同的
*/