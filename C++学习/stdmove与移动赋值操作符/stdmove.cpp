#include<iostream>

class String
{
public:
	String() = default;
	String(const char* string)
	{
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String& other)
	{
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept //这个移动构造函数，它接受右值引用，这是一个临时对象
	{	
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}//使用这个构造函数，这一块代码的作用是，从other窃取资源，换句话说，这就是所谓的移动

	String& operator=(String&& other) noexcept //赋值操作符
	{/*因为这里并没有像上面的移动构造函数中那样构造一个新对象，我们实际上是把另一个对象移到我们自身，移到这个当前的对象中。*/
		printf("Moved!\n");
/*通常在赋值操作符中，你还需要确保这个对象，也就是当前对象不等于另一个对象，即不做像这样dest = (std::move(dest))的操作,因为如果这些对象是相同的，那么就没有必要移动，即你视图把这个对象移动到它自己里面，但它已经在那里了，就没必要移动了*/
/*通常实现这种操作使用this != &other来实现*/
		if (this != &other)
		{
			delete[] m_Data;

			m_Size = other.m_Size;
			m_Data = other.m_Data;//显然我们需要覆盖当前对象，因为当前对象可能已经分配了一些内存。显然如果我们这样做，如果我们设置m_Data等于另一个指针，我们就造成了内存泄漏，因为我们没有办法删除旧的数据

			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		
		return *this;//*this指当前对象
	}
//换句话说，我们只在它们不相等的时候移动，如果它们是同一个对象，那么我们不要做任何事情。如果它们是不同的对象，但数据是相同的，你仍然需要进行移动，因为你仍然在移动一些其他的对象到你自己这里
//所以这个和那种要拷贝的赋值操作符不太一样，如果数据刚好匹配，你就不需要做任何事情，否则你仍然需要做
	~String()
	{
		printf("Destroyed!\n");
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);

		printf("\n");
	}
private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity//Entity是一个额外的间接层，它本身作为一个例子，展示了如何实际使用String类的move
{
public:
	Entity(const String& name)
		:m_Name(name)
	{
	}

	Entity(String&& name)
		:m_Name(std::move(name))
	{
	}

	void PrintName()
	{
		m_Name.Print();
	}
private:
	String m_Name;
};

int main()
{
	//Entity entity("Cherno");
	//entity.PrintName();

	//String string = "Hello";//为了让它可以以使用上面移动构造函数，则我需要确保这个hello字符串，现在变成临时的
	/*String dest = (String&&)string; */	//所以这里选哟使用强制类型转换，这里发生的是，它现在在用一个构造函数构造一个新的字符串，这个构造函数接受右值引用String&&
//这里最后我现在把这个hello字符串移动到这个新的目的地(dest)
//但这并不是一种优雅的方式，它也不是对每个类型都适用，例如，如果我们有一个auto类型，而这个实际类型不能通过我们像这样静态地写代码来推断。
//所以我们要做的是，我们使用一个稍微灵活一点的函数，在编译时，它会找出输入的是什么类型，这个函数时std::move

	//String dest(std::move(string));
/*这里如何写这些代码并不重要(无论是用赋值方式还是构造函数方式)，如果使用赋值操作，问题是我们在这里是创建一个新对象，而不是在这里发生移动赋值操作，我们把变量类型放到前面，然后是变量名，这是一个全新的对象，它正在被构造，因此它会使用移动构造函数。
赋值操作符，只有当我们把一个变量赋值给一个已有的变量时才会被调用*/
/*dest = std::move(string),在这种情况下，赋值操作符会被调用，因为dest是一个已经存在的变量，不要忘记运算符实际上就像一个函数，所以当你在这里调用=运算符时，也就是对现有变量的赋值运算符，就像有一个assign函数一样(dest.assign(std::move(string))),*/

//测试一下上面
	String apple = "Apple";
	String dest;
	//String dest = std::move(apple);这是移动构造函数

	std::cout << "Apple: ";
	apple.Print();
	std::cout << "Dest: ";
	dest.Print();

	dest = std::move(apple);//这是赋值运算符
	//dest.operator(std::move(apple));//赋值操作符与使用构造函数的区别,通过使用这个运算符，它就像我们写.operator=,并像调用函数一样调用它，在这里显然是不行的，因为我们实际上并没有调用赋值操作符，我们只是构造了一个新字符串，使用了一个临时值，
	//这就是为社么调用的是移动构造函数，而这里我们实际上是在调用一个函数，这是一个重要的区别。虽然它们看起来都像赋值运算符，但实际上是不同的

	std::cout << "Apple: ";
	apple.Print();
	std::cout << "Dest: ";
	dest.Print();

	std::cin.get();
}

//移动语义能够将一个对象移动到另一个对象上，这其中涉及到了两个关键部分，其中之一是std::move,另一个是move assignment operator(移动赋值操作符)，这是一个赋值操作符，当我们想把一个对象移动到一个已有的对象中时
//在移动语义中的内容谈到了移动构造函数，但本部分将会谈到如果我们想要将现有对象移动到另一个对象中，而不是构造一个新对象，会发生什么

//总而言之，移动赋值操作符是你想要包含在类中的东西，当你包含一个移动构造函数时，因为它当然是想要将一个对象移动到一个现有的变量中，它基本上时五法则的一部分，还有三八至，五法则包含了所有的新移动语义。

//std::move是你想要将一个对象转换为临时对象是要做的。换句话说，如果你需要把一个已经存在的变量变成临时变量，你可以标记它，表示你可以从这个特定的变量中窃取资源，这使我们能够在现有的变量上执行移动操作
//如果你在创建一个新变量，如果是在函数参数中或在移动构造函数中创建，那么它已经是一个临时变量，这是可以的。但是如果你有一个已经存在的变量，比如这个apple的例子，这是一个已经存在的变量，你需要确保使用std::move来将它转换成一个临时变量
//这样你就可以使用移动构造函数或移动赋值操作符，从哪个变量中获取资源，并进行移动


//C++三发则：如果需要析构函数，则一定需要拷贝构造函数和拷贝赋值操作符；C++五法则：为支持移动语义，又增加了移动构造函数和移动赋值运算符