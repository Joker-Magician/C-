#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

#include<stdlib.h>

int main()
{
	using namespace std::string_literals;

	std::u32string name0 = U"Chaeno"s + U"hello";//ֱ�ӽ������ַ�������ǲ�������ģ�������s��ʵ���Ͼͳ���һ����������ȻҲ�����������ַ����ϼ���L��u��ʹ���Ϊ���ַ�

	const char* example=R"(Line1
Line2
Line3
Line4)";//��һ�ֽ����ַ����ķ�������ǰ�����R,����ζ���������ת�������ʵ��Ӧ���У�Ҫ��ӡ�ܶ��е��ַ����Ǻ����õ�

	const char* ex = "Line1\n"
		"Line2\n"
		"Line3\n";//�ڶ���д��

	//const char name[8] = "Che\0rno";��������ǲ�������ģ�һ����\0�ͻ���Ϊ���ַ����Ľ�β
	const char name[8] = "Cherno";
	const char* name1 = u8"Cherno";//����д����һ����
	const wchar_t* name2 = L"Cherno";//��wchar_t��ǰ�����L��ʾ�������ַ������������ɿ��ַ���ɵ�

	const char16_t* name3 = u"Cherno";//������˵char����һ��1�ֽڵ��ַ�,char16��2�ֽ�ÿ���ַ�ռ16bit
	const char32_t* name3 = U"Cherno";

	std::cout << strlen(name) << std::endl;
	std::cin.get();
}

//����:�ַ������������Ǵ洢��ֻ���ڴ��У���ζ�Ų��ɶ��������޸�