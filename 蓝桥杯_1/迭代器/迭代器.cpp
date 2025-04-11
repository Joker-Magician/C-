#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> a;
	for (int i = 0; i < a.size(); i++) {//对于vector可以用下标遍历
		cout << a[i] << endl;
	}
	for (vector<int>::iterator it = a.begin(); it!=a.end(); ++it)//也可以使用迭代器遍历
		cout << *it << endl;//迭代器与指针相似，如果对它使用解引用运算符，即“*it",就可以取到对应值了
	a.begin();//头迭代器
	a.end();//尾迭代器，是最后一个元素的再往后一个位置
	a.rbegin();//反向头迭代器
	a.rend();//反向尾迭代器
	//迭代器-迭代器可以得到两个迭代器的距离
	return 0;
}

//很多数据结构并不是线性的，对于非线性数据结构，下表是无意义的。无法使用下标来遍历整个班数据结构
//迭代器的作用就是定义某个数据结构的遍历方式，通过迭代器的增减，代表遍历到的位置，通过迭代器便能成功遍历非线性结构了
//注意：尽量不要使用迭代器操作容器，，容易出错