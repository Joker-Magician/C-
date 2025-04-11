#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	string _s1;
	cin >> _s1;//读入
	cout << _s1;//输出

	string s(100, '0');
	s = "awa";
	cout << s << endl;
	s[0] = 'b';
	cout << s << endl;

	string s1 = "123", s2 = "123";
	s1 += 'a';//尾接字符串一定用+=，用s=s+'a'耗费时间更多
	cout << s1 + s2 << endl;

	string s3 = "123123123";
	cout << s3.substr(3) << endl;//subster取子串，substr(3)取从第三个往后的所有
	cout << s3.substr(3, 4) << endl;
	cout << s3.find("312") << endl;//find()会返回子串起始点的下表
	if (s3.find("313") != string::npos) {//如果找不到会返回一个定义的数字npos
		cout << "yes" << endl;
	}

	//可以转换类型
	int x = stoi(s3);//整形
	long long x = stoll(s3);
	//等等许多类型

	int x1 = 6662;
	string s3 = to_string(x);
	cout << s << endl;

	return 0;
}