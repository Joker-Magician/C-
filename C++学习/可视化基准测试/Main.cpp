#include<iostream>
#include<string>
#include<chrono>
#include<algorithm>
#include<fstream>

#include<cmath>
#include<thread>

struct ProfileResult
{
	std::string Name;
	long long Start, End;
	uint32_t ThreadID;//将一个线程id放到结构体中，然后我们也会把那个线程id输出到json文件中
};

struct InstrumentationSession
{
	std::string Name;
};

class Instrumentor //这个类所做的是格式化一个json文件，并将其写入一个文件
{
private:
	InstrumentationSession* m_CurrentSession;
	std::ofstream m_OutputStream;
	int m_ProfileCount;
public:
	Instrumentor()
		:m_CurrentSession(nullptr), m_ProfileCount(0)
	{
	}

	void BeginSession(const std::string& name, const std::string& filepath = "resluts.json")//打开一个文件
	{
		m_OutputStream.open(filepath);
		WriteHeader();	//写一个文件头，是json文件的开头，这是Chrome tracing需要的一个特定的格式
		m_CurrentSession = new InstrumentationSession{ name };
	}

	void EndSession() //写一个简单的页脚，关闭文件等等
	{
		WriteFooter();
		m_OutputStream.close();
		delete m_CurrentSession;
		m_CurrentSession = nullptr;
		m_ProfileCount = 0;
	}

	void WriteProfile(const ProfileResult& result) //这是整个类的核心，用来单独写时间分析数据
	{
		if (m_ProfileCount++ > 0)
			m_OutputStream << ",";

		std::string name = result.Name;
		std::replace(name.begin(), name.end(), '"', '\'');

		m_OutputStream << "{";
		m_OutputStream << "\"cat\":\"function\",";
		m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
		m_OutputStream << "\"name\":\"" << name << "\",";
		m_OutputStream << "\"ph\":\"X\",";
		m_OutputStream << "\"pid\":0,";
		m_OutputStream << "\"tid\":" << result.ThreadID << ",";
		//m_OutputStream << "\"tid\":0,";	//这里设置线程id,本例中设置为0
		m_OutputStream << "\"ts\":" << result.Start;
		m_OutputStream << "}";	//每次运行文件，这些就是我们要输出的

		m_OutputStream.flush();	//一旦它输出更多的json进入输出流，然后就进行刷新。每次写profile文件时，都要这样做的原因是，以防程序崩溃或终止，我们不想丢失所有提供的数据，我们要把这些数据流到文件中，如果发生了什么问题所有的数据都是安全的，我们还可以使用
	}

	void WriteHeader()
	{
		m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
		m_OutputStream.flush();
	}

	void WriteFooter()
	{
		m_OutputStream << "]}";
		m_OutputStream.flush();
	}

	static Instrumentor& Get()
	{
		static Instrumentor* instance = new Instrumentor();
		return *instance;
	}
};

class InstrumentationTimer //插桩计时器InstrumentationTimer，插桩的概念是，注入我们的代码并进行分析
{
public:
	InstrumentationTimer(const char* name)
		:m_Name(name), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~InstrumentationTimer()
	{
		if (!m_Stopped)
			Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();//微秒microseconds,毫秒milliseconds
		long long end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimepoint).time_since_epoch().count();
	
		//std::cout << m_Name << ":" << (end - start) << "ms\n";
		uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());//在timer中的stop函数看看timer实际上是在哪个线程上运行的，这样就可以设置这个线程id.C++标准库使得作为一个整数取得线程id变得困难，但由于线程id实现了一个哈希函数，我们可以使用这个小技巧
	//我们会把线程id传递到结构体中，到正确的profile文件中，然后我们稍微改变下面的Benchmark,让它们使用多个线程，这样我们就能看到线程的运行情况了
		Instrumentor::Get().WriteProfile({ m_Name, start, end, threadID });//通过WriteProfile函数用ProfileResult作为参数，使其包含名字，开始时间，结束时间

		m_Stopped = true;
	}
private:
	const char* m_Name;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	bool m_Stopped;
};

#define PROFILING 1	//如果这个设置为1,那么PROFILING是启用的，这意味这我们会有PROFILE_SCOPE引入一个InstrumentationTimer，并做所有这些事
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name) //这里定义一个宏，它会把name作为参数，这会包装我们的InstrumentationTimer调用，这里我们会拼接行号,这样我们既可以为变量取一个唯一的名字，以防我们有很多这样的东西。但这里不需要##(这取决于编译器的使用)，为了安全起见这里使用它，我们只是把timer和行号链接在一起
//#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__) //这个没有参数，这会调用PROFILE_SCOPE宏，但对于name,它会接受函数的名字，我们可以用编译宏_FUNCTION_来做，注意要放到#else里
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)	//__FUNCSIG__的宏，也就是函数签名，这样我们会得到整个函数的签名(不必担心重载的问题了)，不过仅仅这样会有calling convebtion(函数调用约定),这是签名的一部分，我们并不关心它。如果我们想要删掉它，通过一些字符的处理就可以在放入json文件前去处理它
#else
#define PROFILE_SCOPE(name)	//如果被禁用，我们让它空着就可以，这意味着PROFILE_SCOPE没有任何代码，这样可以有效地剥离计时器
#endif

void Function1()
{
	//InstrumentationTimer timer("Function1");
	//PROFILE_SCOPE("Function1");
	PROFILE_FUNCTION();//添加PROFILE_FUNCTION()后就不必写名字了

	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World #" << i << std::endl;
}

void Function2()
{
	//InstrumentationTimer timer("Function2");
	//PROFILE_SCOPE("Function2");
	PROFILE_FUNCTION();

	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World #" << sqrt(i) << std::endl;
}
//虽然我们可以从控制台上找到计时结果，但显示它们仍然只是数组，而且还非常难以找到
//所以我们进入visualization(可视化)

namespace Benchmark {
	void PrintFunction(int value)
	{

		PROFILE_FUNCTION();

		for (int i = 0; i < 1000; i++)
			std::cout << "Hello World #" << (i + value) << std::endl;
	}

	void PrintFunction()
	{
		PROFILE_FUNCTION();

		for (int i = 0; i < 1000; i++)
			std::cout << "Hello World #" << sqrt(i) << std::endl;
	}

	void RunBenchmarks()
	{	//由于我们堆栈中有另一个函数，我们也是可以将其可视化的
		//InstrumentationTimer timer("RunBenchmarks");//这样就可以看到两个基准测试时间，通过看wall duration。
	//但不幸的是，这个RunBenchmarks必须复制和粘贴我们调用的每个函数的名称，另外这种计时代码不是我们想要在程序中一直运行的东西，应该有一个简单的方法来关闭这些，因为这会增加一些开销，所以我们要通过写一些宏来解决这两个问题
		PROFILE_FUNCTION();

		std::cout << "Running Benchmarks...\n";
		/*一般调用情况*/
			//Function1();
			//Function2();
		/*发生了函数重载，且两个函数都被调用了*/
		//PrintFunction(2);//这样如果按照上面的方法它们都会被定义为PrintFunction,因为预处理器__FUNCTION__定义所做的是取函数的实际名称，会难以区分重载函数的tracing
		//PrintFunction();
	
		//std::thread a(std::bind(PrintFunction, 2));这里初次尝试使用std::bind名单结果更麻烦，它们它是同名函数重载，你还需要进行转换，相当混乱
		std::thread a([]() {PrintFunction(2); });//这里使用lambda更简单
		//std::thread b([]() {PrintFunction(); });//这样能够看到两个线程，注释掉后就可以看到RunBenchmarks线程的调用堆栈，它是我们的主线程
		PrintFunction();

		a.join();
		//b.join();//最后加入2个囧函数，这样在两个线程都完成它们的工作之前，我们不会退出这个运行的Benchmark函数
	}
}//将以上内容让放到命名空间后，因为我们使用了__FUNCSIG__宏，我们就会得到所有这些信息
//如果你的代码中有你想要分析的区域，特别的，不是在函数中，你可以将PROFILE_SCOPE放到任何当前作用域中,需要的话你也可以创建一个空作用域

int main()
{
	Instrumentor::Get().BeginSession("Profile");//创建一个有给定文件名的新文件，这里使用默认参数result.json。
	/*Function1();
	Function2();*/
	Benchmark::RunBenchmarks();
	Instrumentor::Get().EndSession();
	//在BeginSession和EndSession之间做的事情将会被放入分析文件中，这使得我们能够将分析数据分解成多个文件
	std::cin.get();
}



//数据可视化对我们人类来说一直是非常有用的，它能够让我们理解得更多

//我们可以使用谷歌chrome来做可视化分析，Chrome自带了一些自己的分析工具和其他开发工具，但很明显这是真的网页应用或网页的。
// 还有一个特别的叫做Chrome Tracing(edge里也可以),它很基础(barebone，准系统),也很简单，让我们可视化分析和堆栈跟踪视图
//只需要在你的url栏里输入chrome://tracing即可(注意初次可能需要打开开发者的调试功能)，这个的界面非常简洁，它的工作方式是加载一个包含所有数据的json文件
//我们下一步是取所有我们用计时器记录的计时数据，并把它们放入一个Chrome tracing希望的json格式文件

//有了json文件后，将其拖到Chrome Tracing里就可以看到可视化的数据了
//ChromeTracing同时也支持多线程，注意设置好线程id,这样你能够看到当前运行的所有线程，这在分析之外很有用，可以看到你的程序中到底发生了什么，这让计时和分析变得强大