#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cstdio>
//��������:
//�� 1~n �� n �����������ѡȡ��������������п��ܵ�ѡ�񷽰���
//����һ������ n��n С�ڵ��� 15����
//ÿ�����һ�ַ�����ͬһ���ڵ��������������У�������������ǡ�� 1 ���ո����������û��ѡ�κ����ķ�����������С�

using namespace std;

const int N = 15;
int n;
int s[N];//������¼ÿ�����״̬��0��ʾ�����ǣ�1��ʾѡ�������2��ʾ��ѡ

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
	dfs(x + 1);//��һ����֧����ѡ
	s[x] = 0;

	s[x] = 1;
	dfs(x + 1);//�ڶ�����֧��ѡ
	s[x] = 0;
}

int main()
{
	cin >> n;
	dfs(n);
	return 0;
}