#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
/*���⣺������̨��
��Ŀ������һֻ����һ�ο������� 1 ��̨�ף�Ҳ�������� 2 ��̨�ס�����������һ�� n ����̨�׹��ж��������� (�Ⱥ����ͬ�㲻ͬ�Ľ��)��
����˼·������˼ά����
�������һ�����������һ�������� 1 ������ 2 ��̨�ס�
���� f (n) Ϊ������ n ��̨�׵���������
f (n) = f (n - 1) + f (n - 2)���������� n ��̨�׵����������������� n - 1 ��̨�׵����������������� n - 2 ��̨�׵���������
�߽�������f (0) = 1��f (1) = 1*/
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