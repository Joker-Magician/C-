#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	string _s1;
	cin >> _s1;//����
	cout << _s1;//���

	string s(100, '0');
	s = "awa";
	cout << s << endl;
	s[0] = 'b';
	cout << s << endl;

	string s1 = "123", s2 = "123";
	s1 += 'a';//β���ַ���һ����+=����s=s+'a'�ķ�ʱ�����
	cout << s1 + s2 << endl;

	string s3 = "123123123";
	cout << s3.substr(3) << endl;//substerȡ�Ӵ���substr(3)ȡ�ӵ��������������
	cout << s3.substr(3, 4) << endl;
	cout << s3.find("312") << endl;//find()�᷵���Ӵ���ʼ����±�
	if (s3.find("313") != string::npos) {//����Ҳ����᷵��һ�����������npos
		cout << "yes" << endl;
	}

	//����ת������
	int x = stoi(s3);//����
	long long x = stoll(s3);
	//�ȵ��������

	int x1 = 6662;
	string s3 = to_string(x);
	cout << s << endl;

	return 0;
}