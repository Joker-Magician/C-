#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>  
#include <unordered_map>  
using namespace std;  

int n, id;  
unordered_map<int, int> mp;  

int main() {  
   cin >> n;  
   for (int i = 1; i <= n; ++i) {  
       cin >> id;  
       mp[id]++;  
   }  
   int cnt1 = 0, cnt2 = 0;  
   for (auto& pair : mp) {  
       if (pair.second == 1) cnt1++; // ֻ����1�ε�Ԫ������  
       else cnt2 += pair.second - 2; // ���ֶ�ε�Ԫ�������Ķ�������(-2����Ϊ������ԣ�ÿ��Ԫ��-2ʣ�µľ��Ƕ����)  
   }  
   if (cnt1 > cnt2) cout << (cnt1 + cnt2) / 2 << '\n';  
   //���׵������cnt2+(cnt1-cnt2)/2 Ҳ����(cnt1 + cnt2) / 2  
   //�Ȱ����õ�cnt2ȫ���� ʣ���(cnt1-cnt2)���Լ��������  
   else cout << cnt2 << '\n';  
   //cnt2�������� ��������� �������cnt2Ҳ�ô��� ÿ�����ֶ��øĳ��µģ���Ϊ�Ѿ�������ˣ� �����ܹ�����cnt2  
   return 0;  
}