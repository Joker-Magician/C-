#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

/*���ﻹ��һ��Ҫע��ĸ����Ǻ������أ�
	���������� C++ ��һ����Ҫ���ԣ���������ͬһ���������ڶ�����������ͬ�������б�ͬ�ĺ�����
	�ڵ�����Щͬ������ʱ�������������ݴ����ʵ�����ͺ����������������ĸ�����ĺ�����
���ع���:
1.����������ͬ����������ͬ����������������һ����
2.�������Ͳ�ͬ����������ͬ������������ͬ�������������ʹ��ڲ��졣
3.����˳��ͬ����������ͬ������������ͬ����������Ҳ��ͬ����������˳��һ����
*/
// �������������ĺ�
int add(int a, int b) {
    return a + b;
}

// ���������������ĺ�
double add(double a, double b) {
    return a + b;
}

// �������������ĺ�
int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int result1 = add(1, 2);
    double result2 = add(1.5, 2.5);
    int result3 = add(1, 2, 3);

    std::cout << "1 + 2 = " << result1 << std::endl;
    std::cout << "1.5 + 2.5 = " << result2 << std::endl;
    std::cout << "1 + 2 + 3 = " << result3 << std::endl;

    return 0;
}