#include<iostream>
#include<string>


void Print(int value)
{
	std::cout << value << std::endl;
}

void Print(std::string value)
{
	std::cout << value << std::endl;
}

void Print(float value)
{
	std::cout << value << std::endl;
}

//以下使用模板来实现
template<typename T>	//这里选用typename作为模板类型(实际上用class是一样的，不过class通常让人想到类)，以T作为名字
void Print_t(T value)	//这里T的类型就是我们下面传入的参数的类型，下面的类型其实是隐式的得到的
{
	std::cout << value << std::endl;
}
//这个通过template定义的就是模板，它会在编译期被评估，所以这里实际上并不是真的代码，也不是真的函数，只有当我们实际调用它的时候，这些函数才被真的创建
//实际上大量的C++标准模板库同样完全使用了模板，模板并不仅仅局限于函数，也可以将类转换成一个模板

//template<int N>
//class Array
//{
//private:
//	int m_Array[N];//这里的N因为在栈上创建所以是要实际确定的，而这会在模板被调用时进行评估
//public:
//	int GetSize() const { return N; }
//};

template<typename T,int N>
class Array
{
private:
	T m_Array[N];//这样让这里类型是可变的
public:
	T GetSize() const { return N; }
};


int main()
{
	Print(5);
	Print("Hello");//如果这里要打印字符串就需要对Print进行重载
	Print(5.5f);//这就有了三个不同的函数，但它们除了输入参数类型不同其他都是相同的(因为cout可以接受所有的类型)
	
	std::cout << std::endl;

	Print_t<int>(5);//这里也可以使用<>来指定类型
	Print_t("Hello");
	Print_t(5.5f); //这里的参数类型C++的编译器会自动推导出类型T应该是什么,然后进行填空将T替换，这里即使传入一个返回值也是可以的
	//Print_t在不被调用时是不存在的，只有当我们调用时才会根据我们给定的模板参数来创建

	std::cout << std::endl;

	//基于类创建的
	Array<int,5> array;
	std::cout << array.GetSize() << std::endl;

	std::cin.get();
}

//模板，再Java或C#中有类似的叫做泛型，不过并不相同，模板要更加强大

//模板允许你定义一个可以根据你的用途进行编译的模板，相当于让编译器根据一套规则替你代码
