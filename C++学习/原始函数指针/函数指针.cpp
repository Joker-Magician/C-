#include<iostream>
#include<vector>

void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void HelloWorld_a(int a)
{
	std::cout << "Hello World! Value: " << a << std::endl;
}

void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values,void(*func)(int))
{
	for (int value : values)
		func(value);

}

int main()
{
	//void(*function)();//��������auto�ƶϵ����ͣ���Ȼʵ��functionֻ��һ�����ֿ��Ըı�

	auto function = HelloWorld;//ֱ��auto function = HelloWorld()�ǲ��еģ���Ϊauto�޷��ƶϷ���ֵ��HelloWorld�ķ���ֵ��void
//������������Ϊ��ʵ���ϲ������ڵ��ú����������ڻ�ȡ����ָ�룬�൱��&HelloWorld
//����������CPUָ������Ǳ������ʱ�����ڶ������ļ���ĳ���ط��������������ǵ��������������ʱ������Ҫ����Ҫִ�е�ָ���λ��

	function();

	//���������ܿ��ź���֣���˿���ʹ��typedef��using������function
	typedef void(*HelloWorldFunction)();
	HelloWorldFunction function1 = HelloWorld;
	function1();

	typedef void(*HelloWorldFunction_a)(int);
	HelloWorldFunction_a function2 = HelloWorld_a;
	function2(8);


	//��ʹ�õ�����
	std::vector<int> values = { 1, 5, 4, 2, 3 };//��ʼ���б�
	ForEach(values, PrintValue);//��һ�ֵ��÷�ʽ����������ʽת������û�н�����

	ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
//����ʹ����lambda���亯����ֻ��һ���Եģ����꼴���ĺ�����[]��������ʽ��Ҳ������δ���������q���ಿ�ֺͺ���һ��

	std::cin.get();
}

//����ָ��������C���Ե����ݣ��ǽ�һ��������ֵ��һ�������ķ���

