//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
bool st[N];
int n;
bool flag = false;
int t[N], d[N], l[N];
void dfs(int u, int last) {
	if (flag) return;
	if (u == n) {
		flag = true;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!st[i]) {
			if (t[i] + d[i] >= last) {
				st[i] = true;
				if (t[i] > last)
					dfs(u + 1, t[i] + l[i]);
				else
					dfs(u + 1, last + l[i]);
				st[i] = false;
			}
			else return;
		}
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> t[i] >> d[i] >> l[i];
		for (int i = 0; i < N; i++) st[i] = false;
		flag = false;
		dfs(0, 0);
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
