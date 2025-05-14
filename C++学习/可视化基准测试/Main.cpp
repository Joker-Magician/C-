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

class Instrumentor //������������Ǹ�ʽ��һ��json�ļ���������д��һ���ļ�
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

	void BeginSession(const std::string& name, const std::string& filepath = "resluts.json")//��һ���ļ�
	{
		m_OutputStream.open(filepath);
		WriteHeader();	//дһ���ļ�ͷ����json�ļ��Ŀ�ͷ������Chrome tracing��Ҫ��һ���ض��ĸ�ʽ
		m_CurrentSession = new InstrumentationSession{ name };
	}

	void EndSession() //дһ���򵥵�ҳ�ţ��ر��ļ��ȵ�
	{
		WriteFooter();
		m_OutputStream.close();
		delete m_CurrentSession;
		m_CurrentSession = nullptr;
		m_ProfileCount = 0;
	}

	void WriteProfile(const ProfileResult& result) //����������ĺ��ģ���������дʱ���������
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
		m_OutputStream << "\"tid\":0,";
		m_OutputStream << "\"ts\":" << result.Start;
		m_OutputStream << "}";	//ÿ�������ļ�����Щ��������Ҫ�����

		m_OutputStream.flush();	//һ������������json�����������Ȼ��ͽ���ˢ�¡�ÿ��дprofile�ļ�ʱ����Ҫ��������ԭ���ǣ��Է������������ֹ�����ǲ��붪ʧ�����ṩ�����ݣ�����Ҫ����Щ���������ļ��У����������ʲô�������е����ݶ��ǰ�ȫ�ģ����ǻ�����ʹ��
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

class InstrumentationTimer //��׮��ʱ��InstrumentationTimer����׮�ĸ����ǣ�ע�����ǵĴ��벢���з���
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

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();//΢��microseconds,����milliseconds
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
	
		std::cout << m_Name << ":" << (end - start) << "ms\n";
		Instrumentor::Get().WriteProfile({ m_Name, start, end });//ͨ��WriteProfile������ProfileResult��Ϊ������ʹ��������֣���ʼʱ�䣬����ʱ��

		m_Stopped = true;
	}
private:
	const char* m_Name;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	bool m_Stopped;
};

#define PROFILING 1	//����������Ϊ1,��ôPROFILING�����õģ�����ζ�����ǻ���PROFILE_SCOPE����һ��InstrumentationTimer������������Щ��
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name) //���ﶨ��һ���꣬�����name��Ϊ����������װ���ǵ�InstrumentationTimer���ã��������ǻ�ƴ���к�,�������Ǽȿ���Ϊ����ȡһ��Ψһ�����֣��Է������кܶ������Ķ����������ﲻ��Ҫ##(��ȡ���ڱ�������ʹ��)��Ϊ�˰�ȫ�������ʹ����������ֻ�ǰ�timer���к�������һ��
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__) //���û�в�����������PROFILE_SCOPE�꣬������name,������ܺ��������֣����ǿ����ñ����_FUNCTION_������ע��Ҫ�ŵ�#else��
#else
#define PROFILE_SCOPE(name)	//��������ã������������žͿ��ԣ�����ζ��PROFILE_SCOPEû���κδ��룬����������Ч�ذ����ʱ��
#endif

void Function1()
{
	//InstrumentationTimer timer("Function1");
	//PROFILE_SCOPE("Function1");
	PROFILE_FUNCTION();//���PROFILE_FUNCTION()��Ͳ���д������

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
//��Ȼ���ǿ��Դӿ���̨���ҵ���ʱ���������ʾ������Ȼֻ�����飬���һ��ǳ������ҵ�
//�������ǽ���visualization(���ӻ�)

void RunBenchmarks()
{	//�������Ƕ�ջ������һ������������Ҳ�ǿ��Խ�����ӻ���
	//InstrumentationTimer timer("RunBenchmarks");//�����Ϳ��Կ���������׼����ʱ�䣬ͨ����wall duration��
//�����ҵ��ǣ����RunBenchmarks���븴�ƺ�ճ�����ǵ��õ�ÿ�����������ƣ��������ּ�ʱ���벻��������Ҫ�ڳ�����һֱ���еĶ�����Ӧ����һ���򵥵ķ������ر���Щ����Ϊ�������һЩ��������������Ҫͨ��дһЩ�����������������
	PROFILE_FUNCTION();

	std::cout << "Running Benchmarks...\n";
	Function1();
	Function2();
}

int main()
{
	Instrumentor::Get().BeginSession("Profile");//����һ���и����ļ��������ļ�������ʹ��Ĭ�ϲ���result.json��
	/*Function1();
	Function2();*/
	RunBenchmarks();
	Instrumentor::Get().EndSession();
//��BeginSession��EndSession֮���������齫�ᱻ��������ļ��У���ʹ�������ܹ����������ݷֽ�ɶ���ļ�
	std::cin.get();
}


//���ݿ��ӻ�������������˵һֱ�Ƿǳ����õģ����ܹ����������ø���

//���ǿ���ʹ�ùȸ�chrome�������ӻ�������Chrome�Դ���һЩ�Լ��ķ������ߺ������������ߣ������������������ҳӦ�û���ҳ�ġ�
// ����һ���ر�Ľ���Chrome Tracing(edge��Ҳ����),���ܻ���(barebone��׼ϵͳ),Ҳ�ܼ򵥣������ǿ��ӻ������Ͷ�ջ������ͼ
//ֻ��Ҫ�����url��������chrome://tracing����(ע����ο�����Ҫ�򿪿����ߵĵ��Թ���)������Ľ���ǳ���࣬���Ĺ�����ʽ�Ǽ���һ�������������ݵ�json�ļ�
//������һ����ȡ���������ü�ʱ����¼�ļ�ʱ���ݣ��������Ƿ���һ��Chrome tracingϣ����json��ʽ�ļ�

//����json�ļ��󣬽����ϵ�Chrome Tracing��Ϳ��Կ������ӻ���������