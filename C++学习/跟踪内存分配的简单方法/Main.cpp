#include<iostream>
#include<memory>

void* operator new(size_t size)//这串代码的意思是不要使用标准库中的new操作符，链接器实际上会链接到这个函数中
{//因为new是通过这个函数运行的，所以我们很容易输入一些东西
	std::cout << "Allocating " << size << " bytes\n";//这样写的另一个好处是可以很容易在return设置一个断点

	return malloc(size);//因为不想影响程序运行，就只简单返回malloc(size)
}//返回一个void指针,它只是一个内存地址
//我们要做的是分配适当数量的内存，并返回一个指向该内存的指针

struct Object
{
	int x, y, z;
};

void operator delete(void* memory, size_t size)
{
	std::cout << "Allocating " << size << " bytes\n";//这样写的另一个好处是可以很容易在return设置一个断点

	free(memory);
}

int main()
{

	//Object* obj = new Object;//堆分配，本节重点就是如何检测这样的东西
	{
		//如果使用智能指针，不显示调用new会怎样
		std::unique_ptr<Object> obj = std::make_unique<Object>();
		//以上可以通过在operator new函数中插入一个断点，然后右击转入代码，精确地追踪这些内容分配的来源
	}

	std::string string = "Cherno";
	std::cin.get();
}


//