#define _CRT_SECURE_NO_WARNINGS
//#include<bits\stdc++.h>
#include<iostream>
#include<set>
#include<vector>
//set具有确定性：一个元素要么存在，要么不存在
	//互异性：一个元素仅可以在集合中出现一次
	//不具有无序性：在集合中自动按照从小到大的顺序排列
using namespace std;

int main()
{
	set<int> st;
	st.insert(1);//添加元素
	st.insert(2);
	st.insert(2);
	st.insert(0);

	//使用迭代器进行遍历
	for (set<int>::iterator it = st.begin(); it != st.end(); ++it) {
		cout << *it << endl;//使用*仅引用
	}
	//基于范围的循环
	for (auto& elem : st)
		cout << elem << endl;

	st.erase(2);//删除元素
	if (st.find(1) != st.end()) {//查询元素，如果元素不存在会返回尾迭代器，这个的意思是如果元素不等于尾迭代器(即存在),则输出yes
		cout << "yes" << endl;
	}
	if (st.count(2)) {//返回元素数量(set中只会返回0和1)，可借此达到检查有没有该元素的作用
		cout << "yes" << endl;
	}

	cout << st.size() << endl;//查大小
	st.clear();//清空
	cout << st.empty() << endl;//判空

	return 0;
}


//用法：
//可用于去重
//维护顺序
//元素是否出现过
//注意：不存在索引st[2]的写法是错误的