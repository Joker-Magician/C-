#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
#include<iostream>
#include<utility>

//��Ԫ�飬������Ԫ�ع��ɵ����

using namespace std;

int main()
{
	pair<int, int>_p1 = { 1,2 };//�������������ʹ����ʽ���巽ʽp=make_pair(1,2)
	pair<int, int>_p2 = make_pair(1, 2);
	if (_p1 == _p2) {
		cout << "yes" << endl;
	}

	pair<char, int>p2 = {'a', 2};//�൱��ʹ�ýṹ�嶨����char��int
	pair<pair<int, char>, char>p3;//�����൱�ڶ�������Ԫ��

	return 0;
}