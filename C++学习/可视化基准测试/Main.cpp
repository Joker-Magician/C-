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

		long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();//ʹ�ú���
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
//��Ȼ���ǿ��Դӿ���̨���ҵ���ʱ���������ʾ������Ȼֻ�����飬���һ��ǳ������ҵ�
//�������ǽ���visualization(���ӻ�)
int main()
{
	Function1();
	Function2();

	std::cin.get();
}


//���ݿ��ӻ�������������˵һֱ�Ƿǳ����õģ����ܹ����������ø���

//���ǿ���ʹ�ùȸ�chrome�������ӻ�������Chrome�Դ���һЩ�Լ��ķ������ߺ������������ߣ������������������ҳӦ�û���ҳ�ġ�
// ����һ���ر�Ľ���Chrome Tracing(edge��Ҳ����),���ܻ���(barebone��׼ϵͳ),Ҳ�ܼ򵥣������ǿ��ӻ������Ͷ�ջ������ͼ
//ֻ��Ҫ�����url��������chrome://tracing����(ע����ο�����Ҫ�򿪿����ߵĵ��Թ���)������Ľ���ǳ���࣬���Ĺ�����ʽ�Ǽ���һ�������������ݵ�json�ļ�
//������һ����ȡ���������ü�ʱ����¼�ļ�ʱ���ݣ��������Ƿ���һ��Chrome tracingϣ����json��ʽ�ļ�