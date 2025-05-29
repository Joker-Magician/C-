#include<iostream>

class String
{
public:
	String() = default;
};

int main()
{

	std::cin.get();
}

//移动语义能够将一个对象移动到另一个对象上，这其中涉及到了两个关键部分，其中之一是std::move,另一个是move assignment operator(移动赋值操作符)，这是一个赋值操作符，当我们想把一个对象移动到一个已有的对象中时
//在移动语义中的内容谈到了移动构造函数，但本部分将会谈到如果我们想要将现有对象移动到另一个对象中，而不是构造一个新对象，会发生什么