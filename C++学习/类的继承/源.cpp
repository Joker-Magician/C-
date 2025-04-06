#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

class Player : public Entity  /*��˱�����˼̳У��̳���Entity�����б���*/
{							 //Playerӵ��Entity���������ݣ��������࣬Player��Entity��������
public:						 //��������һ�������������������һ��
	const char* Name;

	void PrintName()
	{
		std::cout << Name << std::endl;
	}
};

int main()
{
	std::cout << sizeof(Player) << std::endl;
	std::cout << sizeof(Entity) << std::endl;

	Player player;
	player.Move(5, 5);
	player.X = 2;

	std::cin.get();
}