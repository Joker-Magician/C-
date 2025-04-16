#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<memory>

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print();

};



int main()
{
	{
		std::shared_ptr<Entity>e0;//使用共享指针shared_ptr可以copy

		std::weak_ptr<Entity>e1;

		//注意使用unique_ptr指针不能copy指针，这就会有两个指针指向同一块内存，当其中一个指针释放内存的时候，另一个指针仍然指向该内存就会发生错误
		{
			//两种使用unique_ptr的方法：一是直接调用new进行内存分配
			//std::unique_ptr<Entity>entity(new Entity());//注意这里不能使用隐式转换，因为unique_ptr的构造函数是explicit，需要显示调用构造函数 
			std::unique_ptr<Entity>entity = std::make_unique<Entity>();//二是这种出于异常安全考虑，这样在构造函数碰巧抛出异常的时候更安全，最终不会因为得到一个没有引用空指针而导致内存泄漏


			std::shared_ptr<Entity>sharedEntity = std::make_shared<Entity>();//unique_ptr不直接调用new是因为异常安全，而shared_ptr则是因为它会额外分配一块叫做控制块的内存，用来存储计数，如果调用了new Entity就会有两次内存分配
			//先是new Entity的内存分配，然后是shared_ptr的控制块的分配，如果使用make_shared，就可以把这两部结合起来，这样效率更高
			std::weak_ptr<Entity> weakEntity = sharedEntity;//weak_ptr可以和shared_ptr配套使用，这里所做的和之前复制sharedEntity一样，但之前会增加引用计数,而这里不会增加引用计数
//当你把一个shared_ptr赋值给另一个时，他会增加引用计数，而赋值给weak_ptr则不会，因此如果你不想Entity的所有权，这非常有用。正因不会增加引用计数，所以它不会保证底层对象一直存活
			e0 = sharedEntity;
			e1 = sharedEntity;

			entity->Print();
		}//shared_ptr在这里不会死，当追踪shared_ptr的栈分配对象，当他们死亡后，当它们内存被释放，所有对象都死亡后，这时候才是你的底层Entity被删除的时候
	}
	//这里shared_ptr会死掉
	std::cin.get();
}

//智能指针就是说当你在调用new分配内存时，不用自己去调用delete
//实际上在很多使用智能指针的情况下我们甚至不用去调用new
//智能指针实际是是对原始指针的包装，它会调用new为你分配好内存，然后基于你使用的智能指针，分配的内存会在某一时刻自动释放

//请在使用智能指针时尽量先使用unique_ptr，因为它的消耗较低，如果需要共享在使用shared_ptr，这个因为有一个额外的内存块来计数消耗大一点