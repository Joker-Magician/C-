#include<iostream>
#include<any>//右击进入代码可以看到any的所有代码
#include<variant>
//想要知道哪些分别都是怎么工作的可以打开头文件的源代码看一下，虽然有时因为它的书写方式会很难，但只要慢慢来，你会对自己真正理解的程度感到惊讶

//通过对new重载来跟踪内存的分配，重载了new并且逐步调试观察标准库里有没有调用new，从而知道内存的分配问题
void* operator new (size_t size)//用自己的操作符替换operator new
{
	return malloc(size);//这不是一个很好使用new的方法，请不要在生产代码中使用它，只是通过这个来知道内存分配情况
}

struct CustomClass //测试超过32字节的内存
{
	std::string s0, s1;
};

int main()
{
	std::any data;
	data = 2;//int
	//data = "Cherno";//const char
	data = std::string("Cherno");//any可以设为为任意值，因为这就any
//如果想要取出某个类型，，你必须知道它是哪个类型，然后把它转换成那个类型，你可以用std::any_cast来做
	//std::string string = std::any_cast<std::string>(data);//如果data不是你想转换的elixir，这将会抛出一个转换的异常
	//这样是不行的，因为这个Cherno不是字符串，它只是一个const char指针(不安全)
	data = CustomClass();
	std::string& string = std::any_cast<std::string&>(data);//引用，不复制数据，提高性能


	std::variant<int, std::string> dataV;//如果使用variant
	dataV = 2;
	dataV = "Cherno";
	std::string stingV = std::get<std::string>(dataV);//因为这会隐式地转换成以后字符串，因为它必须是字符串或int。any不会隐式转换，因为它本是就可以变成任何类型

	std::cin.get();
}

//std::any和std::variant是类似的，为你可以存储任何类型，而std::variant要求我们列出所有的类型，而any这里，你根本不用担心类型。相反，这才是在绝大多数情况下，为社么std::variant比std::any更好的地方
//事实上，std::variant要求列出所有这些类型，这很好，会使得类型安全

//variant和any还有一个区别是和它们的存储方式有关，variant只是一个类型安全的union，意思是它把所有的数据都存储在一个union里

//通过打开any的源代码读后，可发现any其实也是一个union，对于小类型而言，它只是把它们存储为一个union，这意味着对于小类型(small type)来说，它的工作方式与variant完全相同
//如果你有一个大的类型，它会带你进入大存储空间的void*，在这种情况下，它会动态分配内存，但动态分配内存不利于性能
//总结,即如果你在小型类型使用variant或any都没问题，在使用的visual studio和msvc里any最开始是32字节的，如果你需要更多的存储空间，std::any会调动new进行动态分配，但是std::variant不会 
//换句话说，除了更加类型安全和有一点限制性(这是一件好事)之外,std::variant子啊处理较大数据时也会执行得更快，而这些数据有需要避免动态内存分配
//另一个提高性能的技巧就是确保你不会复制数据

//最后，any应该什么时候使用呢？很多人会直接了当的告诉你，他优点无用，说实话Cherno倾向于同意
//如果希望在一个变量中存储多个数据类型，请使用std::variant，他基本上时std::any的类型安全版本，这意味这你不能随意设置它的类型，而且它也不会动态分配内存，这样它的性能会更好。
//如果你选哦，要求能够在单个变量中存储任何数据类型，也许你需要重新考虑程序的设计，一般就不一般就不应该用到它
//如果你有像缓冲区的数据，你完全不知道这些数据是什么，你只是想指向它们，那你可以用void指针

//目前any并不是像optional和varian一样有用