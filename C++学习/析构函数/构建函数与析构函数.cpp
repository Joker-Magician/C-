#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Entity
{
public:
	float X, Y;

	Entity()	/*��������*/
	{
		X = 0.0f, Y = 0.0f;
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()	/*��������*/
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}//�������������ڶ�������ʱ�����õ����ⷽ���ͺ���
/*һ����˵�������������ڳ������ʱ�����ã�����һ���ǲ��ɼ��ģ��������ǽ���ͨ��Function�������ã�
�����������ڱ���˺������������ڣ����Կ��Կ���������*/
	/*������Ϊ�����Կ����ͷ��ڴ�*/

	void Print()
	{
		std::cout << X << "," << Y << std::endl;
	}
};

void Function()
{
	Entity e;	//��Ϊ�����������ջ�ϴ����ģ����Ե����������ʱ���ᱻ�Զ�����
	e.Print();
}


int main()
{
	Function();
	std::cin.get();
}

