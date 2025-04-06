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

class Player : public Entity  /*如此便完成了继承，继承了Entity的所有变量*/
{							 //Player拥有Entity的所有内容，甚至更多，Player是Entity的派生类
public:						 //当创建了一个子类后，它会包含父类的一切
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