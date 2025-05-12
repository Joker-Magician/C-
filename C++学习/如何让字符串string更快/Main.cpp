#include<iostream>
#include<string>

static uint32_t s_AllocCount = 0;//代表分配次数(注意要在32位及x86下运行)

void* operator new(size_t size)//跟踪内存，重载new操作符，查看内存被分配了多少次
{
	s_AllocCount++;//计算分配数量
	std::cout << "Allocating " << size << " bytes\n";//打印分配的大小
	return malloc(size);
}
#define STRING_VIEW 1//使用原始字符
#if STRING_VIEW//关掉STRING_VIEW
void PrintName(std::string_view name)
{
	std::cout << name << std::endl;
}
#else
void PrintName(const std::string& name)//虽然接受的是const引用，但它仍然需要为我们构造一个std::string,构造仍需要分配内存
{
	std::cout << name << std::endl;
}
#endif

int main()
{
	//std::string name = "Yan Chernikov";//想要将分配减到0，方法就是完全不使用std::string
	////const char* name = "Yan Chernikov";//这是一个静态字符串，完全没有必要使用std::string

	//PrintName(name);
	//
	//std::cout << s_AllocCount << " allocations" << std::endl;//打印分配次数
	//
	//s_AllocCount = 0; std::cout << std::endl;//1

	//std::string name = "Yan Chernikov";

	std::string name = "Yan Chernikov";
#if STRING_VIEW
	std::string_view firstName(name.c_str(),3);//这里可以用构造函数来指定子字符串,通过name.c_str()，这个输入字符串namedconst char*类型
	std::string_view lastName(name.c_str() + 4, 9);
	//std::string_view firstName(name, 3);
	//std::string_view lastName(name + 4, 9);
#else
	std::string firstName = name.substr(0, 3);
	std::string lastName = name.substr(4, 9);//这里我们没有做多少操作就已经有3个分配了，如果在在一些实时运行的程序，如应用或游戏或类似的东西，你每帧都在做这种事，它会堆积起来，它会损害你的帧速率
#endif

	PrintName("Cherno");
	PrintName(firstName);
	PrintName(lastName);//使用string_view就只有1次分配了
	//PrintName(name.substr(0, 3));//这样反而会有4个分配，因为它所做的是创建了一个全新的字符串，它可以变化并由自己的内存，但我们真正想要的是那个字符串的实视图，这就需要string_view发挥作用了

	std::cout << s_AllocCount << " allocations" << std::endl;//打印分配次数

//std::string_view虽然是C++17的新特性，实际上在C++17之前就可以用。它本质上只是一个指向现有内存的指针，换句话说，就是一个const char指针，指向其他人拥有的现有字符串，再加上一个大小size
//因此对于Yan Chernikov这个名字，我可以有一个指向第一个字符的指针，然后大小是3，这就是我们的子字符串，然后我可以有一个指针指向那个字符串的开头加上四个字节，把我带到那个lastName的开头
//换句话说，我在创建一个窗口，一个进入现有内存的小视图，而不是分配一个新的字符串，用substr()创建一个新的字符串
//这里最大的好处是我不是在创建自己的字符串，我只是在观察一个已有的字符串，没有内存分配，按值传递字符串视图是非常轻量级的
	
	std::cin.get();
}

//程序中有很多字符串操作，格式化文本，比如日志记录，使用正确格式，使用子字符串等等，这并不是只是在玩一串字符没这个很糟糕，而且非常慢,这是因为它们要分配内存
//在堆上分配内存并不一定是件坏事，事实上在很多情况下这是不可避免的，但如果你可以避免你就应该避免，因为它会降低程序的速度，std::string和它的很多函数多喜欢分配，但这实际上并不理想


//这里总共有两种情况：一种是使用字符串，另一种是使用字符串视图