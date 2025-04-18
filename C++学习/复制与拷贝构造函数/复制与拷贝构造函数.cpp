#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

struct Vector2
{
	float x, y;
};

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];//new char[m_Size]后应该再加上终止符，所以+1
		memcpy(m_Buffer,string,m_Size + 1);//目的、来源、大小，实现复制到缓冲区的功能
		m_Buffer[m_Size] = 0;//也可以手动添加终止符
	}

	String(const String& other)//深度复制(深拷贝)，C++会自动为我们提供一个拷贝复制函数
		:m_Size(other.m_Size)
	{
		std::cout << "Copied String!" << std::endl;

		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()//析构函数解决内存泄露
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);//将其作为友元使其可以访问到函数内部的私有变量
};

std::ostream& operator<<(std::ostream& stream, const String& string)//重载<<操作符
{		//相当于给<<加一个自定义功能，让它可以输出自定义的类型
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& string)//如果直接调用PrintString(String string)，会有三个Copied String!被打印，因为当我们每复制一次字符串，我们在堆上分配内存，复制所有的内存，最后我们释放内存，这完全没有必要
{	//我们真正想做的是，将现有的字符串直接进入这个PrintString函数，因为我们知道我们不需要复制它，不需要它的另一个副本，我们可以直接引用现有的string，这样我们就只有一个副本，复制发生在String second = string。方法就是直接传引用，而String这个类实际上不会修改字符串，所以我们应该标记为const引用
	
	String copy = string;//如果还是要复制就应该这样做
	
	std::cout << string << std::endl;	//如果我们不标记为const,这意味着我们可以直接编辑字符串也意味着我们可以将临时的右值传递到实际的函数中
}

//从上面的案例可知，总是要通过const引用去传递对象，因为你写的函数本身你可以决定是否要复制，在函数的内部，但你没有理由到处复制，他们会拖慢你的程序



int main()
{
	Vector2 a = { 2, 3 };
	Vector2 b = a;
	b.x = 5;//这样不会改变a的值，因为b=a只是相当于建立了一个副本，把值传给了b


	Vector2* a1 = new Vector2();
	Vector2* b1 = a1;//而这样相当于复制了指针，a和b同时指向同一个内存地址
	b1->x = 2;//这会同时影响a和b，这里做的不是影响指针，而是影响内存地址

/*  当你写等号时，即使用赋值操作符，将一个变量设置为另一个变量时，你总是(总是要标记*号)，总是在复制值，
这里总是要打上星号*，是因为引用。当你给其他东西分配一个引用，其实你不能重新分配引用。当你复制引用时，
把一个引用赋值给另有一个引用，你实际上实在改变指向，因为引用只是别名(并没有复制).所以引用除外
    每当你编写一个变量被赋值另一个变量的代码时，你总是在复制。在指针存在的情况下，你在复制指针，也就是内存地址，内存地址的数字，
就是数字而已，而不是指针指向的实际内存*/


	String string = "Cherno";
	String second = string;//这里做的是浅拷贝，C++将由char*和unsigned int组成的Sting类直接复制到一个新的内存地址里面，这个新的内存地址包含了second字符串，
	//即这里有两个String对象有相同的char*的值，即相同的内存指针。所以当作用域结束时，析构函数会被调用，也就是程序试图两次释放同一块内存
	//因此，程序就会崩溃了

	second[2] = 'a';

	//std::cout << string << std::endl;
	//std::cout << second << std::endl;

	PrintString(string);
	PrintString(second);


	std::cin.get();
}