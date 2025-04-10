#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
/*例题：青蛙跳台阶
题目描述：一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级台阶。求青蛙跳上一个 n 级的台阶共有多少种跳法 (先后次序不同算不同的结果)。
解题思路（逆向思维）：
考虑最后一步：青蛙最后一步可能跳 1 级或者 2 级台阶。
定义 f (n) 为跳到第 n 级台阶的跳法数。
f (n) = f (n - 1) + f (n - 2)，即跳到第 n 级台阶的跳法数等于跳到第 n - 1 级台阶的跳法数加上跳到第 n - 2 级台阶的跳法数。
边界条件：f (0) = 1，f (1) = 1*/
//class Solution {
//public:
//	int JumpFloor(int n) {
//		if (n == 1 || n == 0)
//			return 1;
//		else
//			return JumpFloor(n - 1) + JumpFloor(n - 2);
//	}
//};
//
//int main()
//{
//	int n;
//	Solution solution;
//	std::cin >> n;
//	std::cout << solution.JumpFloor(n) << std::endl;
//	return 0;
//}