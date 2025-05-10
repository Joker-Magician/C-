#include<iostream>
#include<string>
#include<tuple>

/*struct Person
{
	std::string Name;
	int Age;
};这只需要Person.Name\Person.Age就可以访问了*/

std::tuple<std::string, int> CreatePerson()//一个人的姓名和年龄，组成一个元组，<只写类型即可>
{
	return { "Cherno",24 };
}//只包含两个可以将tuple改为pair，tuple<>里面可以扩展包含更多参数

int mian()
{
	/*auto person = CreatePerson();//auto类型为std::tuple<std::string, int>，不加是因为看着有些乱
	std::string& name = std::get<0>(person);//通过get<0>获取数据库编号为0的，也就是std::string名字
	int age = std::get<1>(person);*/

	//使用tie
	//std::string name;
	//int age;
	//std::tie(name, age) = CreatePerson();
//这里没有person，不是结构体，本身不是一个类型，它只是一个容器，用来存放我们想要的东西，包含了一个string，一个int.
//使用tie看起来比上面tuple更漂亮一些，不需要获取成员那么麻烦。但它仍然需要三行代码，看起来仍然不太友好，我可能仍然会用结构体
	
	auto[name, age] = CreatePerson();//如果报错右击该项目属性->C/C++->语言->将C++改为C++17(默认可能也不可以)
	std::cout << name;


	std::cin.get();
}


//结构化绑定仅适用于C++17，这是一个新的特性，让我们更好的处理多返回值
//这个是在原来用用结构体处理多返回值的基础上扩展的一种处理这个的新方法，特别是如何处理元组(tuple)和对组(pairs)以及返回诸如此类的东西
//结构化绑定简化了我们的代码，让它比以前的做法更清晰.一旦有多个返回值就把他组成一个元组等等，使我们的代码可管理
