#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//应用程序会把内存分为两部分:堆与栈,以及其他一些东西
using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknow"){}
	Entity(const String& name): m_Name(name){}

	const String& GetName() const { return m_Name; }
};

void Function()
{
	int a = 2;
	Entity entity = Entity("Charno");
}//当这个函数结束时，这个栈结构就会被销毁，栈上创建的所有变量都会消失

int main()
{
	Function();//当我们调用Function时，就为这个函数创建了一个包含了生命的所有局部变量的栈结构
	
	Entity* e;
	{
		Entity entity ("Cherno");//这实际上就是构造函数
		e = &entity;//如果想要这个Cherno在这个生命周期外继续存活就不能把他分配到栈上，而是必须分配到堆上
		std::cout << entity.GetName() << std::endl;//另外不想分配到栈上的原因可能是，如果这个entity太大，同时我们可能有很多的entity，我们可能就没有足够的空间来进行分配，因为栈通常是很小的，一般是一两兆，着取决于你的平台和编译器
	}

	Entity* e;
	{
		Entity* entity = new Entity("Cherno");	//在堆上分配首先要用Entity*而不是Entity类型，然后使用new来给entity赋值，这里最大的区别不是那个指针而是new这个关键字
		e = entity;	//当调用了new类型实际上就是发生了在堆上分配空间，然后这个new Entity实际会返回一个Entity指针，所以我们要声明成Entity*类型
		std::cout << entity->GetName() << std::endl;
		//delete entity;	//使用了new就要负责告诉编译器把内存释放掉，不然会造成内存泄露
	}

	std::cin.get();
	delete e;//这个只有调用了delete才会被释放掉，即使放到cin.get后也一样

}

//如果你的对象非常非常大，或者想要显示地控制对象的生存周期，就在堆上创建
//如果不是这两种情况，那就在栈上分配，这更简单，会自动回收，也更快
//如果要在堆上创建就一定要调用delete释放掉内存