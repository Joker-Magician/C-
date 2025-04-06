#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
/*纯虚函数其实就是特殊的虚函数*/
class Printable
{
public:
	virtual std::string GetClassName() = 0;
};	//注意虽然之所以称它为接口，只是因为它有一个纯虚函数，仅此而已，但它实际上是一个类

class Entity : public Printable
{
public:
	virtual std::string GetName() { return "Entity"; }	//如果在基类中的虚函数带有实际函数体，这意味着在子类中重写函数(如Player类)是可写可不写的
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

void Print(Printable* obj)			//这里实际需要一种类型，该类型保证类内有GetClassName函数
{									//我们需要这种能提供GetClassName函数，这就是接口
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

//纯虚函数的本质上和其他语言中的抽象方法和接口相同
/*原理上讲，纯虚函数允许我们定义一个在基类中没有实现的函数，然后强制子类去实现这个函数*/

/*在面向对象程序设计中创建一个只包含未实现方法然后交由子类去实际实现功能的类是非常普遍的
  这通常被称为接口。
  接口就是一个只包含未实现的方法并作为一个模版的类，并且由于接口类实际上不包含方法实现，所以我们无法实例化这个类*/