#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

/*这里还有一个要注意的概念是函数重载：
	函数重载是 C++ 的一项重要特性，它允许在同一个作用域内定义多个名称相同但参数列表不同的函数。
	在调用这些同名函数时，编译器会依据传入的实参类型和数量来决定调用哪个具体的函数。
重载规则:
1.参数数量不同：函数名相同，但参数的数量不一样。
2.参数类型不同：函数名相同，参数数量相同，但参数的类型存在差异。
3.参数顺序不同：函数名相同，参数数量相同，参数类型也相同，但参数的顺序不一样。
*/
// 计算两个整数的和
int add(int a, int b) {
    return a + b;
}

// 计算两个浮点数的和
double add(double a, double b) {
    return a + b;
}

// 计算三个整数的和
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