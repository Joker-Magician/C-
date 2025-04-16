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
		Entity* e = this;//Entity*这就是this的类型，如果把鼠标放到this上会发向它其实是Entity* const
		//因此也可以写成Entity* const e = this,大多数人只会把它赋值给一个Entity*,因为const意味着右边的this不允许我们给他重新赋值
		
		this->x = x;
		this->y = y;

		PrintEntity(this);//这样就会传入已经设置了x和y的当前实例
		PrintEntity_1(*this);//如果传入一个常量引用，那么需要在这里进行解引用this
	
		//delete this;//注意：请尽量避免这样做，因为你正在从你的成员函数里释放内存，执行后，你去访问任何成员数据都会失败，因为内存已经被释放掉了
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

//this关键字，通过它我们可以访问成员函数，成员函数就是属于某个类的函数或方法
//在函数内部，我们可以引用this，this是指向这个函数所属的当前对象实例的指针
//所以，我们可以在C++中写一个方法，一个非静态的方法，为了调用这个方法，我们需要先实例化一个对象，然后再去调用这个方法，所以这个方法必须有一个有效对象来调用，而this关键字就是指向那个对象的指针