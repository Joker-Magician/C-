#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
		func(value);//����ʵ�����ǵ���main�������涨���lambda�Ĵ�����������
}
//lambda�������������ǽ�һ����������һ��api���Ա�����δ����ĳ��ʱ�䣬������Ϊ���ǵ����������
//��Ϊ�������ڲ�֪�����ܵ��������������Ϊ����û������Ҫ�����ݻ��߾������ǻ����������(������Ҫ�ӳٵ����������)�����������������������������Ҫ���������ǵ�������ú�����ʱ������Ҫ�����ĸ�����
//lambda��һ���ܺõķ�������ָ�����������ָ��δ����Ҫ���еĴ���


int main()
{
	std::vector<int> values = { 1, 5, 4, 2, 3 };
	
	//ForEach(values, [](int value) { std::cout << "Value:" << value << std::endl; });


	auto lambda = [](int value) { std::cout << "Value:" << value << std::endl; };//ѧϰC++ʱ���Բο�cppreference.com��վ��ѧϰ
//[]�ǲ������˼�������Ҫ���ⲿ������lambda�����ڲ�������ͨ����һ�����д�ֵ���������ַ���

	int a = 5;
	//�����һ�������ŵ���˼����˵���Ǵ�����δ��ݱ���
	auto lambda1 = [=](int value) { std::cout << "Value:" << a << std::endl; };//[=]��˼�Ǵ������еı�����ͨ��ֵ����
	auto lambda2 = [&](int value) { std::cout << "Value:" << a << std::endl; };//[&]��˼�Ǵ������еı�����ͨ�����ô���
	auto lambda3 = [a](int value) { std::cout << "Value:" << a << std::endl; };//[a]����a��ͨ�����ô���;[&a]����a��ͨ�����ô���

	ForEach(values, lambda);//�������������<functional>���ܻᱨ��

	//lambda��[]�������п�ѡ���η�����mutable�������������޸�ͨ���������ݲ���Ĳ���
	auto lambda4 = [=](int value) mutable{ a = 5; std::cout << "Value:" << a << std::endl; };


	//ʹ��lambda����������ĳ�ֵ��������ҵ�ֵ
	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });//Ѱ�ұ�3�������Ȼ�󷵻����ĵ�������Ҳ�������������ĵ�һ��Ԫ��.�������ʹ�ò���if������ʵ��
	//find_if������<algorithm>ͷ�ļ���
	std::cout << *it << std::endl;

	std::cin.get();
}

//lambda�����������Ƕ���һ�ֽ������������ķ�ʽ
//�����ַ�ʽ��������������Ҫʵ�ʴ���һ������������һ�����ٵ�һ���Ժ�����չʾ����Ҫ���еĴ���
//����ԭ��ֻҪ��һ������ָ�룬�Ϳ�����C++��ʹ��lambda

