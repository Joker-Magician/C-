#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Entity
{
private:
	std::string m_Name;

	int m_Score;
public:
	/*Entity()
	{
		m_Name = "Unknown";
	}

	Entity(const std::string& name)
	{
		m_Name = name;
	}*///这是一种默认的初始化的方式

	Entity()
		:m_Name("Unknown"),m_Score(0)//注意这样初始化时需要按照与上面相同的顺序
	{
	}

	Entity(const std::string& name)
		:m_Name(name)
	{
	}

	const std::string& GetName() const { return m_Name;  }
};

int main()
{
	Entity e0;
	std::cout << e0.GetName() << std::endl;

	Entity e1;
	std::cout << e1.GetName() << std::endl;
 
	std::cin.get();
}

//第二种初始化列表的方式具有更强的可读性，当定义的变量过多时，默认方式初始化可能会非常混乱，很难看出构造函数在干什么