#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void apple_print(const std::string& text)
{
	std::cout << text << std::endl;
}//传统的C语言中没有命名空间的写法应该是这样的，可以避免命名冲突

namespace apple1 { namespace function {
//不按照VS自动的缩进方式(大括号不换行)，而是这样写可以在发生多级命名空间嵌套是，将内容一级缩进、二级缩进这样看很清晰看清
		void print(const char* text)
		{
			std::cout << text << std::endl;
		}
		
	}
}

namespace apple {

	void print(const char* text)
	{
			std::cout << text << std::endl;
	}

	void print_again();
}

namespace orange {

	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}

}


int main()
{
	apple1::function::print("Hello");

	apple::print("Hello");//::是命名空间操作符，写上就意味着进入了这个命名空间
//同样的方法也可以用在类中，因为类本身就是命名空间

	/*using namespace orange/apple;可以这样方便修改
	print("Hello");*/
	using apple::print;//只单独使用apple中的print函数
	print("Hello");
	apple::print_again();//这里依然需要指明print_again()来自哪个命名空间

	namespace a = apple;
	a::print("Hello");//可以给apple命名空间一个别名

	namespace b = apple1::function;
	b::print("Hello");


	std::cin.get();
}

//命名空间的主要目的是避免命名冲突
//当我们希望能够在不同的上下文中调用相同的符号，就可以用到命名空间