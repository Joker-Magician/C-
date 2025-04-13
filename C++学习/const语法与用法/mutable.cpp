#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

//mutable实际上有两种不同的用法，一种是和const一起使用(这种战=占了绝大多数情况)，另一种是在lambda表达式中使用
//mutable即意思是可以改变的

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCout = 0;//与const的一起的用法
public:
	const std::string& GetName() const 
	{
		m_DebugCout++;
		return m_Name;
	}
};

int main()
{
	const Entity e;
	e.GetName();

	int x = 8;
	auto f = [=]() mutable//想要传x可以同引用传递这个变量（如f=[&x]()），也可以通过=对变量进行传值传递
	{
		/*int y = x;
		y++;这样是允许的,但有点乱*/
		x++;//上面使用了mutable这里就允许自增了，实际上和上面的工作原理是一致的，不过看起来更加简洁
		std::cout << x << std::endl;
	}

	f();
//基本上来说,lambda就像一个一次性的小函数，可以写出来并赋值给一个变量
	//这里x=8,因为是通过传值传递的
	std::cin.get();
}