#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<print>

//注意用using namespace可以，但永远不要在头文件中使用，也不建议使用标准库中的命名空间，不然非常容易与自己或其他一些相同的命名空间中的函数混乱
//非常容易使代码报错或很乱难以辨别作用和代码使用的语言，可以缩小命名空间的作用域使用(如在if条件中使用等)

//一个应该百分百避免的就是在头文件内使用using namespace,永远不要这样做！！！
//可以使用using namespace,可以只会using自己的库，绝对不会对std使用
//如果确实需要使用using，可以在一个较小的作用域内使用，最小也就在一个if条件语句中是使用，最大的情况，也就是在一个cpp文件的内部使用它

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{//帕斯卡命名法
	for (int value : values)
		func(value);
}

void for_each(const std::vector<int>& values, const std::function<void(int)>& func)
{//蛇形命名法
	for (int value : values)
		func(value);
}

namespace apple {

	void print(const std::string& text)
	{
		std::cout << text << std::endl;
	}

}

namespace orange {
	
	void print(const char* text)
	{//这个orange做的事情是将text赋值到一个字符串中，然后把字符串倒过来，然后打印出来
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}

}


int main()
{	
#if 0
	//在这串没用using namespace的原始代码中我很容易就能指出我使用的是标准模板库和C++库，不用就可以知道带有std前缀的东西就是来自标准库
	std::vector<int>values = { 1, 5, 4, 2, 3 };
	//C++(标准库)一般喜欢用这种蛇形命名法
	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
	std::cout << *it << std::endl;

	int a = 5;

	auto lambda = [=](int value) { std::cout << "Value:" << a << std::endl; };

	ForEach(values, lambda);

	{
		using namespace std;

		vector<int>values = { 1, 5, 4, 2, 3 };
		auto it = find_if(values.begin(), values.end(), [](int value) { return value > 3; });
		cout << *it << endl;

		int a = 5;

		auto lambda = [=](int value) { cout << "Value:" << a << endl; };

		for_each(values, lambda);
	//如果在这里调用了使用蛇形命名法命名的函数(如for_each和find_if)就会很难分清哪个是std(标准库)里面的，哪个是自己的命名空间或函数里面的。这让阅读代码变得更加困难
	}
#endif
	{
		using namespace apple;
		using namespace orange;

		apple::print("Hello");

		print("Hello");//在同时使用了using namespace orange与using namespace apple时会打印出来olleH
		//Hello是一个const char的数组而不是一个string，因为如果没有orange命名空间，那么apple可以做一个隐式转换，但当我们引入了orange，它的print函数会更加匹配，不需要任何转换
		//虽然这样做不会有error和warning，但它会调用完全不同的函数，这不是error，这是无声的运行时错误
	}

	{
		apple::print("Hello");

		orange::print("Hello");//在同时使用了using namespace orange与using namespace apple时会打印出来olleH
		//Hello是一个const char的数组而不是一个string，因为如果没有orange命名空间，那么apple可以做一个隐式转换，但当我们引入了orange，它的print函数会更加匹配，不需要任何转换
		//虽然这样做不会有error和warning，但它会调用完全不同的函数，这不是error，这是无声的运行时错误
	}

	std::cin.get();
}

//使用命名空间很有用，当命名空间很长或有自己的命名空间(自己的项目文件中的符号都在这个命名空间中)，当在某些函数中需要经常调用这些时可以使用命名空间

/*函数的两大命名法*/
/*帕斯卡命名法：每个单词首字母大写，中间不能有空格或下划线等，和驼峰的区别是驼峰首字母小写*/
/*蛇形命名法(snake case格式:小写单词，中间用下划线链接)*/