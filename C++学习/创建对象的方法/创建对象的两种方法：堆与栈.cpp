#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//Ӧ�ó������ڴ��Ϊ������:����ջ,�Լ�����һЩ����
using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknow"){}
	Entity(const String& name): m_Name(name){}

	const String& GetName() const { return m_Name; }
};

void Function()
{
	int a = 2;
	Entity entity = Entity("Charno");
}//�������������ʱ�����ջ�ṹ�ͻᱻ���٣�ջ�ϴ��������б���������ʧ

int main()
{
	Function();//�����ǵ���Functionʱ����Ϊ�������������һ�����������������оֲ�������ջ�ṹ
	
	Entity* e;
	{
		Entity entity ("Cherno");//��ʵ���Ͼ��ǹ��캯��
		e = &entity;//�����Ҫ���Cherno���������������������Ͳ��ܰ������䵽ջ�ϣ����Ǳ�����䵽����
		std::cout << entity.GetName() << std::endl;//���ⲻ����䵽ջ�ϵ�ԭ������ǣ�������entity̫��ͬʱ���ǿ����кܶ��entity�����ǿ��ܾ�û���㹻�Ŀռ������з��䣬��Ϊջͨ���Ǻ�С�ģ�һ����һ���ף���ȡ�������ƽ̨�ͱ�����
	}

	Entity* e;
	{
		Entity* entity = new Entity("Cherno");	//�ڶ��Ϸ�������Ҫ��Entity*������Entity���ͣ�Ȼ��ʹ��new����entity��ֵ�����������������Ǹ�ָ�����new����ؼ���
		e = entity;	//��������new����ʵ���Ͼ��Ƿ������ڶ��Ϸ���ռ䣬Ȼ�����new Entityʵ�ʻ᷵��һ��Entityָ�룬��������Ҫ������Entity*����
		std::cout << entity->GetName() << std::endl;
		//delete entity;	//ʹ����new��Ҫ������߱��������ڴ��ͷŵ�����Ȼ������ڴ�й¶
	}

	std::cin.get();
	delete e;//���ֻ�е�����delete�Żᱻ�ͷŵ�����ʹ�ŵ�cin.get��Ҳһ��

}

//�����Ķ���ǳ��ǳ��󣬻�����Ҫ��ʾ�ؿ��ƶ�����������ڣ����ڶ��ϴ���
//�������������������Ǿ���ջ�Ϸ��䣬����򵥣����Զ����գ�Ҳ����
//���Ҫ�ڶ��ϴ�����һ��Ҫ����delete�ͷŵ��ڴ�