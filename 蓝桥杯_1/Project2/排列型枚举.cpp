#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
/*��������:
�� 1~n �� n �������ų�һ�к��������˳��������п��ܵĴ�������Ϊһ������ n ��
Ҫ���մ�С�����˳��������з�����ÿ�� 1 �������ȣ�ͬһ��������������һ���ո������
��Σ�����������ͬ���У���Ӧ�±����һһ�Ƚϣ��ֵ����С������ǰ�档*/
using namespace std;
const int N = 10;
int n;
bool used[N];//��¼�����Ƿ�ʹ��
int s[N];//��¼����
void dfs(int u) {
	if (u > n) {//���ڣ�ֱ�ӽ��������
		for (int i = 0; i < n; i++) {
			cout << s[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) { //�����û�б�ѡ�Ļ�
			s[u] = i;	//���������¼�ڷ�����
			used[i] = true;	//���1�������ѡ��
			dfs(u + 1);		//������һλ����ѡ��
			used[i] = false;//�ָ�������
			s[u] = 0;		//�ָ�
		}
	}
}
int main() {
	cin >> n;
	dfs(n);
	return 0;
}