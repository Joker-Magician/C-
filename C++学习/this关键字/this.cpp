#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Entity;

void PrintEntity(Entity* e);
void PrintEntity_1(const Entity& e);

class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		Entity* e = this;//Entity*�����this�����ͣ���������ŵ�this�ϻᷢ������ʵ��Entity* const
		//���Ҳ����д��Entity* const e = this,�������ֻ�������ֵ��һ��Entity*,��Ϊconst��ζ���ұߵ�this���������Ǹ������¸�ֵ
		
		this->x = x;
		this->y = y;

		PrintEntity(this);//�����ͻᴫ���Ѿ�������x��y�ĵ�ǰʵ��
		PrintEntity_1(*this);//�������һ���������ã���ô��Ҫ��������н�����this
	
		//delete this;//ע�⣺�뾡����������������Ϊ�����ڴ���ĳ�Ա�������ͷ��ڴ棬ִ�к���ȥ�����κγ�Ա���ݶ���ʧ�ܣ���Ϊ�ڴ��Ѿ����ͷŵ���
	}

	int GetX() const
	{
		const Entity& e = *this;

		return x;
	}

};

void PrintEntity(Entity* e)
{

}

void PrintEntity_1(const Entity& e)
{

}

int main()
{
	std::cin.get();
}

//this�ؼ��֣�ͨ�������ǿ��Է��ʳ�Ա��������Ա������������ĳ����ĺ����򷽷�
//�ں����ڲ������ǿ�������this��this��ָ��������������ĵ�ǰ����ʵ����ָ��
//���ԣ����ǿ�����C++��дһ��������һ���Ǿ�̬�ķ�����Ϊ�˵������������������Ҫ��ʵ����һ������Ȼ����ȥ������������������������������һ����Ч���������ã���this�ؼ��־���ָ���Ǹ������ָ��