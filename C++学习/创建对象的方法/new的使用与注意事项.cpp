#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknow") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

int main()
{
	int a = 2;
	int* b = new int[50];//200 bytes//因为会返回指针，所以用b*,b存储的就是它的内存地址

	Entity* e = new Entity[50];//和类一起使用时，new做了两件事，一是看它有多大，在这里给你一个50个连续的Entity
	Entity* e = new Entity();//这样就只分配了一个，这里它还调用了构造函数，这就是new做的另一个事情.默认调用可以不加括号
//new只是一个操作符，和加减乘除一样，这意味它可以被重载，并改变它的行为
	//通常调用new就调用了C中的malloc函数
	malloc(50);//实际作用是传入一个size，也就是我们要多少字节，然后返回一个void指针
	/*Entity* e = new Entity();
	Entity* e = (Entity*)malloc(sizeof(Entity));*///两行代码实际是相似的，仅有的区别是new调用了Entity的构造函数

	delete e;//这是一个常规函数，它调用了C中的free函数去释放内存
	//如果不释放，它就没有被标记为空闲，也就不会被放回空闲列表，这些内存就再也不能被调用
	delete[] b;//使用了数组操作符[],就要用数组操作符来释放

	std::cin.get();
}


//new的主要目的是分配内存，具体来说就是在堆上分配内存
//先写new,然后写上数据类型(这可以是一个类，也可以是一个基本类型，或者是一个数组),根据你所写的类型，以字节为单位决定了要分配的内存大小
//比如写new int，它会请求分配4个字节的内存，一旦有了那个数字，它会请求操作系统，或者说C标准库"我需要4个字节的内存，请把它给我"
//然后，现在我们需要找到一个包含4字节的连续内存块，即使4个字节很小，分配起来很快，但仍要在一行内存中找到一个4字节的内存地址
//找到之后，它就会返回一个指向那个内存地址的指针，然后就可以开始使用数据了

//在找到那些连着的内存块并不是一个个的寻找，这其实有一个叫空闲列表的东西，它会维护那些有空闲字节的地址，但仍然很慢

//new主要就是找到一个满足我们需求的足够大的内存块，然后给我们一个指向那个内存地址的指针