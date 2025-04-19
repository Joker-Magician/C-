#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Entity
{
public:
	void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr		//����->�������������Զ��������ʹ����
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		:m_Obj(entity)
	{
	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator->()
	{
		return m_Obj;
	}

	const Entity* operator->()const
	{
		return m_Obj;
	}
};

struct Vector3
{
	float x, y, z;//float����һ��ռ�ĸ��ֽڣ���Ϊx�ǵ�һ����ƫ����Ϊ0��y��ƫ����Ϊ4��z��ƫ����Ϊ8
};

int main()
{
	Entity e;
	e.Print();

	Entity* ptr = &e;
	Entity& entity = *ptr;//������Ҫʹ��*��������ptr(������)��Ȼ����entity�滻����ſ���
	entity.Print();//ע�����ﲻ��ʹ��ptr.Print()����Ϊptr��һ��ָ�룬Ҳ����һ����ֵ(���Ƕ���Ҳ�Ͳ��ܵ��÷���)
	(*ptr).Print();//Ҳ��������������

	ptr->Print();//ʹ�ü�ͷ�������������滻��Щ����ʵ���Ͼ��൱���������Entityָ��

	//����->���÷�
	ScopedPtr entity1 = new Entity();//����Ҳ����д��Entity* entity1 =new Entity()
	const ScopedPtr entity1 = new Entity();//z����const�汾
	entity1->Print();
	//���Լ��������У������Լ��Ĺ��캯������ʵ���Զ���

	//���ü�ͷ����������ȡ�ڴ���ĳ��������ƫ����
	int offset = (int)&((Vector3*)nullptr)->x;//��0ת��ΪVector3����,Ȼ���ü�ͷ������x����õ���Щ�ڴ�Ĳ��֣���ǰ�����&����ȡx���ڴ��ַ��
//Ȼ��õ����x��ƫ����(��0��ʼ,0Ҳ����д��nullptr),������ת����int���ͣ���������offset	
	std::cout << offset << std::endl;


	std::cin.get();
}