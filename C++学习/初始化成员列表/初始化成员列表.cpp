#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Entity
{
private:
	std::string m_Name;

	int m_Score;
public:
	/*Entity()
	{
		m_Name = "Unknown";
	}

	Entity(const std::string& name)
	{
		m_Name = name;
	}*///����һ��Ĭ�ϵĳ�ʼ���ķ�ʽ

	Entity()
		:m_Name("Unknown"),m_Score(0)//ע��������ʼ��ʱ��Ҫ������������ͬ��˳��
	{
	}

	Entity(const std::string& name)
		:m_Name(name)
	{
	}

	const std::string& GetName() const { return m_Name;  }
};

int main()
{
	Entity e0;
	std::cout << e0.GetName() << std::endl;

	Entity e1;
	std::cout << e1.GetName() << std::endl;
 
	std::cin.get();
}

//�ڶ��ֳ�ʼ���б�ķ�ʽ���и�ǿ�Ŀɶ��ԣ�������ı�������ʱ��Ĭ�Ϸ�ʽ��ʼ�����ܻ�ǳ����ң����ѿ������캯���ڸ�ʲô