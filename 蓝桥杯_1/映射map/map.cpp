#define _CRT_SECURE_NO_WARNINGS
//#include<bits\stdc++.h>
#include<iostream>
#include<map>
#include<vector>

//���鱾���Ͽ�������һ��ӳ�䣬map�����ṩ�������ɵ�ӳ��
//���ԣ������ԣ�һ����ֻ����ӳ���г���һ�Σ�
//�����ԣ�����С��������

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

	mp.erase(2);//ɾ��
	cout << mp.count(2) << endl;
	cout << mp.size() << endl;
	mp.clear();
	cout << mp.empty() << endl;

	cout << mp[2] << endl;//�����ڻ�ֱ�Ӹ�һ����ֵ0
	if (mp.find(2) != mp.end()) {//ͬ���ҵ���᷵��Ԫ������λ�õĵ�����
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	//�ô���������ͳ�Ƴ��ִ���
	map<string, int>mp1;//�ַ���������ӳ��
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

//ע�⣺�����õ����������±�