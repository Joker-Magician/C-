#include<iostream>
#include<string>

class Entity
{
public:
	virtual void PrintName() {}//有了虚函数这样就有了需要重写的东西，这意味着它是多态类型，我们可以再次使用动态类型转换
};//这是一个真是的实体类，肯定会有虚函数，这也让它更真实一些

class Player : public Entity
{
};

class Enemy : public Entity
{
};


int main()
{
	Player* player = new Player();
	Entity* actuallyPlayer = player;//隐式转换，完成后想把这个再转换成其他类型就很难了，以为这个很有可能是enemy
	
	Entity* actuallyEnemy = new Enemy();

	/*Player* p = (Player*)e1;*/ //这里不能直接放e1,因为这里是一个player玩家，至于它是不是一个enemy敌人我们并不知道，所以我们必须向编译器保证它(e1)是一个玩家player
/*在本例中这样做是危险的，因为e1实际上是enemy，如果把它强制转换成player, 并不是不可以，如果enemy有的函数，player和entity也都有的话，我们试着运行这个函数它可能会没问题
我们甚至可能不会注意到任何问题，但如果我们试着做一些enemy没有，而player所独有的事情(比如访问特定成员变量)，我们的程序很可能会崩溃或做出我们不想做的奇怪事情*/
	
//因此我们不能使用原始类型转换，可以使用static_cast
	//Player* p = static_cast<Player*>(e1);//这是没问题的
	
	Player* p0 = dynamic_cast<Player*>(actuallyEnemy);//这样会失败，因为这实际上是一个Enemy，返回一个NULL
	if (p0)//做检查
	{
	}
	Player* p1 = dynamic_cast<Player*>(actuallyPlayer);//如果使用dynamic_cast，它会告诉我们它需要一个多态类类型。所以我们需要一个虚函数表(见Entity类)
	//这里会成功转换为Player,因为这实际上是一个Player

/*那么编译器是如何知道玩家是玩家，实体实际上是玩家而不是敌人*/
/*要做到这一点，是因为它存储了运行时类型信息(runtime type information)，也就是所谓的RTTI,这虽然增加了开销，但它可以让你做动态类型转换之类的事情*/

	//如果想关闭运行时类型信息，右击项目属性->C/C++->语言->启用运行时信息类型改为否(NO)，然后编译代码，它会给我们警告

//使用dynamic_cast在绝大多数情况下，它们需要RTTI是打开状态
	std::cin.get();
}



//dynamic_cast更像是一个函数，它不像编译时进行的类型转换，而是在运行时计算，正因如此它确实有相关的运行成本

//dynamic_cast是专门用于沿继承层次结构进行的强制类型转换
//但本质上意味着，如果我有一个类，它是另一个类的子类，我想转换为基类型，或者从基类型转换为派生类型，这就是可以使用dynamic_cast的地方

/*假设我们有一个Entity类，游戏中所有实体entity的类，然后我们有玩家类和敌人类，它们都是实体，所以它们都是从实体类派生的。
	如果我只想将玩家对象转回实体对象，玩家本身就是实体对象，因此可以做隐式转换，不需要做casting(强制转换)
	而反过来的话，如果我们有一个实体实例，我们想把它转换成一个玩家，我们不知道它是不是玩家，我们只知道它是一个实体指针，它是一个实体实例，是一个实体对象的实例
(实体对象，指它可以是实体类型也可以是实体，既可以不是玩家也不是敌人，就只是实体，但它也可以是玩家也可以是敌人)，编译器如果相信我们，但是我们错了，它其实是敌人
那么我们尝试访问玩家独有的数据或修改玩家独有数据的函数，我们的程序可以会崩溃，那将是一场灾难。因为这个原因，dynamic_cast常被用来做验证
	所以，如果我们有一个实体实例，它实际上是一个敌人，我们尝试使用dynamic_cast来将其转换成玩家，这个转换会失败，dynamic_cast会返回一个NULL指针，也就是0，然后我
们可以验证它或做任何我们想做的事情，我们可以用它来检查一个对象是否是给定类型。即我可以尝试在实体Entity对象上进行dynamic_cast，将其转换为玩家Player对象，然后检查
它是否返回NULL*/