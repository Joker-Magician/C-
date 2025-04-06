#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Entity
{
public:
	//std::string GetName() { return "Entity"; }
	virtual std::string GetName() { return "Entity"; }//��ǰ������virtual��ʾ����һ���麯��
};													  //����������溯����д�����ҵ���ȷ�ĺ���

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name){ }

	//std::string GetName() { return m_Name; }
	std::string GetName() override { return m_Name; }  //����override���Ա�ʾ�����������д�ˣ����ⲻ�Ǳ���ģ�
};													   //�����Ϻ������ǿ�ɶ��ԣ�������֪�������������д�ˣ������԰�������Ԥ��bug����ƴд�����

void PrintName(Entity* entity)  //�������������Entity������ζ���������Entity�ڲ���GetName��������ֻ����Entity���ڲ�Ѱ�Һ͵���GetName
{										
	std::cout << entity->GetName() << std::endl;
}

int main()
{
	Entity* e = new Entity();
	//std::cout << e->GetName() << std::endl;
	PrintName(e);

	Player* p = new Player("Cherno");
	//std::cout << p->GetName() << std::endl;
	PrintName(p);		//�����������ϣ������������ʶ���������Player��Ҫ����Player���GetName����ʱ����Ҫ�õ��麯����		
						//��������PrintName������ӡ�Ļ�Entity�ͻ��ӡ���Σ���ʵ���������������ǵڶ���Player��ӡӦ�ô�ӡPlayer
/*ԭ����������������������������򷽷������������������ʱ�������ǻ�ȥ��������������͵ķ���*/

	/*Entity* entity = p;//ָ��Entity������ʵ����һ��Player��һ��Player���ʵ��
	std::cout << entity->GetName() << std::endl;*/

	std::cin.get();
}