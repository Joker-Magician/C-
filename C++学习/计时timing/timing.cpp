#include<iostream>
#include<chrono>
#include<thread>

//ʹ������������������֮��ķ��������Զ�Ϊ�Ҽ�ʱ
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

		float ms = duration.count() * 1000.0f;//��Ϊʱ��ܶ�������ms,������õ�����
		std::cout << "Timr took " << ms << "ms" << std::endl;
	}
};//������һ���򵥵Ľṹ����м�ʱ���Զ���ӡ�����ǻ����������������ģ���������Ҫ���ľ����ں����Ŀ�ͷ��������

void Funtion()
{
	Timer timer;

	/*for (int i = 0; i < 100; i++)
		std::cout << "Hello" << std::endl;*/

	for (int i = 0; i < 100; i++)
		std::cout << "Hello\n";//���ʱ���������֮һ����Ϊstd::endl����ΪĳЩԭ������ʱ��
}
//�������Ļ�׼���Եȵȣ���Ӧ����releaseģʽ�¶����м���

int main()
{
	using namespace std::literals::chrono_literals;//�����������ʹ��1s

	auto start = std::chrono::high_resolution_clock::now();//��ʾ��ʼʱ��
	std::this_thread::sleep_for(1s);//���߳�����1s
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;//std::chrono::duration<float>��Ϊ�߾���ʱ��
	std::cout << duration.count() << "s " << std::endl;
	//�̵߳�����ʱ�䲻�ܱ�֤�����������˯��ʱ�䣬���Ҽ�ʱ����Ҳ����ʱ�俪��

	Funtion();

	std::cin.get();
}

//��ʱ��������ϣ��ĳЩ�������ض�ʱ�䷢��������ֻ���������ܻ�����׼���Կ�����Ĵ������еö�춼������
//��C++11��������chrono������C++���һ���֣�����Ҫȥʹ�ò���ϵͳ�⡣��C++11֮ǰ����Ҫ��һ���ǳ���ȷ�ļ�ʱ����������Ҫʹ�ò���ϵͳ�⣬����windows����һ��QueryPerformanceCounter�Ķ���
//������Ȼ����ʹ����Щ������ʵ�ϣ��������Ҫ����ؿ��Ƽ�ʱ������CPU�ļ�ʱ�����������ʹ��ƽ̨�ض��Ŀ�
 