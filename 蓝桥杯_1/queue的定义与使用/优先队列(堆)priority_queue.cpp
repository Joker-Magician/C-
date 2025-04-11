#define _CRT_SECURE_NO_WARNINGS
//#include<bits\stdc++.h>
#include<queue>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	priority_queue<int> pque_max;//在<>实际可以传三个值，此时默认为大顶堆;
	pque_max.push(1);
	cout << pque_max.top() << endl;
	pque_max.push(3);
	cout << pque_max.top() << endl;
	pque_max.push(2);
	cout << pque_max.top() << endl;//此时堆顶为最大值
	pque_max.push(4);
	cout << pque_max.top() << endl;
	pque_max.pop();
	cout << pque_max.top() << endl;
	pque_max.pop();
	cout << pque_max.top() << endl;
	pque_max.pop();
	cout << pque_max.top() << endl;
	cout << endl;

	priority_queue<int,vector<int>,greater<int>> pque_min;//此时设置为小顶堆
	pque_min.push(1);
	cout << pque_max.top() << endl;
	pque_min.push(3);
	cout << pque_max.top() << endl;
	pque_min.push(2);
	cout << pque_max.top() << endl;
	pque_min.push(4);
	cout << pque_max.top() << endl;//堆顶为最小值
	pque_min.pop();
	cout << pque_max.top() << endl;
	pque_min.pop();
	cout << pque_max.top() << endl;
	pque_min.pop();
	cout << pque_max.top() << endl;
	cout << endl;

	//无论stack还是queue中都不允许直接访问元素，但若是想要修改priority_queue堆顶可以采用曲线救国的方式
	priority_queue<int, vector<int>, greater<int>> pque;
	pque.push(1);
	pque.push(2);
	pque.push(3);
	pque.push(4);

	int x = pque.top();
	pque.pop();//弹出堆定的元素
	pque.push(x + 1);
	cout << pque.top() << endl;

	return 0;
}