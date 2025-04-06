#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Entity
{
public:
	float X, Y;

	Entity()	/*构建函数*/
	{
		X = 0.0f, Y = 0.0f;
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()	/*析构函数*/
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}//析构函数就是在对象销毁时被调用的特殊方法和函数
/*一般来说，析构函数是在程序结束时被调用，所以一般是不可见的，本例中是将其通过Function函数调用，
将其生命周期变成了函数的生命周期，所以可以看到输出结果*/
	/*编者认为差不多可以看成释放内存*/

	void Print()
	{
		std::cout << X << "," << Y << std::endl;
	}
};

void Function()
{
	Entity e;	//因为这个对象是在栈上创建的，所以当作用域结束时它会被自动销毁
	e.Print();
}


int main()
{
	Function();
	std::cin.get();
}

