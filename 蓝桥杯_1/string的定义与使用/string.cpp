#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	string str = "Hello.C++";
	//ʹ��push_back()���ַ���ĩβ����ַ�
	str.push_back('I');
	cout << "After push_back:" << str << endl;
	//ʹ��pop_back()�Ƴ��ַ���ĩβ���ַ�
	str.pop_back();
	cout << "After pop_back:" << str << endl;
	//ʹ��insert()��ָ��λ�ò����ַ���
	str.insert(7, "World, ");
	cout << "After insert:" << str << endl;
	//ʹ��+��ƴ���ַ���
	str = str + "Welcome to programming.";
	cout << "After + operator:" << str << endl;
	//��ȡ����ӡ�ַ����Ĵ�С
	cout << "Size: " << str.size() << endl;
	cout << "Size: " << str.length() << endl;
	return 0;
}