#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Entity
{
public:
	void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr		//重载->操作符，并在自定义的类中使用它
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		:m_Obj(entity)
	{
	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator->()
	{
		return m_Obj;
	}

	const Entity* operator->()const
	{
		return m_Obj;
	}
};

struct Vector3
{
	float x, y, z;//float类型一个占四个字节，因为x是第一个则偏移量为0，y的偏移量为4，z的偏移量为8
};

int main()
{
	Entity e;
	e.Print();

	Entity* ptr = &e;
	Entity& entity = *ptr;//这里需要使用*逆向引用ptr(解引用)，然后用entity替换这个才可以
	entity.Print();//注意这里不用使用ptr.Print()，因为ptr是一个指针，也就是一个数值(不是对象，也就不能调用方法)
	(*ptr).Print();//也可以这样解引用

	ptr->Print();//使用箭头操作符可以来替换这些，这实际上就相当与解引用了Entity指针

	//重载->及用法
	ScopedPtr entity1 = new Entity();//这里也可以写出Entity* entity1 =new Entity()
	const ScopedPtr entity1 = new Entity();//z这是const版本
	entity1->Print();
	//在自己的类型中，定义自己的构造函数，并实现自动化

	//利用箭头操作符来获取内存中某个变量的偏移量
	int offset = (int)&((Vector3*)nullptr)->x;//将0转换为Vector3类型,然后用箭头来访问x将会得到这些内存的布局，在前面加上&来获取x的内存地址，
//然后得到这个x的偏移量(从0开始,0也可以写成nullptr),最后把它转换成int类型，让它等于offset	
	std::cout << offset << std::endl;


	std::cin.get();
}