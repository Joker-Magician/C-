#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	/*explicit*/ Entity(const std::string& name)
		:m_Name(name), m_Age(-1) {}//这里设为-1，意味着他是无效的，没有提供age

	/*explicit*/ Entity(int age)
		:m_Name("Unknown"), m_Age(age) {}
};

//如果你想要用一个整数构造一个Entity对象，那你必须显示的调用这个构造函数
//explicit会禁用隐式转换，explicit关键字放在构造函数前面,这样如果你想用一个整数构造一个Entity对象,那你就必须显示的调用这个构造函数

void PrintEntity(const Entity& entity)
{
	//Printing
}

int main()
{
	PrintEntity(22);
	PrintEntity(std::string("Cherno"));//用Entity("Cherno")也一样//这里("Cherno")不能正常工作是因为这个字符串不是std::sring类型的，它是一个char数组
//为了让这个能工作，C++需要做两次转化，一次是从const char数组到string，然后是从string转到Entity，但只允许做一次的隐式转换

	Entity a = std::string("Cherno");// a("Cherno")
	Entity b = 22;//b(22)这两种实例化的方法是相同的
//这里b看起来被赋值了一个整形，其实被转换成了Entity型，这就是隐式转换或隐式构造函数
	std::cin.get();
}

//关于两种类型的转化C++编译器允许一种隐式的转化