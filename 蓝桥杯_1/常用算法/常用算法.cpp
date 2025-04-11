#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<cmath>

using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b)
{
	//第二位从小到大
	if (a.second != b.second)
		return a.second < b.second;
	//第一位从大到小
	return a.first > b.first;
}//对于相同函数一定要返回false，否则可以发生错误，

int gcd(int a, int b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b)*b;
}

int main()
{
	int a = 1, b = 2;
	cout << a << ' ' << b << endl;
	swap(a, b);//数字和字符均可以交换
	cout << a << ' ' << b << endl;

	//快速排序函数sort
	vector<int>arr{ 1,9,1,9,8,1,0 };
	sort(arr.begin(), arr.end());//从小到大排列
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
	sort(arr.begin(), arr.end(),greater<int>());//从大到小排
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
	vector<pair<int, int>>arr1{ {1,9},{2,9},{8,1},{0,0} };
	sort(arr1.begin(), arr1.end(), cmp);
	for (auto ele : arr1)
		cout << ele.first << ' ' << ele.second << endl;

	//二分查找
	vector<int>arr2{ 0,1,1,1,8,9,9 };//注意使用前要有序
	int pos1 = lower_bound(arr.begin()+2, arr.end(), 8) - arr.begin();//从第二个开始找找到≥8的第一个元素
	cout << pos1 << endl;
	int pos2 = upper_bound(arr.begin(), arr.end(), 8) - arr.begin();//找到>8的第一个元素
	cout << pos2 << endl;

	//reverse反转一个序列的顺序
	vector<int>arr3{ 0,1,1,1,8,9,9 };
	reverse(arr3.begin(), arr3.end());
	for (auto ele : arr3)
		cout << ele << endl;

	//max与min
	cout << max(1, 2) << endl;
	cout << min(1, 2) << endl;

	//去重unique--去除相邻重复元素
	vector<int>arr4{ 1,2,1,4,5,4,4 };
	sort(arr4.begin(), arr4.end());
	arr.erase(unique(arr4.begin(), arr.end()), arr.end());//erase为了删掉去重后的无效数据

	//数学函数
	cout << abs(-1) << endl;
	cout << exp(2) << endl;
	cout << log(3) << endl;
	cout << pow(2, 3) << endl;
	cout << sqrt(2) << endl;
	cout << ceil(2.1) << endl;
	cout << floor(2.1) << endl;
	cout << round(2) << endl;//四舍五入取整

	//C++17以上有gcd和lcm
	int x = gcd(8, 12);//4
	int y = lcm(8, 12);//24

	return 0;
}