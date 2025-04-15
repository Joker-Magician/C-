#define _CRT_SECURE_NO_WARNINGS
//比如，当定义了一个数学相关的类，然后需要把这两个数学对象相加，那么重载加号操作符就是顺理成章的做法
#include<iostream>
#include<string>

struct Vector2
{
	float x, y;

	Vector2(float x,float y)
		:x(x),y(y){ }

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);/* *this + other 也可以->operator+(other)*/
	}

	/*Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}*/

	//Vector2 operator+(const Vector2& other) const
	//{
	//	return Add(other);
	//}//这样就创造了+运算符

	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}//可以不用操作符+来调用Add函数，而是在Add函数里调用+操作符

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	//bool运算符
	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}
	//不等于取反即可
	bool operator!=(const Vector2& other) const
	{
		//return !operator==(other);
		return !(*this == other);//两种写法是一样的，但上面会看起来很奇怪
	}

};

//对<<进行重载
std::ostream& operator<<(std::ostream& stream, const Vector2& other)//std::ostream&这个是对重载的原始定义
{
	stream << other.x << "," << other.y;
	return stream;
}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position.Add(speed.Multiply(powerup));
	Vector2 result2 = position + speed * powerup;

	if (result1 == result2)
	{

	}

	std::cout << result2 << std::endl;

	std::cin.get();
}

//操作符基本上是一种用来代替函数执行某些事情的符号，不仅包括数学运算符(加减乘除),还包括解引用操作符、箭头操作符、+=运算符、取址操作符、左移操作符(<<)、new与delete、","、"[({})]"等
//总的来说，操作符就是函数,目的是为了让代码更整洁，