#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

static int n = 10;
//int n = 10;
//LINK : 没有找到 E:\github本地仓库\C-\C++学习\x64\Debug\Static的使用.exe 或上一个增量链接没有生成它；正在执行完全链接
//会显示一个链接错误
//一般如果要使用全局变量尽量用static将变量局限于这个.cpp文件中.obj中，不然就会与其他文件乱链接(LINK)，发生错误。
/*注意：一般不建议使用全局变量，它是有害的*/

int main()
{
	std::cout << n << std::endl;
}
