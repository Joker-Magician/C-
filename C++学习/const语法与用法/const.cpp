#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


class Entity
{
private:
	int m_X1, m_Y1;
	mutable int var;//mutable意思是可以被更改的(可变的)，这样在const方法中也是可以修改的
	int* m_X2, m_Y2;//这里仅表示m_X2是指针，但m_Y2是int型
public:
	int GetX1() const				//第三种用法，与变量无关，而是用在方法名的后面(只有类里才可以这样用)
	{	//m_X=2;这是不被允许的		//这意味这个方法不会修改任何实际的类，因此这里我们不能修改类的成员变量
		return m_X1;
	}

	void SetX1(int x)
	{
		m_X1 = x;
	}

	const int* const GetX2() const	//这表示我们返回了一个不能修改的指针，指针的内容也不能被修改
	{
		return m_X2;				//而且这个函数也承诺不会修改实际的Entity类
	}

	int GetX3()
	{	
		return m_X1;
	}

	int GetX4() const
	{
		var = 2;
		return m_X1;
	}
};

void PrintEntity(const Entity& e)
{
	//e=Entity();如果重新分配这个引用，实际上是在改变这个对象而不是其他的对象。这里没有像指针那样有指针本身和指针指向内容的区别，因为引用就是内容
	std::cout << e.GetX1() << std::endl;//这就是能修改的内容，引用就是那个Entity，因此不能修改Entity尽管是引用
	//std::cout << e.GetX3() << std::endl;这样访问是不被允许的，因为它不能确定方法是否能被修改，所以有时会可能会在一个类中看到有和没有const两个版本的方法

	
}


int main()
{
	const int MAX_AGE = 5;//const，首先从语法上指定了这个整数是一个常熟，以后不会去改动它

	int* a = new int;//，第一个在指针上的应用，在堆上创建这个整形，这样实际上就得到一个指针

	*a = 2;
	a = (int*)&MAX_AGE;//重新分配指针，为了绕开const限制，可以把它强制转换成int*类型(一般情况下不该这么做)
	std::cout << *a << std::endl;//这样可以做两件事，一是可以改变这个指针的内容(就是指针指向的内存内容)，二是可以改变指针指向的内存地址

	const int* a1 = new int;//这意味着不能再去修改指针指向的内容
	a1 = (int*)&MAX_AGE;
	//*a1 = 2;这样是报错的，a的值是实际内存地址的内容
	std::cout << *a1 << std::endl;//但是读取a的值是没有问题的

	int* const a2 = new int;//const第二种方式，可以改变指针指向的内容，但是不能把指针自身重新赋值让它指向其他东西
	//a2 = (int*)&MAX_AGE;这样是报错的
	*a2 = 2;
	std::cout << *a2 << std::endl;

	const int* const a3 = new int;//这就意味着既不能改变指针的内容，也不能改变指针本身让他指向别处
	//*a3 = 2;
	//a3 = (int*)&MAX_AGE;
	//a3 = nullptr;这些都是不被允许的
	std::cout << *a3 << std::endl;

	const int* a = new int;
	int const* a = new int;//这两种定义是一样的，关键在于是在*号的前面还是后面


	std::cin.get();
}

//可以把const叫做一个假的关键字，因为它实际上在生成代码的时候并没有做什么
//这个有点像类和结构体的可见性，是一种针对开发人员写代码的强制规则，为了让代码保持整洁的机制
//基本上const就是你做出承诺某些东西是不变的，是不会改动的
//但是这只是个承诺，实际上可以通过某些机制绕过或不遵守这个承诺