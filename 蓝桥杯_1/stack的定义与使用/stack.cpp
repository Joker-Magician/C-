#define _CRT_SECURE_NO_WARNINGS
//#include<bits\stdc++.h>
#include<stack>
#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	stack<double> stk;
	stk.push(1.0);
	stk.push(1.4);
	cout << stk.size() << endl;
	cout << stk.empty() << endl;
	cout << stk.top() << endl;
	stk.pop();
	if (!stk.empty()) {
		cout << stk.top() << endl; // Correctly access the top element after pop
	} else {
		cout << "Stack is empty" << endl; // Handle empty stack case
	}

	//使用vector来制造栈
	vector<double> vec;
	vec.push_back(1.0);
	vec.push_back(1.4);
	vec.pop_back();
	cout << vec.back() << endl;

	return 0;
}