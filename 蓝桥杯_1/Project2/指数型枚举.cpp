#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cstdio>
//问题描述:
//从 1~n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案。
//输入一个整数 n（n 小于等于 15）。
//每行输出一种方案，同一行内的数必须升序排列，相邻两个数用恰好 1 个空格隔开。对于没有选任何数的方案，输出空行。

using namespace std;

const int N = 15;
int n;
int s[N];//用来记录每个点的状态：0表示待考虑，1表示选择该数，2表示不选

void dfs(int x) {
	if (x == n) {
		for (int i = 0; i < n; i++) {
			if (s[i] == 1) {
				printf("%d", i + 1);
			}
		}
		printf("\n");
		return;
	}
	s[x] = 2;
	dfs(x + 1);//第一个分支，不选
	s[x] = 0;

	s[x] = 1;
	dfs(x + 1);//第二个分支，选
	s[x] = 0;
}

int main()
{
	cin >> n;
	dfs(n);
	return 0;
}