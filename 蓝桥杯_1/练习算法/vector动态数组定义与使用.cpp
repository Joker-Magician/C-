#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;


int main() {
	//动态数组的定义与基本操作
	vector<int> a;
	a.push_back(10);//添加元素10
	a.push_back(20);
	a.push_back(30);

	//定义二维数组
	vector<vector<int>> mat(100, vector<int>(666, -1));//构造初始100行，初始666列的二维数组，初值为-1

	//输出vector中的所有元素
	cout << "Initial vector:";
	for (int num : a) {
		cout << num << " ";
	}
	cout << endl;


	//访问vector中的元素
	cout << "Vector element ay index 2;" << a[2] << endl;
	
	
	//修改vector中的一个元素
	a[2] = 35;
	
	
	//删除vector中的一个元素（使用迭代器）
	vector<int>::iterator it = a.begin();/* iterator就是迭代器的英文，相当于一个指针指向it,用于遍历 std::vector 容器。•	a.begin() 返回一个指向 vector 起始位置的迭代器。•	这里 it 被初始化为指向 a 的第一个元素。*/
	it += 2;	/*•	迭代器支持类似指针的算术操作,it += 2 将迭代器向前移动两个位置，使其指向 vector 中的第三个元素（索引为 2 的元素）*/
	a.erase(it);	
/*erase 是 std::vector 的成员函数，用于删除指定位置的元素。
参数：这里传入的是迭代器 it，表示删除 it 当前指向的元素。
效果：删除元素后，vector 中的所有后续元素会向前移动以填补空缺。
迭代器 it 在调用 erase 后会失效（需要小心使用）。*/

	cout << "Vector after adding an element:";
	for (int num : a) {
		cout << num << " ";
	}

	a.empty();//判定是否是空的，返回bool类型的变量，1为true，0为false

	a.clear();//快速清空一个数组

	a.resize(100);//可以改变长度，多余的位置默认为0（可以在长度后面自己设置初值），少的位置直接被删掉

	cout << endl;
	return 0;
}