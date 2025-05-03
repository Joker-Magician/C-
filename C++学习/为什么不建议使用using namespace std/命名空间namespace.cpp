#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void apple_print(const std::string& text)
{
	std::cout << text << std::endl;
}//传统的C语言中没有命名空间的写法应该是这样的，可以避免命名冲突

namespace apple { namespace function {
//不按照VS自动的缩进方式(大括号不换行)，而是这样写可以在发生多级命名空间嵌套是，将内容一级缩进、二级缩进这样看很清晰看清
		void print(const char* text)
		{
			std::cout << text << std::endl;
		}
	}
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
	apple::function::print("Hello");//::是命名空间操作符，写上就意味着进入了这个命名空间



	std::cin.get();
}

//命名空间的主要目的是避免命名冲突
//当我们希望能够在不同的上下文中调用相同的符号，就可以用到命名空间