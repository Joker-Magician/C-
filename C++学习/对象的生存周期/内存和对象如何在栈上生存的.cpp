#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()//析构函数
	{
		std::cout << "Dstroyed Entity" << std::endl;
	}
};

//int* CreateArray()//错误示范：不要返回局部变量的指针或引用
//{
//	int array[50];
//	return array;//一旦离开这个函数这个在栈上内存就会被回收
//}

int* CreateArray(int* arry)
{
	
}

class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr)
		: m_Ptr(ptr)
	{

	}

	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

int main()
{
	int array[50];
	CreateArray(array);//这样是可行的 

	//int* a = CreateArray();//这样调用是不行的

	{
		Entity e;//这样实在栈上创建，这样写它会调用默认的构造函数
		//Entity* e = new Entity();在堆上创建的Entity永远不会被销毁
	}//在栈上创建当离开这个作用域是被销毁，内存被释放，调用析构函数输出"Destroyed Entity!"
//作用域，作用域可以是任何东西，包括函数作用域等

	{
		ScopedPtr e = new Entity;//隐式转换，可写为e(new Entity()),这样会默认使用构造函数
	}//在离开这个作用域时，e被销毁会调用析构函数，后面Entity指针也会被删除，这样就实现了smart_ptr(智能指针)、unique_ptr(作用域指针)最基本的功能
//这样实现了自动构造、自动析构等功能
	std::cin.get();
}