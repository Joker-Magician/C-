#define _CRT_SECURE_NO_WARNINGS
//���磬��������һ����ѧ��ص��࣬Ȼ����Ҫ����������ѧ������ӣ���ô���ؼӺŲ���������˳����µ�����
#include<iostream>
#include<string>

struct Vector2
{
	float x, y;

	Vector2(float x,float y)
		:x(x),y(y){ }

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);/* *this + other Ҳ����->operator+(other)*/
	}

	/*Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}*/

	//Vector2 operator+(const Vector2& other) const
	//{
	//	return Add(other);
	//}//�����ʹ�����+�����

	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}//���Բ��ò�����+������Add������������Add���������+������

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	//bool�����
	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}
	//������ȡ������
	bool operator!=(const Vector2& other) const
	{
		//return !operator==(other);
		return !(*this == other);//����д����һ���ģ�������ῴ���������
	}

};

//��<<��������
std::ostream& operator<<(std::ostream& stream, const Vector2& other)//std::ostream&����Ƕ����ص�ԭʼ����
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

//��������������һ���������溯��ִ��ĳЩ����ķ��ţ�����������ѧ�����(�Ӽ��˳�),�����������ò���������ͷ��������+=�������ȡַ�����������Ʋ�����(<<)��new��delete��","��"[({})]"��
//�ܵ���˵�����������Ǻ���,Ŀ����Ϊ���ô�������࣬