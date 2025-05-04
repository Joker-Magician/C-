#include<iostream>
#include<chrono>
#include<thread>

//使用整个对象生存周期之类的范例让它自动为我计时
struct Timer 
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;//因为时间很短所以用ms,这样会得到毫秒
		std::cout << "Timr took " << ms << "ms" << std::endl;
	}
};//我们有一个简单的结构体进行计时并自动打印，这是基于析构函数来做的，我们真正要做的就是在函数的开头创建对象

void Funtion()
{
	Timer timer;

	/*for (int i = 0; i < 100; i++)
		std::cout << "Hello" << std::endl;*/

	for (int i = 0; i < 100; i++)
		std::cout << "Hello\n";//这个时间快了三分之一，因为std::endl会因为某些原因拖慢时间
}
//如果你关心基准测试等等，你应该在release模式下多运行几次

int main()
{
	using namespace std::literals::chrono_literals;//这样下面才能使用1s

	auto start = std::chrono::high_resolution_clock::now();//表示开始时间
	std::this_thread::sleep_for(1s);//让线程休眠1s
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;//std::chrono::duration<float>作为高精度时间
	std::cout << duration.count() << "s " << std::endl;
	//线程的休眠时间不能保证是你告诉它的睡眠时间，而且计时本身也会有时间开销

	Funtion();

	std::cin.get();
}

//计时无论在你希望某些事情在特定时间发生，还是只是评估性能或做基准测试看看你的代码运行得多快都很有用
//在C++11后我们有chrono，它是C++库的一部分，不需要去使用操作系统库。在C++11之前你想要有一个非常精确的计时器，那你需要使用操作系统库，如在windows中有一个QueryPerformanceCounter的东西
//我们仍然可以使用那些，但事实上，如果你想要更多地控制计时，控制CPU的计时能力，你可能使用平台特定的库
 