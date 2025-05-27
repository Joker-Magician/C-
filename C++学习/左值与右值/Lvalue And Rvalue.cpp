#include<iostream>
#include<string>

int GetValue()
{
	return 10;
}

int& GetValue1()//int&这个叫左值引用
{
	static int value = 10;//这样我们就需要为我的值提供某种存储空间，比如使用一个静态int,然后返回它
	return value;
}//这种情况，会因为这返回的是一个左值引用，所以可以给它赋值，下面的表达式也就没问题了，这就是左值引用

void SetValue(int value)
{
}

void SetValue1(int& value)
{
}

void SetValue2(const int& value)
{
}


void PrintName1(std::string& name)
{
	std::cout << name << std::endl;
}

void PrintName2(const std::string& name)
{
	std::cout << name << std::endl;
}

void PrintName3(std::string&& name)//右值引用
{
	std::cout << name << std::endl;
}
/*一个&符号的是接受左值，即使在前面加上const，意思是这与右值兼容*/

void PrintName4(const std::string& name)
{
	std::cout << "[lvalue]" << name << std::endl;
}

void PrintName4(std::string&& name)
{
	std::cout << "[rvalue]" << name << std::endl;
}


int main()
{
	//简单定义
/*左值绝大多数时候在等号左边，右值在右边
请注意，这并不总是适用的，所以这不是一个完整的事实，不能总是这样认为，因为它不一定是对的*/
	
	int i1 = 10;//可以将10赋值给左值i,但你不能给一个右值赋值
	/*10 = i;这样是不被允许的，因为10没有位置，我们不能在10中存储数据*/
	int a1 = i1;//i是一个左值，显然我们可以用另一个变量a让它等于i。在这个例子中，我们设置一个左值等于一个同样是左值的值（这就是为什么等号右边是右值的说法是不对的）
	
	int i2 = GetValue();//等号的右边也可以等于一个函数。在这个例子中，GetValue返回右值，返回一个临时值；它是临时的，这是因为即使它返回一个int,它也没有位置，没有存储空间，它只返回值10
	int a2 = i2;
	/*GetValue() = 5;这样是不行的，我们的编译器会说，这个表达式必须是可修改的左值*/
	GetValue1() = 5;

	int i3 = 10;//调用SetValue可以使用左值，也可以使用右值
	SetValue(i3);//这里参数是左值
	SetValue(10);//而这种情况下，这里的参数是右值，当函数被调用时，这个右值会被用来创建一个左值
/*注意：你不能将右值赋给左值引用，所以左值引用的只能是左值*/

	//int& a = 10;/*这里的特殊规则是，虽然我不能用左值来引用右值，也就是不能这样*/
	const int& a = 10;//而这样是可以的。这是一种特殊规则，是一种变通手段，实际情况是，编译器可能会用你的存储创建一个临时变量，然后把它赋值给那个引用
	int temp = 10;
	const int& a3 = temp;//所以实际上它不可避免地创建了一个左值，但也同时支持了左值与右值

	int i4 = 10;
	SetValue1(i4);
	//SetValue1(10);这样是不可以的，编译器会说，非常量(const)引用的初始值必须是左值
	
	int i5 = 10;
	SetValue2(i5);
	SetValue2(10);//将其改为const引用后，这样它就同时可接受两种类型数据



	std::string firstName = "Yan";
	std::string lastName = "Chernikov";

	std::string fullName = firstName + lastName;//这时等号右边是右值，左边是左值，firstName和lastName组成一个临时字符串，然后它赋值给了一个左值
	
	PrintName1(fullName);//这样是可以
	//PrintName1(firstName + lastName);如果用表达式调用它是行不通的，因为这是右值

	PrintName2(firstName + lastName);//这样是被允许的，这就是为什么你会看到很多用C++写的常量引用，因为它们兼容临时的右值和实际存在的左值变量
/*因此有一个检测某个值是否为左值的方法，我们可以写一个非常量的左值引用，因为左值引用只能接受左值，就像PrintName1(firstName + lastName)不会被编译，因为这当然是一个右值*/

/*我们也有办法写一个函数只接受临时对象，这需要我们使用一个叫做右值引用的东西*/
	//PrintName3(fullName);右值引用这样是不被允许的。这里编译器会说右值引用不能绑定到左值，这意味着我们可以写这个函数的重载，它只接受临时对象
	PrintName3(firstName + lastName);//这里是被允许的，我们不能传递左值，但可以传递右值


	PrintName4(fullName);
	PrintName4(firstName + lastName);
//这里可以看到左值选择的是第一个重载，右值选择的是第二个重载
//有了右值引用，我们现在有了一种特殊的方法来检测临时值并对它们做一些特殊的事情

//这些非常有用，尤其是在移动语义方面，这里的这样优势在于优化，如果我们知道传入的是一个临时对象的话，那我们就不需要担心它们是否活着、是否完整、是否拷贝，我们可以简单地偷它的资源，给到特定对象，或者其他地方使用它们，因为我们知道它是暂时的，它不会存在很长时间
//而如果使用常量的左值引用(const + &)，除了它是const之外，你不能从这个name字符串中窃取任何东西，因为它可能会在很多函数中使用，而PrintName(firstName + lastName)中可以，因为它显然是暂时的,只会在这个特定的printName调用中使用
/*因此，记住，左值是有某种存储支持的变量，右值是临时值，左值引用仅仅接受左值，除非使用const，而右值引用仅仅接受右值*/

	std::cin.get();
}

//很多人称左值为有地址的值(located value)

