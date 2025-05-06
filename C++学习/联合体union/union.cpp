#include<iostream>

struct Vector2
{
	float x, y;
};

struct Vector4	//可以看成两个Vector的两种方法
{
	/*float x, y, z, w;*/

/*	Vector2& GetA()	//如果我们不想复制，我们可以返回一个指向vector2的引用，引用的是x的一个类型双关的版本
	{						这是一种方法，另一种方法是使用union
		return *(Vector2*)&x;
	}*/

	union
	{
		/*float x, y, z, w;union只有一个成员变量，所以我们不能让这些浮点数像这样，因为这样意味着x,y,z,w会占用相同的空间*/
		struct //让浮点数xyzw包在这个struct里
		{
			float x, y, z, w;
		};
		//这个结构体是匿名的，它只是一种数据结构，它没有添加任何东西，它的好处是将上面转换为单个成员

		struct//增加一个成员，与上面占相同的存储空间
		{
			Vector2 a, b;
		};
		//现在访问Vector4有两种方法，可以通过x y z w或者a和b,a与x,y的内存是一样的，b将与z,w相同的内存
	};

};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << "," << vector.y << std::endl;
}

int main()
{
	struct Union
	{
		union
		{
			float a;
			int b;
		};
	};

	Union u;
	u.a = 2.0f;
	std::cout << u.a << "," << u.b << std::endl;
//会打印出来2和107××××，因为这个107××××是浮点数形式的2的字节表示，就好像我们取了组成浮点数的内存，然后把它解释成一个整形，这就是类型双关
//这就是union可以做的，它通常被用来做类型双关

	Vector4 vector = { 1.0f,2.0f, 3.0f, 4.0f };
	vector.x = 2.0f;//这里仍然可以正常访问，是因为我没有给结构体起一个名字什么的
	PrintVector2(vector.a);
	PrintVector2(vector.b);
	vector.z = 500.0f;
	std::cout << "----------------" << std::endl;
	PrintVector2(vector.a);
	PrintVector2(vector.b);



	std::cin.get();
}


//联合体union与结构体struct类似，只不过它一次只能占用一个成员的内存
//如果我们有一个结构体，我们声明了4个浮点数，则在这个结构体中我们可以又4*4=16个字节的内存，因为我们有四个成员，当我们不断向类或结构体中添加更多成员时，其内存会不断增长
//而union只能有一个成员，所以如果我们声明4个浮点数，比如abcd，联合体的大小仍然是4个字节,当我们尝试去处理它们，去改变a,b,c,d的值，它们的内存都是一样的,如果让a的值为5,那么d的值也会是5，这就是联合体的工作方式

//对于联合体，你可以向使用结构体或类一样使用它们，也可以给它添加静态函数或者普通函数、方法等等,但不能使用虚函数等一些限制

//通常人们用联合体来做的事情是和类型双关相关的
//当你想给同一变量取两个不同的名字时，它很有用.如我们想要制作颜色RGB,XYZ与RGB，以让我们可以通过两种方式使用它们，X与R、G与Y等等.

//通常union是匿名使用的，但是匿名union不能含有成员函数


//当你有多种方法，或者你想用多种方法来处理相同数据时，union很有用，同样你也可以使用类型双关或者其他，通常union的可读性更强