#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
/*���⣺������̨��
��Ŀ������һֻ����һ�ο������� 1 ��̨�ף�Ҳ�������� 2 ��̨�ס�����������һ�� n ����̨�׹��ж��������� (�Ⱥ����ͬ�㲻ͬ�Ľ��)��*/

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