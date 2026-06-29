//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;
int n;
int q[N], tmp[N];

/* 归并排序 */
void merge_sort(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (q[i] <= q[j]) tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];
	for (i = l, j = 0; i <= r; i++, j++)
		q[i] = tmp[j];
}


/* 二分查找(双闭区间) */  //一般题目中出现希望什么什么尽可能大，就可能是在考察二分查找
int binarySearch(vector<int>& nums, int target) {
	// 初始化双闭区间[0, n-1],即i,j分别指向数组首元素、尾元素
	int i = 0, j = nums.size() - 1;
	// 循环，当搜索空间为空时跳出(当i > j时为空)
	while (i <= j) {
		int m = i + (j - i) / 2; // 计算中点索引 m
		if (nums[m] < target) // 此情况说明target在区间[m+1, j]中
			i = m + 1;
		else if (nums[m] > target) // 此情况说明 target 在区间[i, m-1]中
			j = m - 1;
		else 
			return m;
	}
	// 未找到目标元素,返回 -1
	return -1;
}

/* 埃式筛法 */
int main(){
	int N;
	std::cin >> N;

	std::vector<bool> is_prime(N + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i] == true) {
			for (long long j = (long long)i * i; j <= N; j += i) {
				is_prime[i] = false;
			}
		}
	}

	return 0;
}