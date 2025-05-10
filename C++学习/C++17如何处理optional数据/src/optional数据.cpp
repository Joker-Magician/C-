#include<iostream>
#include<optional>
#include<fstream>
//方法一使用bool判断数据是否有效
//std::string ReadFileAsString(const std::string& filepath,bool& outSuccess)//用一个函数来读取文件
//{
//	std::ifstream stream(filepath);//这里是一个文佳输入流，会读取我们真正想要读取的文件路径
//	//现在有了输入文件流，我们要做的是读取它，如果它是有效的或者文件打开是成功的，又或者是无效或者无法打开，那我们也要处理它
//	if (stream)
//	{
//		std::string result;
//		//read file
//		stream.close();
//		outSuccess = true;
//		return result;//返回我们读到的字符串
//	}
//
//	outSuccess = false;
//
//	return std::string();//不成功可以返回一个空字符串return ""，也可以返回一个这样构造的字符串
//}

//方法二使用std::optional判断数据是否有效
std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		//read file
		stream.close();
		return result;
	}

	return {};//这里是返回一个std::opional，比如用{}
}

int main()
{

//	bool fileOpenedSuccessfully;
//	//但重点是我们很难知道文件是否被成功打开
//	std::string data = ReadFileAsString("data.txt",fileOpenedSuccessfully);
//	//if (data != "")//一般我们判断data是否为空，但这样不是很好。我们更想知道数据能否被成功读取的方法
//	//{}				//因为也许那个文件在那里，它是空的，但它可能是有效的，我们需要一种方法来确定它是否有效
////第一种方法是输出一个布尔值, 可以取名为success
//	if(fileOpenedSuccessfully)//这比空字符串要好
//	{ }
 
//第二种方法就是使用std::optional
	std::optional<std::string> data = ReadFileAsString("data.txt");
	
	std::string value = data.value_or("Not present"); //data.value_or作用是，如果数据确实存在与std::optional中，它将返回给我们那个字符串。如果不存在，它会返回我们传入的任何值
//这在解析文件时非常有用，比如提取变量或任何已经设置的元素，因为通常你可能会在文件中一些东西是可选的，如果某个参数没有在文件中设置，你可以使用你指定的默认值
	std::cout << value << std::endl;

	//std::optional<int> count;//如果我们可能运行一个基准测试，在文件中有我们在基准测试中的次数
	//int c = count.value_or(100);//如果文佳存在，我们可以提取这个计数,如果不存在，可以使用默认值100

	if (data.has_value())//如果data.has_value是true，这意味着可选的已经被设置;这里也可以写成if(data),因为data对象有一个bool运算符
	{
		std::cout << "File read successfully!\n";
	}
	else
	{
		//std::string& string = *data;//可以以普通字符串的形式访问它
		//data.value();这样也可以
		std::cout << "File could not be opened!\n";
	}
//测试前请在该项目下提前创建一个data.txt文件.r如果手动在该项目中删除该文件，它会说文件不能打开
	std::cin.get();
}

/*很多时候，我们有一个返回数据的函数，比如我们正在读取一个文件，但是如果这个文件不能被读取，会发生什么？它是否不存在，抑或是数据不是我们所期望的格式
很多时候，我们仍然需要从函数中返回一些东西，在这个特定的情况下，你可能只返回一个空字符串，但这并不是很好，因为没有多大意义。
如果文件是空的，我们应该有办法看到数据是存在还是不存在，这就是要用到std::optional的地方，这是一个C++17的新特性*/