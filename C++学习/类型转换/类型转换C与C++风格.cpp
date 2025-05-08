#include<iostream>

class Base
{
public:
	Base() { }
	virtual ~Base() { }
};

class Derived : public Base
{
public:
	Derived() { }
	~Derived() { }
};

class AnotherClass : public Base
{
public:
	AnotherClass() { }
	~AnotherClass() { }
};

int main()
{
//C语言风格类型转换，在圆括号中指定强制转换的类型，然后是我们要强制转换的变量
	double value = 5.25;
	double a1 = value + 5.3;
	std::cout << a1 << std::endl;//10.55
	double a2 = (int)value + 5.3;//显式转换
	std::cout << a2 << std::endl;//10.3

//C++语言风格类型转换，一共有static_cast、reinterpret_cast、dynamic_cast、const_cast四种主要的cast
	double s1 = static_cast<int>(value) + 5.3;
	/*double s2 = reinterpret_cast<AnotherClass*>(&value) + 5.3;这里C++的类型双关就会做一个检查，说明你的错误在哪里，而在C语言中则时看不出来的*/
	

	//需要认识到的是，它们不做任何C风格类型转换不能做的事情，它们可能会做其他的事情，但实际结果也只是一个成功的类型转换而已，C风格的强制转换可以实现所有这些，
//这并不是添加新功能，它只是添加了一些语法糖到你的代码中

/*例如，我们将实际执行一个检查，如果转换不成功，可能返回NULL,所以它做了额外的事情，这也意味着它实际上会让你的代码慢下来。但在大多数情况下，C++风格的类型转换也不做额外的事情，
它们只是放进去英语单词，例如static_cast，意思是静态类型转换，在静态类型转换的情况下，它们还会做一些其他的编译时检查，看看这种转换是否真的可能*/
/*reinterpret_cast也一样，就像是我们说过的类型双关用英语语言表达出来一样，reinterpret_cast的意思是我把这段内存重新解释成别的东西 */
/*const_cast,移除或者添加变量的const限定*/

/*搞这么多cast的好处是，除了可能收到的那些编译时检查之外，还可以在代码库中搜索它们
C语言风格则不能真正的搜索到，而在这里用英文单词可以很容易去搜索*/

	Derived* derived = new Derived();

	Base* base = derived;//根据这个代码我们实际知道base是Derived类的一个实例，但我们假装不知道

	AnotherClass* ac1 = dynamic_cast<AnotherClass*>(base);//如果这里使用static_cast是没问题的，这样和用C语言的类型转换是一样的，就是直接给了那个值，但以后可能会出问题，因为你知道ac不是AnotherClaee类实例，而是Derived类的实例
	if (ac1)//这里ac是NULL，因为ac是Derived类不是AnotherClass
	{

	}
	Derived* ac2 = dynamic_cast<Derived*>(base);
	if (ac2)//这样这里的指针是有效的，因为这个转换是成功的
	{

	}
/*所以dynamic_cast是一个很好的方法来检查转换是否成功，它与运行时类型信息RTTI(runtime type information)密切联系*/

	std::cin.get();
}

//C++是一个强类型语言，如果把一个东西设为int，就不能把它当成double或float等相似的东西来使用，我必须坚持我的类型，除非有一个简单的隐式转换，这意味着C++知道如何在这两种类型之间转换，并且没有数据损失，这就是隐式转换
//或者有一个显示转换，我们告诉C++，嘿，你需要把这个类型转换成这个类型

// cast 分为 static_cast dynamic_cast reinterpret_cast const_cast
// static_cast static_cast 用于进行比较“自然”和低风险的转换，如整型和浮点型、字符型之间的互相转换, 不能用于指针类型的强制转换
// reinterpret_cast 用于进行各种不同类型的指针之间强制转换
// const_cast 仅用于进行去除 const 属性的转换
// dynamic_cast 不检查转换安全性，仅运行时检查，如果不能转换，返回null