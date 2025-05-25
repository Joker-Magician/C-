#include<iostream>
#include<memory>

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;//表示总共分配的内存
	uint32_t TotalFreed = 0;//释放的内存

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }//当前使用的内存
};

static AllocationMetrics s_AllocationMetrics;//创建一个静态实例

void* operator new(size_t size)//这串代码的意思是不要使用标准库中的new操作符，链接器实际上会链接到这个函数中
{//因为new是通过这个函数运行的，所以我们很容易输入一些东西
	//std::cout << "Allocating " << size << " bytes\n";//这样写的另一个好处是可以很容易在return设置一个断点

	s_AllocationMetrics.TotalFreed += size;

	return malloc(size);//因为不想影响程序运行，就只简单返回malloc(size)
}//返回一个void指针,它只是一个内存地址
//我们要做的是分配适当数量的内存，并返回一个指向该内存的指针

void operator delete(void* memory, size_t size)//通过重载的delete来释放重载new的内存，并且可以同添加size的函数名，通过覆盖这个特定的函数签名来获取该信息
{
	//std::cout << "Freeing " << size << " bytes\n";//这样写的另一个好处是可以很容易在return设置一个断点，然后观察到它实际上是在某一作用域的析构函数，删除了其原始指针  


	free(memory);
}
//通过上面两个函数，我们就可以创建内存分配跟踪器，可以确切的知道有多少内存被使用，有多少内存被分配，有多少内存被释放

struct Object
{
	int x, y, z;
};

static void PrintMemoryUsage()
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main()
{

	////Object* obj = new Object;//堆分配，本节重点就是如何检测这样的东西
	//{
	//	//如果使用智能指针，不显示调用new会怎样
	//	std::unique_ptr<Object> obj = std::make_unique<Object>();
	//	//以上可以通过在operator new函数中插入一个断点，然后右击转入代码，精确地追踪这些内容分配的来源
	//}//这就可通过重载delete的来释放了，它实际上是这个unique_ptr的析构函数，实际上是删除了底层的原始指针


	//std::string string = "Cherno";

	PrintMemoryUsage();
	std::string string = "Cherno";
	PrintMemoryUsage();
	{
		std::unique_ptr<Object> obj = std::make_unique<Object>();
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

	std::cin.get();
}
