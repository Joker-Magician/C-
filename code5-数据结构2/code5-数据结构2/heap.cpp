#define _CRT_SECURE_NO_WARNINGS
//堆，即优先队列（Priority Queue),特殊的队列，取出元素的顺序是依照元素的优先权(关键字)大小，而不是元素进入队列的先后顺序
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxData 100

typedef int ElementType;

typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
	ElementType* Elements;	/*存储堆元素的数组*/
	int Size;				/*堆的当前元素个数*/
	int Capacity;			/*堆的最大容量*/
};

MaxHeap Creat(int MaxSize)
{		/*创建容易为MaxSize的空的最大堆(大顶堆)*/
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType*)malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;
	/*定义“哨兵”为大于堆中所有可能元素的值，以便于以后更快操作*/
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
{	/* 将元素item插入最大堆H,其中H->Elements[0]已经定义为哨兵 */
	int i;
	if (IsFull(H))
	{
		printf("最大堆已满");
		return;
	}
	i = ++H->Size;/* i指向插入后堆中的最后一个元素的位置 */
	for (; H->Elements[i / 2] < item; i /= 2)
		H->Elements[i] = H->Elements[i / 2];/* 向下过滤节点 */
	H->Elements[i] = item;	/* 将item插入 */
}

ElementType Delete( MaxHeap H )
{/*从最大堆H中取出键值为最大的元素，并删除一个节点*/
	int Parent, Child;
	ElementType MaxItem, temp;
	if (IsEmpty(H))
	{
		printf("最大堆已为空");
		return;
	}
	MaxItem = H->Elements[1];/*取出根节点最大值*/
	/*用最大堆中最后一个元素从根节点开始向上过滤下层节点*/
	temp = H->Elements[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent == Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
			Child++;	/*Child指向左右子节点的较大者*/
		if (temp >= H->Elements[Child])
			break;
		else  /*移动temp元素到下一层*/
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}


int main()
{


	return 0;
}


//采用二叉搜索树存储堆，这个树是一个完全二叉树