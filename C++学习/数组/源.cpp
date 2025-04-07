#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<array>

int main()
{
/*定义数组的三种方法*/
	//1
	int example[5];	//emample是一个内存地址，实际上example是一个整形指针
	
	//2
	int* another = new int[5];
	/*以上两种方法在效果上是一样的，但是它们的生命周期不同
	int example[5]是创建在栈上的，它会在跳出这个作用域的时候被销毁
	int* another = new int[5]是创建在堆上的，它会一直存活到直到我们把它销毁(使用delete)或程序结束
	*/
	delete[] another;
	/*这意味着如果有个函数要返回函数内新创建的数组，那么必须使用new来分配，除非传入的参数是一个内存地址*/
	/*使用后者创建还要考虑 内存间接寻址(memeory indirection)
	   从another地址上实际得到另一个地址，而这个地址指向我们实际的数组。这意味着如果要访问这个数组，则需要在代码里跳来跳去，这种跳跃肯定是影响性能的*/


	//3 确保包含了<array>
	std::array<int, 5> another_2;

	for (int i = 0; i < another_2.size(); i++)
		another_2[i] = 2;
	//如果想用它做边界检查，但会有额外的开销，不过这都是值得的
	//这个虽然更安全，但大部分人更习惯用原生的数组，会更快一点，不过一般也没什么问题


	static constexpr int exampleSize = 5;//类中的常量表达式必须是静态的，const和constexpr都可以
	int example_2[exampleSize];
	//在定义数组是需要提供一个它知道的常量,而这样设置是被允许的


	int* ptr = example;
	
	for (int i = 0; i < 5; i++)	//这里使用i<5而不是i<=4是因为后者可能会出现错误，且会做小于和等于两次操作，影响性能
		example[i] = 2;
	
	example[2] = 5;
	
	*(ptr + 2) = 6;//使用指针重写，指针会根据类型来计算所加的字节数，这里就是移2*4也就是8个字节
	*(int*)((char*)ptr + 8) = 6;//也可以通过这种花哨的操作达到相同的效果，而实际上就是写个了索引
}