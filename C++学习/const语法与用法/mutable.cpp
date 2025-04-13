#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

//mutableʵ���������ֲ�ͬ���÷���һ���Ǻ�constһ��ʹ��(����ս=ռ�˾���������)����һ������lambda���ʽ��ʹ��
//mutable����˼�ǿ��Ըı��

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCout = 0;//��const��һ����÷�
public:
	const std::string& GetName() const 
	{
		m_DebugCout++;
		return m_Name;
	}
};

int main()
{
	const Entity e;
	e.GetName();

	int x = 8;
	auto f = [=]() mutable//��Ҫ��x����ͬ���ô��������������f=[&x]()����Ҳ����ͨ��=�Ա������д�ֵ����
	{
		/*int y = x;
		y++;�����������,���е���*/
		x++;//����ʹ����mutable��������������ˣ�ʵ���Ϻ�����Ĺ���ԭ����һ�µģ��������������Ӽ��
		std::cout << x << std::endl;
	}

	f();
//��������˵,lambda����һ��һ���Ե�С����������д��������ֵ��һ������
	//����x=8,��Ϊ��ͨ����ֵ���ݵ�
	std::cin.get();
}