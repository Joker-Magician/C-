#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>

//计算两个整数的最大公约数
long long gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

//计算两个整数的最小公倍数
long long lcm(int a, int b) {
	return a * b / gcd(a, b);
}