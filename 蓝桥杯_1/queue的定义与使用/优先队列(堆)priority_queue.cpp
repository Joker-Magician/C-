#define _CRT_SECURE_NO_WARNINGS
//#include<bits\stdc++.h>
#include<queue>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	priority_queue<int> pque_max;//��<>ʵ�ʿ��Դ�����ֵ����ʱĬ��Ϊ�󶥶�;
	pque_max.push(1);
	cout << pque_max.top() << endl;
	pque_max.push(3);
	cout << pque_max.top() << endl;
	pque_max.push(2);
	cout << pque_max.top() << endl;//��ʱ�Ѷ�Ϊ���ֵ
	pque_max.push(4);
	cout << pque_max.top() << endl;
	pque_max.pop();
	cout << pque_max.top() << endl;
	pque_max.pop();
	cout << pque_max.top() << endl;
	pque_max.pop();
	cout << pque_max.top() << endl;
	cout << endl;

	priority_queue<int,vector<int>,greater<int>> pque_min;//��ʱ����ΪС����
	pque_min.push(1);
	cout << pque_max.top() << endl;
	pque_min.push(3);
	cout << pque_max.top() << endl;
	pque_min.push(2);
	cout << pque_max.top() << endl;
	pque_min.push(4);
	cout << pque_max.top() << endl;//�Ѷ�Ϊ��Сֵ
	pque_min.pop();
	cout << pque_max.top() << endl;
	pque_min.pop();
	cout << pque_max.top() << endl;
	pque_min.pop();
	cout << pque_max.top() << endl;
	cout << endl;

	//����stack����queue�ж�������ֱ�ӷ���Ԫ�أ���������Ҫ�޸�priority_queue�Ѷ����Բ������߾ȹ��ķ�ʽ
	priority_queue<int, vector<int>, greater<int>> pque;
	pque.push(1);
	pque.push(2);
	pque.push(3);
	pque.push(4);

	int x = pque.top();
	pque.pop();//�����Ѷ���Ԫ��
	pque.push(x + 1);
	cout << pque.top() << endl;

	return 0;
}