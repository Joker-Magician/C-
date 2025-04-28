#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
		func(value);//这里实际上是调用main函数里面定义的lambda的代码来做迭代
}
//lambda给的例子是我们将一个函数传给一个api，以便于在未来的某个时间，它可以为我们调用这个函数
//因为我们现在不知道不能调用这个函数，因为它还没有它需要的数据或者就是我们还不想调用它(我们想要延迟调用这个函数)，如果我们想调用这个函数，我们需要告诉它我们到了想调用函数的时候，我们要调用哪个函数
//lambda是一个很好的方法，来指定这个函数，指定未来想要运行的代码


int main()
{
	std::vector<int> values = { 1, 5, 4, 2, 3 };
	
	//ForEach(values, [](int value) { std::cout << "Value:" << value << std::endl; });


	auto lambda = [](int value) { std::cout << "Value:" << value << std::endl; };//学习C++时可以参考cppreference.com网站来学习
//[]是捕获的意思，如果想要将外部变量放lambda函数内部，和普通函数一样，有传值和引用两种方法

	int a = 5;
	//这个第一个方括号的意思就是说我们打算如何传递变量
	auto lambda1 = [=](int value) { std::cout << "Value:" << a << std::endl; };//[=]意思是传递所有的变量，通过值传递
	auto lambda2 = [&](int value) { std::cout << "Value:" << a << std::endl; };//[&]意思是传递所有的变量，通过引用传递
	auto lambda3 = [a](int value) { std::cout << "Value:" << a << std::endl; };//[a]传入a，通过引用传递;[&a]传入a，通过引用传递

	ForEach(values, lambda);//这里如果不包含<functional>可能会报错

	//lambda在[]还可以有可选修饰符，如mutable，它允许函数体修改通过拷贝传递捕获的参数
	auto lambda4 = [=](int value) mutable{ a = 5; std::cout << "Value:" << a << std::endl; };


	//使用lambda可以用来在某种迭代器中找到值
	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });//寻找比3大的数，然后返回它的迭代器，也就是满足条件的第一个元素.这里可以使用布尔if语句快速实现
	//find_if包含在<algorithm>头文佳中
	std::cout << *it << std::endl;

	std::cin.get();
}

//lambda本质上是我们定义一种叫做匿名函数的方式
//用这种方式创建函数，不需要实际创建一个函数，就像一个快速的一次性函数，展示下需要运行的代码
//运行原理：只要有一个函数指针，就可以在C++中使用lambda

