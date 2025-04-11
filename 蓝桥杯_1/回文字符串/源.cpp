#include <iostream>
//#include<bits/stdc++.h>
#include<string>
#include<vector>
/*问题描述:小蓝迷上回文字符串，有只含小写字母的字符串 S，可在 S 开头加指定字符 l、q、b ，想知道能否将其转化为回文字符串。
  输入格式:第一行整数 T 表示 T 组数据，之后每组数据一行是字符串 S 。
  输出格式:输出 T 行，能转化为回文输出 Yes，否则输出 No 。*/

using namespace std;

string s;
bool solve() {
    vector<int> vec;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] != 'l' && s[i] != 'q' && s[i] != 'b') vec.push_back(i);
    }

    if (vec.size() == 0) return true;
    int left = vec[0], l = vec[0], right = vec[vec.size() - 1], r = vec[vec.size() - 1];
    while (left <= right && s[left] == s[right]) {
        left++;
        right--;
    }
    while (l >= 0 && r < len && s[l] == s[r]) {
        r++;
        l--;
    }
    return left > right && l < 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (solve()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}