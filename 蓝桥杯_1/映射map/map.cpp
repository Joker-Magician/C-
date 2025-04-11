#define _CRT_SECURE_NO_WARNINGS
//#include<bits\stdc++.h>
#include<iostream>
#include<map>
#include<vector>

//数组本质上可以算作一种映射，map可以提供更加自由的映射
//特性：互异性：一个键只能在映射中出现一次，
//有序性：按从小到大排序

using namespace std;

int main()
{
	map<int, int>mp;

	mp[2] = 1;
	mp[1] = 3;
	mp[0] = 4;
	mp[99999] = 99999;

	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		cout << it->first << ' ' << it->second << endl;
	for (auto& pr : mp) {
		cout << pr.first << ' ' << pr.second << endl;
	}

	mp.erase(2);//删除
	cout << mp.count(2) << endl;
	cout << mp.size() << endl;
	mp.clear();
	cout << mp.empty() << endl;

	cout << mp[2] << endl;//不存在会直接赋一个初值0
	if (mp.find(2) != mp.end()) {//同样找到后会返回元素所在位置的迭代器
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	//用处：可用来统计出现次数
	map<string, int>mp1;//字符串和整形映射
	vector<string> word;
	word.push_back("awa");
	word.push_back("awa");
	word.push_back("awa");
	word.push_back("awa");
	word.push_back("bwb");
	word.push_back("bwb");
	for (int i = 0; i < word.size(); i++) {
		mp1[word[i]]++;
	}
	for (auto& pr : mp1) {
		cout << pr.first << ' ' << pr.second << endl;
	}
	return 0;
}

//注意：不可用迭代器计算下标