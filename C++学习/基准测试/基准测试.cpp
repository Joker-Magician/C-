#include<iostream>
#include<memory>

#include<chrono>
#include<array>

class Timer
{
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();//�õ���ǰ��ʱ�䣬���Ϳ�ͨ�����ŵ�now�ϲ鿴
	}

	~Timer()
	{
		Stop();
	}

	void Stop()//���stop�����������������Զ����ã�����ϣ������ǻ����������
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();//����ת������ȷʱ�䣬Ȼ�����(count),����startTime΢�������microseconds����ʼʱ����΢������ʾ
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();//����ת������ȷʱ�䣬Ȼ�����(count),����startTime΢�������microseconds����ʼʱ����΢������ʾ

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << duration << "us(" << ms << "ms)\n";
	}
/*�����Ϳ������ܶ��£����Դ�stop����������ݵ�ĳ�ָ������У����ٲ�����ʵ�ʽ����������һ���ǳ����ϵͳ����������е����ݵ�һ���ļ��У����ܶ����飬������Ϳ��Բ鿴��
�ڵ����Ĺ����У��鿴�����е������������ĵ�ʱ�䣬�����������һ����Ϸ����ῴ��ÿһ֡�����ѵ�ʱ�䣬�Լ�ÿһ֡����д��������Щ��ʱ�Ƚ϶�*/

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;//����ǰʱ��洢�����˽�г�Ա������

};
//��������󱻴���ʱ���ǿ�ʼ��ʱ��������������ʱ����ֹͣ��ʱ�����������ν��RAII(��Դ��ȡ��ʼ��,Resource Acquisition Is Initialization)


int main()
{
	int value = 0;
	{
		Timer timer;
		for (int i = 0; i < 1000000; i++)
			value += 2;
	}
	/*ע�⣬Ҫȷ�����������Ķ���������ʵ���ϱ�����Ĵ��룬��ǳ���Ҫ����ΪC++�����������Ż����룬������룬������ȫ���Ĵ���*/
	/*��ͨ���һ��鿴����������Ա�debug��release�Ĳ��release�����Ż�����������˺ܶ࣬��forѭ���У���û�мӷ�ָ�ʵ�ʷ������ǣ������������⴮���벢��ʶ�����Ⲣ����Ҫ������ʱ���㣬���ǽ������Ż���
	ֱ���ڱ���ʱ�ͼ�������ˣ�ֻ��Ҫ��ӡ�������������
	�������ʱ���Ľ��������ȫ���õģ���Ϊɶû���������ǻ��������ڲ�����ӡ��Ҫ�೤ʱ�䡣���ԣ��������ڲ���ʲô����Ҫȷ����ȷʵ������Щ���飬�㲢�����ڲ���ʲô��û�з��������飬��Ϊ������ʵ���ϻ�ǳ������ظı���Ĵ���*/

	std::cout << value << std::endl;

	//��������ָ�������(������һ������Ĳ��ԣ���Ϊ��������û�з������ݣ�Ҳû����������ָ�������������������)
	struct Vector2
	{
		float x, y;
	};
	//ע��Ҫ���ӽ������������ĵĴ��룬���ǲ������Ĵ�������
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
//�ڵ���ģʽ�·�����make_Shared��new_Shared��࣬������debug�·����ģ���Բ������ܲ��Ǻܺã���Ϊ���кܶ����İ�ȫ��ʩ��Ҫʱ��
//��releaseģʽ�·������ᷢ�ֳ��˶����Լӿ��ˣ�����make_Shared���Ա�new_Shared����

	__debugbreak();//���öϵ㣬����visual studioר�Ž�����windows�ĺ���,�����������жϱ��룬�������ǾͲ��������������룬Ȼ���Լ����öϵ���
}

//��׼���ԣ�ÿ���˶���ÿ���˵ķ�������������ô��˷�������������ܱ�����ܻ����ӿ���
//��Щ��ϲ�������������������ߣ���Щ��ϲ����diamond�����Ǳ��������������ü�ʱ��֮��Ķ�������Щ��ϲ���������ǵĳ��򣬰ѳ����װ��һ����ʱ���У�Ȼ�������Ҫ���Ե��ض�����

//��׼���Բ��������������Դ�����л�׼���ԵĹ��ߣ��������Ҫ����һ��C++��������ܣ�����δ��뱾�����Ҫ��"��ȷ"��ȥд
