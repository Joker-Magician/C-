#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	string str = "Hello.C++";
	//使用push_back()在字符串末尾添加字符
	str.push_back('I');
	cout << "After push_back:" << str << endl;
	//使用pop_back()移除字符串末尾的字符
	str.pop_back();
	cout << "After pop_back:" << str << endl;
	//使用insert()在指定位置插入字符串
	str.insert(7, "World, ");
	cout << "After insert:" << str << endl;
	//使用+号拼接字符串
	str = str + "Welcome to programming.";
	cout << "After + operator:" << str << endl;
	//获取并打印字符串的大小
	cout << "Size: " << str.size() << endl;
	cout << "Size: " << str.length() << endl;
	return 0;
}