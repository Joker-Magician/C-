#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
/*例题：青蛙跳台阶
题目描述：一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级台阶。求青蛙跳上一个 n 级的台阶共有多少种跳法 (先后次序不同算不同的结果)。*/

class Solution_2 {
public:
	int jumpFrool(int n) {
		if (n == 1 || n == 0) return 1;

		std::vector<int> f(n + 1, 0);
		f[0] = 1;
		f[1] = 1;

		for (int i = 2; i < n + 1; i++) {
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};

int main()
{
	int n;
	Solution_2 solution;
	std::cin >> n;
	std::cout << solution.jumpFrool(n) << std::endl;
	return 0;
}