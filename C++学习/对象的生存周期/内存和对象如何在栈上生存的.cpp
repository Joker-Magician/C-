#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()//��������
	{
		std::cout << "Dstroyed Entity" << std::endl;
	}
};

//int* CreateArray()//����ʾ������Ҫ���ؾֲ�������ָ�������
//{
//	int array[50];
//	return array;//һ���뿪������������ջ���ڴ�ͻᱻ����
//}

int* CreateArray(int* arry)
{
	
}

class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr)
		: m_Ptr(ptr)
	{

	}

	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

int main()
{
	int array[50];
	CreateArray(array);//�����ǿ��е� 

	//int* a = CreateArray();//���������ǲ��е�

	{
		Entity e;//����ʵ��ջ�ϴ���������д�������Ĭ�ϵĹ��캯��
		//Entity* e = new Entity();�ڶ��ϴ�����Entity��Զ���ᱻ����
	}//��ջ�ϴ������뿪����������Ǳ����٣��ڴ汻�ͷţ����������������"Destroyed Entity!"
//������������������κζ��������������������

	{
		ScopedPtr e = new Entity;//��ʽת������дΪe(new Entity()),������Ĭ��ʹ�ù��캯��
	}//���뿪���������ʱ��e�����ٻ������������������Entityָ��Ҳ�ᱻɾ����������ʵ����smart_ptr(����ָ��)��unique_ptr(������ָ��)������Ĺ���
//����ʵ�����Զ����졢�Զ������ȹ���
	std::cin.get();
}