#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
/*���麯����ʵ����������麯��*/
class Printable
{
public:
	virtual std::string GetClassName() = 0;
};	//ע����Ȼ֮���Գ���Ϊ�ӿڣ�ֻ����Ϊ����һ�����麯�������˶��ѣ�����ʵ������һ����

class Entity : public Printable
{
public:
	virtual std::string GetName() { return "Entity"; }	//����ڻ����е��麯������ʵ�ʺ����壬����ζ������������д����(��Player��)�ǿ�д�ɲ�д��
	std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity,public Printable
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {
	}

	std::string GetName() override { return m_Name; }  
	std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity* entity) 
{
	std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj)			//����ʵ����Ҫһ�����ͣ������ͱ�֤������GetClassName����
{									//������Ҫ�������ṩGetClassName����������ǽӿ�
	std::cout << obj->GetClassName() << std::endl;
}

int main()
{
	Entity* e = new Entity();
	//PrintName(e);

	Player* p = new Player("Cherno");
	//PrintName(p);		

	Print(e);
	Print(p);

	std::cin.get();
}

//���麯���ı����Ϻ����������еĳ��󷽷��ͽӿ���ͬ
/*ԭ���Ͻ������麯���������Ƕ���һ���ڻ�����û��ʵ�ֵĺ�����Ȼ��ǿ������ȥʵ���������*/

/*����������������д���һ��ֻ����δʵ�ַ���Ȼ��������ȥʵ��ʵ�ֹ��ܵ����Ƿǳ��ձ��
  ��ͨ������Ϊ�ӿڡ�
  �ӿھ���һ��ֻ����δʵ�ֵķ�������Ϊһ��ģ����࣬�������ڽӿ���ʵ���ϲ���������ʵ�֣����������޷�ʵ���������*/