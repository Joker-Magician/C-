#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
/*问题描述:
把 1~n 这 n 个整数排成一行后随机打乱顺序，输出所有可能的次序。输入为一个整数 n 。
要求按照从小到大的顺序输出所有方案，每行 1 个。首先，同一行相邻两个数用一个空格隔开。
其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面。*/
using namespace std;
const int N = 10;
int n;
bool used[N];//记录数据是否被使用
int s[N];//记录方案
void dfs(int u) {
	if (u > n) {//出口，直接将方案输出
		for (int i = 0; i < n; i++) {
			cout << s[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) { //这个数没有被选的话
			s[u] = i;	//将这个数记录在方案中
			used[i] = true;	//标记1这个数被选了
			dfs(u + 1);		//进行下一位数的选择
			used[i] = false;//恢复！！！
			s[u] = 0;		//恢复
		}
	}
}
int main() {
	cin >> n;
	dfs(n);
	return 0;
}