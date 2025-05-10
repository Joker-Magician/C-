#include <iostream>
#include <variant>
#include <optional>

/*std::optional<std::string> ReadFileAsString()
{
	return {};
}*///我们之前做的是如果文本存在，它会返回所有文本字符，如果不存在，或者不能读取，则会返回optional{}。这就是我们之前做的
//这虽然很好，让我们很容易看到读取是否成功，std::optional能在任何情况下允许我们有一些不存在的可选数据

enum class ErrorCode
{
	None = 0, NotFount = 1, NoAccess = 2//受保护的不能被读取
};

std::variant<std::string,ErrorCode> ReadFileAsString()//我们不仅仅要知道是否读取成功的话可以使用std::variant,如果成功获取了数据，我们可以使用字符串作为值，如果不成功可以设置一些错误代码，我们可以把它编码成一个整数或使用枚举
{
	return {};
}//这笔返回一个布尔值更加详细一些

int main()
{
	std::variant<std::string, int> data;
//与union的区分是union是取所有成员变量内存最大值作为内存
//variants不是这样的，variant只是将所有可能的数据类型存储为单独的变量作为单独的成员
	std::cout << sizeof(int) << "\n";//4
	std::cout << sizeof(std::string) << "\n";//40
	std::cout << sizeof(data) << "\n";//48
//从这可以看出，它是为你创建了一个结构体或类，它只是将这两种数据类型存储为那个类或结构体中的成员

	data = "Cherno";//我们列出它是一个字符串或整数满五年也可以把它重新赋值给一个字符串或整数
	//data = 2;
	//data = false;//它虽然允许我们赋值给其他类型，但如果我们这样做了，我们实际上以后就不能访问它了
	std::cout << std::get<std::string>(data) << "\n";//访问变量使用std::get<>后面跟这一个放你想要的类型的模板参数
	//data.index();//这个函数会告诉你类型索引，它将所有类型映射到索引上，std::string是0，int是1，通过检查索引来检查类型是否正确
	//auto* value = std::get_if<std::string>(&data);//作用是获取这个数据作为一个字符串(使用<std::string>)，传递std::variant值的内存地址或指针，然后这将为我们返回一个指针，我们可以检查这个指针是否为空，如果它不是那个类型的话，它会给我们一个空指针，反之则给我们一个指向那个字符串的指针
	if (auto value = std::get_if<std::string>(&data))//我们将其封装到if中，为你根本不需要在前面加星号
	{	//如果它是字符串就将它当作字符串来处理
		std::string& v = *value;//这就是我们的字符串，我们可以像往常一样访问它
	}
	else//用else来处理另一种类型
	{

	}
	
	data = 2;

	//std::cout << std::get<std::string>(data) << "\n";//如果错误访问，它会跑给我们一个异常，我们可以利用异常来修改，也可以使用index函数，而更好的是使用get_if函数
	std::cout << std::get<int>(data) << "\n";


	std::cin.get();
}

//在单一变量存放多种类型的数据主要用到了std::variant，这也是C++17中的一种新的特性
//用来处理可能存在也可能不存在的数据，也可能是与我们预期不同的类型。当然也不一定是与我们预期不同的类型，而是让我们能够存储不同类型的数据

//std::optional是关于我们如何存储可能存在也可能不存在的数据，而std::variant和std::option很像，它的作用是让我们不用担心处理的确切数据类型，只有一个变量，之后我们再考虑它的具体类型，我们所做的就是一个叫做std::variant的东西，然后列出它可能的数据类型
//例如，你可能在解析一个文件，你可能不确定这是一个字符串还是一个整数，也许你在程序运行时接受一个命令行，你不确定那个参数是整数还是字符串还是浮点数或者布尔数等
//std::variant允许你列出所有可能的类型，然后你可以决定它将是什么，如果你想，你可以把它重新赋值给任何类型，这也是你创建可能有多个类型的变量的一种方式

//从技术上讲，union仍然是更有效率和更好的，然而variant更见类型安全，不会造成未定义行为，你应该使用它，除非你做的是底层优化，把内存大小保持在一个较低的位置，不管是什么原因，比如CPU处理