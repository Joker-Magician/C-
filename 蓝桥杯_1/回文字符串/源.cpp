#include <iostream>
//#include<bits/stdc++.h>
#include<string>
#include<vector>
/*��������:С�����ϻ����ַ�������ֻ��Сд��ĸ���ַ��� S������ S ��ͷ��ָ���ַ� l��q��b ����֪���ܷ���ת��Ϊ�����ַ�����
  �����ʽ:��һ������ T ��ʾ T �����ݣ�֮��ÿ������һ�����ַ��� S ��
  �����ʽ:��� T �У���ת��Ϊ������� Yes��������� No ��*/

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