#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

//注意用using namespace可以，但永远不要在头文件中使用，也不建议使用标准库中的命名空间，不然非常容易与自己或其他一些相同的命名空间中的函数混乱
//非常容易使代码报错或很乱难以辨别作用和代码使用的语言，可以缩小命名空间的作用域使用(如在if条件中使用等)

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
		func(value);
}

int main()
{
	std::vector<int>values = { 1, 5, 4, 2, 3 };
	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
	std::cout << *it << std::endl;

	int a = 5;

	auto lambda = [=](int value) { std::cout << "Value:" << a << std::endl; };

	ForEach(values, lambda);
	std::cin.get();
}

//