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
	//�ڶ�λ��С����
	if (a.second != b.second)
		return a.second < b.second;
	//��һλ�Ӵ�С
	return a.first > b.first;
}//������ͬ����һ��Ҫ����false��������Է�������

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
	swap(a, b);//���ֺ��ַ������Խ���
	cout << a << ' ' << b << endl;

	//����������sort
	vector<int>arr{ 1,9,1,9,8,1,0 };
	sort(arr.begin(), arr.end());//��С��������
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
	sort(arr.begin(), arr.end(),greater<int>());//�Ӵ�С��
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
	vector<pair<int, int>>arr1{ {1,9},{2,9},{8,1},{0,0} };
	sort(arr1.begin(), arr1.end(), cmp);
	for (auto ele : arr1)
		cout << ele.first << ' ' << ele.second << endl;

	//���ֲ���
	vector<int>arr2{ 0,1,1,1,8,9,9 };//ע��ʹ��ǰҪ����
	int pos1 = lower_bound(arr.begin()+2, arr.end(), 8) - arr.begin();//�ӵڶ�����ʼ���ҵ���8�ĵ�һ��Ԫ��
	cout << pos1 << endl;
	int pos2 = upper_bound(arr.begin(), arr.end(), 8) - arr.begin();//�ҵ�>8�ĵ�һ��Ԫ��
	cout << pos2 << endl;

	//reverse��תһ�����е�˳��
	vector<int>arr3{ 0,1,1,1,8,9,9 };
	reverse(arr3.begin(), arr3.end());
	for (auto ele : arr3)
		cout << ele << endl;

	//max��min
	cout << max(1, 2) << endl;
	cout << min(1, 2) << endl;

	//ȥ��unique--ȥ�������ظ�Ԫ��
	vector<int>arr4{ 1,2,1,4,5,4,4 };
	sort(arr4.begin(), arr4.end());
	arr.erase(unique(arr4.begin(), arr.end()), arr.end());//eraseΪ��ɾ��ȥ�غ����Ч����

	//��ѧ����
	cout << abs(-1) << endl;
	cout << exp(2) << endl;
	cout << log(3) << endl;
	cout << pow(2, 3) << endl;
	cout << sqrt(2) << endl;
	cout << ceil(2.1) << endl;
	cout << floor(2.1) << endl;
	cout << round(2) << endl;//��������ȡ��

	//C++17������gcd��lcm
	int x = gcd(8, 12);//4
	int y = lcm(8, 12);//24

	return 0;
}