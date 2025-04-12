#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

#include<stdlib.h>

int main()
{
	using namespace std::string_literals;

	std::u32string name0 = U"Chaeno"s + U"hello";//直接将两个字符串相接是不被允许的，但加上s后实际上就成了一个函数，当然也可以在两个字符串上加上L或u等使其变为宽字符

	const char* example=R"(Line1
Line2
Line3
Line4)";//另一种接上字符串的方法是在前面加上R,这意味着它会忽略转义符。在实际应用中，要打印很多行的字符串是很有用的

	const char* ex = "Line1\n"
		"Line2\n"
		"Line3\n";//第二种写法

	//const char name[8] = "Che\0rno";这个现在是不被允许的，一遇到\0就会认为是字符串的结尾
	const char name[8] = "Cherno";
	const char* name1 = u8"Cherno";//两种写法是一样的
	const wchar_t* name2 = L"Cherno";//用wchar_t并前面加上L表示接下来字符串字面量是由宽字符组成的

	const char16_t* name3 = u"Cherno";//本质上说char就是一个1字节的字符,char16是2字节每个字符占16bit
	const char32_t* name3 = U"Cherno";

	std::cout << strlen(name) << std::endl;
	std::cin.get();
}

//本质:字符串字面量总是存储在只读内存中，意味着不可对他进行修改