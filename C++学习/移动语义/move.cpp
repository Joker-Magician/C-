#include<iostream>

class String
{
public:
	String() = default;
	String(const char* string)
	{
		printf("Created!\n");//通过这个结合下面的memcpy，这样我们以后就可以看到我们的代码流了
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);//通过这回基本的memcpy,把所有的数据从源字符串移动到这里的数据缓冲区
	}//这是一个基本构造函数，取一个字符串，分配内存，把所有东西复制到内存缓冲区(buff)中

	String(const String& other)//写一个复制构造函数
	{
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept//使用这个来指定构造函数，这里使用noexcept来指定
	{//通过指定这个构造函数，希望最终当我们执行这个"复制"时，不会复制，它现在变成了移动
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;//我们要做的时复制数据，但我们在这里做的不是分配一个新的数据缓冲区，然后逐个复制所有的数据，将整个数据块复制到这个新的数据块中
//我们所做的只是简单地给指针赋值，所以我们要把指针指向m_Data,other.m_Data这个就是原来的字符串缓冲区的指针，现在我们说，我们在这个新的字符串实例中创建的指针，它实际上指向相同的数据
//所以不是分配一个新的数据块，然后把所有东西都复制进去，这实际上指向老的字符串的同一个数据块
	
		other.m_Size = 0;
		other.m_Data = nullptr;
//通过这样做我们算是创建了一个空对象，这个旧的字符串现在基本上时一个空的状态，当旧字符串实例被销毁时，这个delete m_Data实际上会删除nullptr,显然删除nullptr相当于啥也没干，因为没东西可被删除的，这个指针是指向的nullptr
//所以我们实际上只是接管了那个旧的字符串，而不是通过赋值所有的数据和分配新的内存来进行深度复制(深拷贝)，我们实际上做了一个浅拷贝，我们只是重新链接了指针
	}

	~String()
	{
		printf("Destroyed!\n");
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)//因为最后没有终止符所以需要循环遍历这个数组，并打印出来
			printf("%c", m_Data[i]);

		printf("\n");
	}
private:
	char* m_Data;//注意因为这个例子不需要所以后面没有加终止符nullptr,一般写时需要加上
	uint32_t m_Size;
};

class Entity
{
public:
	Entity(const String& name)
		: m_Name(name)
	{
	}
//为了确保上面指定的构造函数能够工作，我们还需要确保Entity有一个构造函数，它接受一个临时值
	Entity(String& name)
		//: m_Name((String&&)name)//为了让它使用move构造函数，这里必须这样显式地将它转换为一个临时对象，不然仍然会有有一个copied
		: m_Name(std::move(name))//在实践中，你不会像这样将它转换为右值引用，相反，你可以使用一个叫做std::move的东西，它本质上做同样的事情
	{
	}

	void PrintName()
	{
		m_Name.Print();
	}
private:
	String m_Name;
};
//这里的重点是，我们没有使用这个复制构造函数来分配一个新的内存块，然后复制，我们只是成功地移动了它，所以我们仍然只有一个分配

int main()
{
	Entity entity(String("Cherno"));//使用了显示构造,而这里的'Cherno'不是一个左值，它没有赋值给任何东西，它只是作为这个Entity构造函数的一个参数
	entity.PrintName();

	std::cin.get();
}


//移动语义本质上允许我们移动对象，这时右值引用的最大用处之一。这在C++11引入右值引用，这是移动语义所必需的
//基本思想是，有很多情况下，我们不需要或者不想把一个对象从一个地方复制到另一个地方，但又不得不复制，因为这是唯一可以复制的地方
//例如，如果我把一个对象传递给一个函数，那么它要获得那个对象的所有权，我别无选择，我只能复制。当我想从函数返回一个对象时也是一样的，我仍然需要在函数中创建那个对象，然后返回它，也就是我又要复制数据了
//现在有了一种叫做返回值优化的东西可以对这部分进行优化，让它不再是问题
//但在第一个例子中，如果我需要传入一个对象，这个对象放入某个函数，而这个函数需要得到这个对象的所有权或者其他，我仍然需要再当前堆栈帧中构造一个一次性对象，不管它在哪里，然后将它复制到我正在调用的函数中
//这并不理想，因为我不需要它在这里，我需要它在那里，但我不能在那里构造它，因为我需要现在这里构造它，然后把它传递进去,这会变得一团糟。
//当然，如果你的对象只是由一对整数或类似的东西组成，那么复制也没什么不可以的，但如果你的对象选哟堆分配内存之类的(比如如果它是一个字符串，如果你需要复制它，你需要创建一个全新的堆分配)，这就不好了，这会成为一个沉重的复制对象
//这就是移动语义的用武之处，如果我们只是移动对象而不是复制它，那么性能会更高
