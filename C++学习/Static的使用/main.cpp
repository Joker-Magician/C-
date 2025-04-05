#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//static int n = 10;
////int n = 10;
////LINK : 没有找到 E:\github本地仓库\C-\C++学习\x64\Debug\Static的使用.exe 或上一个增量链接没有生成它；正在执行完全链接
////会显示一个链接错误
////一般如果要使用全局变量尽量用static将变量局限于这个.cpp文件中.obj中，不然就会与其他文件乱链接(LINK)，发生错误。
///*注意：一般不建议使用全局变量，它是有害的*/
//
//int main()
//{
//	std::cout << n << std::endl;
//}

/*类/结构里面的static使用*/

struct Entity
{
	static int x, y;
	void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
};

/*  void Print(Entity e)  在类中静态引用Print就相当于这个函数去掉了括号中的Entity e；
	{
		std::cout << e.x << "," << e.y << std::endl;
	}
*/
int Entity::x;
int Entity::y;//这样这些变量就定义了

int main()
{
	Entity e;
	/*e.x = 2;
	e.y = 3;*/
	Entity::x = 2;
	Entity::y = 3;

	//Entity e1 = { 5,8 };
	Entity e1;
	/*e1.x = 5;
	e1.y = 8;*/  /*这样定义实际上是没有意义的，应该像下面那样定义*/
	Entity::x = 5;
	Entity::y = 8;

	//如此改变后就会打印两5和8，
/*因为当在类中用static定义后，任何后面出现的都是那两个变量的副本，
  二者指向同一块存储空间，当下面对变量修改时，上面的变量也改变了，所以打印出两个5和8.
  可以近似理解为相当于定义了一个全局变量*/
//这样就是在Entity这个命名空间中定义了两个变量，他们实际上并不属于命名空间中，但他们仍是类的一部分
//可以理解为在类中定义的全局变量，当在定义新的类时，他们的存储空间并不会被重新分配

	e.Print();
	e1.Print();
	std::cin.get();
}

/*实际用处：
当有一条信息想在所有实例中共享时，可以将该放在相关的类内，而不是到处创建全局变量
*/
