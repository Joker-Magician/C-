#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	/*explicit*/ Entity(const std::string& name)
		:m_Name(name), m_Age(-1) {}//������Ϊ-1����ζ��������Ч�ģ�û���ṩage

	/*explicit*/ Entity(int age)
		:m_Name("Unknown"), m_Age(age) {}
};

//�������Ҫ��һ����������һ��Entity�������������ʾ�ĵ���������캯��
//explicit�������ʽת����explicit�ؼ��ַ��ڹ��캯��ǰ��,�������������һ����������һ��Entity����,����ͱ�����ʾ�ĵ���������캯��

void PrintEntity(const Entity& entity)
{
	//Printing
}

int main()
{
	PrintEntity(22);
	PrintEntity(std::string("Cherno"));//��Entity("Cherno")Ҳһ��//����("Cherno")����������������Ϊ����ַ�������std::sring���͵ģ�����һ��char����
//Ϊ��������ܹ�����C++��Ҫ������ת����һ���Ǵ�const char���鵽string��Ȼ���Ǵ�stringת��Entity����ֻ������һ�ε���ʽת��

	Entity a = std::string("Cherno");// a("Cherno")
	Entity b = 22;//b(22)������ʵ�����ķ�������ͬ��
//����b����������ֵ��һ�����Σ���ʵ��ת������Entity�ͣ��������ʽת������ʽ���캯��
	std::cin.get();
}

//�����������͵�ת��C++����������һ����ʽ��ת��