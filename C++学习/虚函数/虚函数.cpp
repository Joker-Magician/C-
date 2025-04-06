#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Entity
{
public:
	//std::string GetName() { return "Entity"; }
	virtual std::string GetName() { return "Entity"; }//在前加上了virtual表示这是一个虚函数
};													  //这样如果下面函数重写了能找到正确的函数

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name){ }

	//std::string GetName() { return m_Name; }
	std::string GetName() override { return m_Name; }  //加上override可以表示这个函数被重写了，但这不是必须的，
};													   //但加上后可以增强可读性，让我们知道这个函数被重写了，还可以帮助我们预防bug，如拼写错误等

void PrintName(Entity* entity)  //这个函数参数是Entity，这意味着它会调用Entity内部的GetName函数，它只会在Entity的内部寻找和调用GetName
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
	PrintName(p);		//这里如果我们希望编译器能意识到传入的是Player，要调用Player类的GetName，这时就需要用到虚函数了		
						//这样调用PrintName函数打印的话Entity就会打印两次，而实际上我们期望的是第二次Player打印应该打印Player
/*原因是如果我们在类正常声明函数或方法，当调用这个方法的时候，他总是会去调用属于这个类型的方法*/

	/*Entity* entity = p;//指向Entity，但他实际是一个Player，一个Player类的实例
	std::cout << entity->GetName() << std::endl;*/

	std::cin.get();
}