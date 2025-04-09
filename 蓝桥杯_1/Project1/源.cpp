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
       if (pair.second == 1) cnt1++; // 只出现1次的元素数量  
       else cnt2 += pair.second - 2; // 出现多次的元素数量的多余总数(-2是因为俩俩配对，每个元素-2剩下的就是多余的)  
   }  
   if (cnt1 > cnt2) cout << (cnt1 + cnt2) / 2 << '\n';  
   //容易的理解是cnt2+(cnt1-cnt2)/2 也就是(cnt1 + cnt2) / 2  
   //先把能用的cnt2全用上 剩余的(cnt1-cnt2)再自己俩俩配对  
   else cout << cnt2 << '\n';  
   //cnt2不仅够用 还多出来了 多出来的cnt2也得处理 每个数字都得改成新的（因为已经多出来了） 所以总共就是cnt2  
   return 0;  
}