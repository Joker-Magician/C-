#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
#include<iostream>
#include<utility>

//二元组，即两个元素构成的组合

using namespace std;

int main()
{
	pair<int, int>_p1 = { 1,2 };//如果编译器较老使用老式定义方式p=make_pair(1,2)
	pair<int, int>_p2 = make_pair(1, 2);
	if (_p1 == _p2) {
		cout << "yes" << endl;
	}

	pair<char, int>p2 = {'a', 2};//相当于使用结构体定义了char和int
	pair<pair<int, char>, char>p3;//这样相当于定义了三元组

	return 0;
}