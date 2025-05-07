#include<iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructed\n"; }
	/*~Base() { std::cout << "Base Destructed\n"; }*/	//直接调用时，它不知道调用的析构函数可能有另一个析构函数，因为它没有被标记为虚函数
	virtual ~Base() { std::cout << "Base Destructed\n"; }
};	//标记为virtual，意味着C++知道可能会有一个方法，在层次结构下的某种重写的方法，因为在普通方法前面标记为virtual，那么它就可以被覆写，这意味着要做虚函数表这样的设置
//虚析构函数的意思不是覆写析构函数，而是加上一个析构函数。换句话说，如果我们把基类析构函数改写为虚函数，它实际上会调用两个析构函数，它会先调用派生类析构函数，然后在层次结构中向上，调用基类析构函数

class Derived : public Base
{
public:
	/*Derived() { std::cout << "Derived Constructed\n"; }
	~Derived() { std::cout << "Derived Destructed\n"; }*/
	Derived() { m_Array = new int[5];  std::cout << "Derived Constructed\n"; }
	~Derived() { delete[] m_Array; std::cout << "Derived Destructed\n"; }//这里只调用了派生类的构造函数，没有调用派生类的析构函数，但却实际上分配了20个字节的内存，这样就造成了内存泄露
private:
	int* m_Array;

};

int main()
{
	Base* base = new Base();//创建Base类的一个实例，并将其分配到堆上以方便我们可以明确地创建和删除它
	delete base;
	std::cout << "--------------------\n";
	Derived* derived = new Derived();
	delete derived;
	std::cout << "--------------------\n";
	Base* poly = new Derived();//创建一个Derived实例，但将它赋值给Base类类型
	delete poly;//创建时Derived和Base都正确创建了，但是删除是只有基类的析构函数被调用了，派生类的析构函数没有被调用，这样就导致了内存泄露

	std::cin.get();
}

//虚析构函数即虚函数与析构函数的结合
//虚析构函数主要用于处理多态，例如，如果你有一个类a,然后一个类b派生于a,你想把类引用为类a，但它实际上是类b，然后你决定删除a或者它以某种方式被删除了
//然后，你还是希望运行b的析构函数，而不是运行a的析构函数。这就是所谓的虚析构函数以及它的使用

//当你在写一个要扩展的类或者子类时，这一点非常重要。只要你允许一个类拥有子类，你需要百分之一百的声明你的析构函数是虚函数，否则没人能安全的扩展这个类，包括你自己也不能
//因为如果这样做，就不能使用析构函数，如果你根据类的基类类型来处理该类，那么类的析构函数将永远不会被调用