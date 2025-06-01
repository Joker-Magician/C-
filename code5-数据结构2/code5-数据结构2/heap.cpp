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

int IsFull(MaxHeap H)
{

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


int main()
{


	return 0;
}


//采用二叉搜索树存储堆，这个树是一个完全二叉树