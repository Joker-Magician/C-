#include<iostream>
#include<string>
#include<chrono>
#include<algorithm>
#include<fstream>

#include<cmath>

struct ProfileResult
{
	std::string Name;
	long long Start, End;
};

struct InstrumentationSession
{
	std::string Name;
};

class Instrumentor
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

	void BeginSession(const std::string& name, const std::string& filepath = "resluts.json")
	{
		m_OutputStream.open(filepath);
		WriteHeader();
		m_CurrentSession = new InstrumentationSession{ name };
	}

	void EndSession()
	{
		WriteFooter();
		m_OutputStream.close();
		delete m_CurrentSession;
		m_CurrentSession = nullptr;
		m_ProfileCount = 0;
	}

	void WriteProfile(const ProfileResult& result)
	{
		if (m_ProfileCount++ > 0)
			m_OutputStream << ",";

		std::string name = result.Name;
		std::replace(name.begin(), name.end(), '"', '\'');

		m_OutputStream << "{";
		m_OutputStream << "\"cat\":\"function\",";
		m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
		m_OutputStream << "\"name\":\"" << name << "\",";
		m_OutputStream << "\"ph\":\"x\",";
		m_OutputStream << "\"pid\":0";
		m_OutputStream << "\"tid\":0,";
		m_OutputStream << "\"ts\":" << result.Start;
		m_OutputStream << "}";

		m_OutputStream.flush();
	}

	void WriteHeader()
	{
		m_OutputStream << "{\"otherData\": {},\"traceEvents\":{";
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

class Timer
{
public:
	Timer(const char* name)
		:m_Name(name), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();//使用毫秒
		long long end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimepoint).time_since_epoch().count();
	
		std::cout << m_Name << ":" << (end - start) << "ms\n";

		m_Stopped = true;
	}

	~Timer()
	{
		if (!m_Stopped)
			Stop();
	}
private:
	const char* m_Name;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	bool m_Stopped;
};

void Function1()
{
	Timer timer("Function1");

	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World" << std::endl;
}

void Function2()
{
	Timer timer("Function2");

	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World" << std::endl;
}
//虽然我们可以从控制台上找到计时结果，但显示它们仍然只是数组，而且还非常难以找到
//所以我们进入visualization(可视化)
int main()
{
	Function1();
	Function2();

	std::cin.get();
}


//数据可视化对我们人类来说一直是非常有用的，它能够让我们理解得更多

//我们可以使用谷歌chrome来做可视化分析，Chrome自带了一些自己的分析工具和其他开发工具，但很明显这是真的网页应用或网页的。
// 还有一个特别的叫做Chrome Tracing(edge里也可以),它很基础(barebone，准系统),也很简单，让我们可视化分析和堆栈跟踪视图
//只需要在你的url栏里输入chrome://tracing即可(注意初次可能需要打开开发者的调试功能)，这个的界面非常简洁，它的工作方式是加载一个包含所有数据的json文件
//我们下一步是取所有我们用计时器记录的计时数据，并把它们放入一个Chrome tracing希望的json格式文件