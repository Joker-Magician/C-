#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	//cout << que.front() << endl;//�鿴����Ԫ��
	//cout << que.back() << endl;//�鿴��βԪ��
	que.pop();//��������Ԫ��
	//cout << que.front() << endl;
	//cout << que.back() << endl;
	que.pop();
	cout << que.front() << endl;
	cout << que.back() << endl;
	cout << que.size() << endl;
	cout << que.empty() << endl;
	return 0;
}