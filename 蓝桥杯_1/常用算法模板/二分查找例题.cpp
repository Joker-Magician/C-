//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long LL;
using namespace std;

const int MAXN = 1e5 + 10;
int n, k, MaxH, MaxW, MaxA;
int h[MAXN], w[MAXN];

int check(int m) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (h[i] / m) * (w[i] / m);//长和宽能放下的最大长度的乘积
	}
	return ans;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &h[i], &w[i]);
	}
	int l = 1, r = 1e5, mid;
	while (l < r) {
		mid = l + r + 1 >> 1;
		// check条件：注意题目要求答案的最大值
		if (check(mid) >= k)
			l = mid;
		else
			r = mid - 1;
	}
	//输出l或者r，而不是mid
	cout << l << endl;
	return 0;

	return 0;
}