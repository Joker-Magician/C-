#include<iostream>
#include<vector>

void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void HelloWorld_a(int a)
{
	std::cout << "Hello World! Value: " << a << std::endl;
}

void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values,void(*func)(int))
{
	for (int value : values)
		func(value);

}

int main()
{
	//void(*function)();//这是下面auto推断的类型，当然实际function只是一个名字可以改变

	auto function = HelloWorld;//直接auto function = HelloWorld()是不行的，因为auto无法推断返回值，HelloWorld的返回值是void
//这样可以是因为我实际上并不是在调用函数，而是在获取函数指针，相当于&HelloWorld
//函数就像是CPU指令，当我们编译代码时它就在二进制文件的某个地方，我们所做的是当这个函数被调用时，我们要检索要执行的指令的位置

	function();

	//上面代码可能看着很奇怪，因此可以使用typedef和using来调用function
	typedef void(*HelloWorldFunction)();
	HelloWorldFunction function1 = HelloWorld;
	function1();

	typedef void(*HelloWorldFunction_a)(int);
	HelloWorldFunction_a function2 = HelloWorld_a;
	function2(8);


	//可使用的例子
	std::vector<int> values = { 1, 5, 4, 2, 3 };//初始化列表
	ForEach(values, PrintValue);//第一种调用方式，这里有隐式转换所以没有解引用

	ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
//这里使用了lambda隐匿函数，只有一次性的，用完即弃的函数。[]叫做捕获方式，也就是如何传出函数，q其余部分和函数一样

	std::cin.get();
}

//函数指针是来自C语言的内容，是将一个函数赋值给一个变量的方法

