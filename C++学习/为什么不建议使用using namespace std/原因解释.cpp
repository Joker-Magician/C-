#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<print>

//ע����using namespace���ԣ�����Զ��Ҫ��ͷ�ļ���ʹ�ã�Ҳ������ʹ�ñ�׼���е������ռ䣬��Ȼ�ǳ��������Լ�������һЩ��ͬ�������ռ��еĺ�������
//�ǳ�����ʹ���뱨���������Ա�����úʹ���ʹ�õ����ԣ�������С�����ռ��������ʹ��(����if������ʹ�õ�)

//һ��Ӧ�ðٷְٱ���ľ�����ͷ�ļ���ʹ��using namespace,��Զ��Ҫ������������
//����ʹ��using namespace,����ֻ��using�Լ��Ŀ⣬���Բ����stdʹ��
//���ȷʵ��Ҫʹ��using��������һ����С����������ʹ�ã���СҲ����һ��if�����������ʹ�ã����������Ҳ������һ��cpp�ļ����ڲ�ʹ����

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{//��˹��������
	for (int value : values)
		func(value);
}

void for_each(const std::vector<int>& values, const std::function<void(int)>& func)
{//����������
	for (int value : values)
		func(value);
}

namespace apple {

	void print(const std::string& text)
	{
		std::cout << text << std::endl;
	}

}

namespace orange {
	
	void print(const char* text)
	{//���orange���������ǽ�text��ֵ��һ���ַ����У�Ȼ����ַ�����������Ȼ���ӡ����
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}

}


int main()
{	
#if 0
	//���⴮û��using namespace��ԭʼ�������Һ����׾���ָ����ʹ�õ��Ǳ�׼ģ����C++�⣬���þͿ���֪������stdǰ׺�Ķ����������Ա�׼��
	std::vector<int>values = { 1, 5, 4, 2, 3 };
	//C++(��׼��)һ��ϲ������������������
	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
	std::cout << *it << std::endl;

	int a = 5;

	auto lambda = [=](int value) { std::cout << "Value:" << a << std::endl; };

	ForEach(values, lambda);

	{
		using namespace std;

		vector<int>values = { 1, 5, 4, 2, 3 };
		auto it = find_if(values.begin(), values.end(), [](int value) { return value > 3; });
		cout << *it << endl;

		int a = 5;

		auto lambda = [=](int value) { cout << "Value:" << a << endl; };

		for_each(values, lambda);
	//��������������ʹ�����������������ĺ���(��for_each��find_if)�ͻ���ѷ����ĸ���std(��׼��)����ģ��ĸ����Լ��������ռ��������ġ������Ķ������ø�������
	}
#endif
	{
		using namespace apple;
		using namespace orange;

		apple::print("Hello");

		print("Hello");//��ͬʱʹ����using namespace orange��using namespace appleʱ���ӡ����olleH
		//Hello��һ��const char�����������һ��string����Ϊ���û��orange�����ռ䣬��ôapple������һ����ʽת������������������orange������print���������ƥ�䣬����Ҫ�κ�ת��
		//��Ȼ������������error��warning�������������ȫ��ͬ�ĺ������ⲻ��error����������������ʱ����
	}

	{
		apple::print("Hello");

		orange::print("Hello");//��ͬʱʹ����using namespace orange��using namespace appleʱ���ӡ����olleH
		//Hello��һ��const char�����������һ��string����Ϊ���û��orange�����ռ䣬��ôapple������һ����ʽת������������������orange������print���������ƥ�䣬����Ҫ�κ�ת��
		//��Ȼ������������error��warning�������������ȫ��ͬ�ĺ������ⲻ��error����������������ʱ����
	}

	std::cin.get();
}

//ʹ�������ռ�����ã��������ռ�ܳ������Լ��������ռ�(�Լ�����Ŀ�ļ��еķ��Ŷ�����������ռ���)������ĳЩ��������Ҫ����������Щʱ����ʹ�������ռ�

/*����������������*/
/*��˹����������ÿ����������ĸ��д���м䲻���пո���»��ߵȣ����շ���������շ�����ĸСд*/
/*����������(snake case��ʽ:Сд���ʣ��м����»�������)*/