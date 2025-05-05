#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

int main()
{
	std::vector<int> values = { 3, 5, 1, 4, 2 };
	std::sort(values.begin(), values.end());//如果不提供任何谓词或函数，对于整数他会按照升序排序
	
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;

//如果想要提供某种方式让它排序，可以通过传递一个函数来实现，它既可以是一个你创建的结构体内的函数，也可以是一个lambda，也可以是内置函数
	std::sort(values.begin(), values.end(), std::greater<int>());//这会按照从大到小排序
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;

//bool cmp(const Type1 &a, const Type2 &b)这个比较函数会返回一个bool值，ture或false，如果我们传入的第一个参数排在前面的话，那么返回ture
	std::sort(values.begin(), values.end(), [](int a, int b)//因此这里我们给的两个值a和b，哪一个应该排在前面，这就是我们要确定的
		{//如果返回ture，这意味这a会被排在b之前，而如果我们返回false，那么b就会在a之前
			return a < b;//如果a<b，它会排列到列表的前面
		});//规则使用lambda
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;

	std::sort(values.begin(), values.end(), [](int a, int b)//因此这里我们给的两个值a和b，哪一个应该排在前面，这就是我们要确定的
		{
			return a > b;
		});
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;

	//将1放到最后
	std::sort(values.begin(), values.end(), [](int a, int b)//因此这里我们给的两个值a和b，哪一个应该排在前面，这就是我们要确定的
		{
			if (a == 1)
				return false;
			if (b == 1)
				return true;

			return a < b;
		});
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;


	std::cin.get();
}

//在C++排序std::sort中，我们需要给它提供一个迭代器，包括一个开始迭代器和一个结束迭代器，迭代器内的所有东西都会基于我们提供的某个谓语排序
//我们可以不提供谓语，那么它会尝试基于类型进行排序，我们也可以给他提供一个函数或这lambda，基于这些规则进行排序
//std::sort没有任何返回值，排序的复杂度是N*logN