#include<iostream>
#include<memory>

#include<chrono>
#include<array>

class Timer
{
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();//得到当前的时间，类型可通过鼠标放到now上查看
	}

	~Timer()
	{
		Stop();
	}

	void Stop()//这个stop函数在析构函数中自动调用，我们希望这个是基于作用域的
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();//将其转换到正确时间，然后计数(count),给出startTime微秒计数，microseconds将开始时间用微妙来表示
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();//将其转换到正确时间，然后计数(count),给出startTime微秒计数，microseconds将开始时间用微妙来表示

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << duration << "us(" << ms << "ms)\n";
	}
/*这样就可以做很多事，可以从stop函数输出数据到某种跟踪器中，跟踪测量的实际结果，但这是一个非常大的系统，它输出所有的数据到一个文件中，做很多事情，这样你就可以查看了
在单独的工具中，查看程序中的所有内容消耗的时间，如果你想制作一款游戏，你会看到每一帧所花费的时间，以及每一帧有哪写函数，哪些耗时比较多*/

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;//将当前时间存储到这个私有成员变量中

};
//当这个对象被创建时我们开始计时器，当对象被销毁时我们停止计时器，这就是所谓的RAII(资源获取初始化,Resource Acquisition Is Initialization)


int main()
{
	int value = 0;
	{
		Timer timer;
		for (int i = 0; i < 1000000; i++)
			value += 2;
	}
	/*注意，要确保你所测量的东西，就是实际上被编译的代码，这非常重要，因为C++编译器可以优化代码，剥离代码，甚至完全更改代码*/
	/*可通过右击查看汇编语言来对比debug与release的差别，release代码优化化后汇编就少了很多，如for循环中，就没有加法指令。实际发生的是，编译器看了这串代码并意识到，这并不需要在运行时计算，于是进行了优化，
	直接在编译时就计算出来了，只需要打印出两百万就行了
	即这类计时器的结果将是完全无用的，因为啥没测量，我们基本上是在测量打印需要多长时间。所以，无论你在测试什么，都要确保你确实做了这些事情，你并不是在测量什么都没有发生的事情，因为编译器实际上会非常积极地改变你的代码*/

	std::cout << value << std::endl;

	//测量智能指针的性能(并不是一个合理的测试，因为我们甚至没有访问数据，也没和其他共享指针或其他东西共享数据)
	struct Vector2
	{
		float x, y;
	};
	//注意要更接近我们真正关心的代码，我们并不关心创建数组
	std::cout << "Make Shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vector2>();
	}

	std::cout << "New Shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2);
	}

	std::cout << "Make Unique\n";
	{
		std::array<std::unique_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_unique<Vector2>();
	}
//在调试模式下分析，make_Shared和new_Shared差不多，这是在debug下分析的，这对测试性能不是很好，因为它有很多额外的安全措施需要时间
//在release模式下分析，会发现除了都明显加快了，还有make_Shared明显比new_Shared更快

	__debugbreak();//设置断点，这是visual studio专门仅用于windows的函数,它所做的是中断编译，这样我们就不用在这里插入代码，然后自己设置断点了
}

//基准测试，每个人都有每个人的方法，但如果你用错了方法，你衡量性能本身可能会增加开销
//有些人喜欢依赖第三方分析工具，有些人喜欢对diamond进行仪表化处理，给他们设置计时器之类的东西，有些人喜欢运行他们的程序，把程序封装在一个计时器中，然后测试想要测试的特定程序

//基准测试不仅仅是你用来对代码进行基准测试的工具，如果你想要衡量一段C++代码的性能，而这段代码本身就需要你"正确"地去写
