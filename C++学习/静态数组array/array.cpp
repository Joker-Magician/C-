#include<iostream>
#include<array>//右击转到文档可以直接查看比较重要的array的源代码

void PrintArray(const std::array<int,5>& data)//这里显式的直接传入了5，如果在不知道的情况下可以使用模板
{
	for (int i = 0; i < data.size(); i++)
		std::cout << data[i] << std::endl;
}
//下面为参考例子
template <int N>
void PrintArrayNew(const std::array<int, N>& arr)
{
	for (int i = 0; i < arr.size() :i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

void PrintArrayOld(int* array, unsigned int size)
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << std::endl;
}

int main()
{
	//std::array与C语言的风格是一致的
	std::array<int, 5>data;
	data[0] = 2;
	data[4] = 1;
	data[5] = 2;
//使用array相较于传统方式可以调用类似sort等SLT库的内容做事
//当处于debug模式下，array还有一个边界检查，当在array中直接data[5] = 2会显示报错，传统C语言不会，实际上这样做也是可以的，
	//它只会覆盖你实际上并不拥有的数据，你还没有分配的数据

	int dataOld[5];
	dataOld[0] = 0;
	dataOld[5] = 0;

//这两种使用数组在内存中的存储方式是一样的，都是存储存储在栈上的
//二创建std::vector类的地方是在堆上创建底层数据存储的

	std::cin.get();
}

//静态数组即是大小固定的数组
//新的特性不是一定要使用，他们必须做的更好或给我们带来性能上的提升或类似的东西来让我们使用它
//即使新的特性让我们的代码看起来更好，却更慢，那我们没有理由去使用它