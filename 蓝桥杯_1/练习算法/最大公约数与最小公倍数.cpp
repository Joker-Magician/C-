#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>

//�����������������Լ��
long long gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

//����������������С������
long long lcm(int a, int b) {
	return a * b / gcd(a, b);
}