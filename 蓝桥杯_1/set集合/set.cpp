#define _CRT_SECURE_NO_WARNINGS
//#include<bits\stdc++.h>
#include<iostream>
#include<set>
#include<vector>
//set����ȷ���ԣ�һ��Ԫ��Ҫô���ڣ�Ҫô������
	//�����ԣ�һ��Ԫ�ؽ������ڼ����г���һ��
	//�����������ԣ��ڼ������Զ����մ�С�����˳������
using namespace std;

int main()
{
	set<int> st;
	st.insert(1);//���Ԫ��
	st.insert(2);
	st.insert(2);
	st.insert(0);

	//ʹ�õ��������б���
	for (set<int>::iterator it = st.begin(); it != st.end(); ++it) {
		cout << *it << endl;//ʹ��*������
	}
	//���ڷ�Χ��ѭ��
	for (auto& elem : st)
		cout << elem << endl;

	st.erase(2);//ɾ��Ԫ��
	if (st.find(1) != st.end()) {//��ѯԪ�أ����Ԫ�ز����ڻ᷵��β���������������˼�����Ԫ�ز�����β������(������),�����yes
		cout << "yes" << endl;
	}
	if (st.count(2)) {//����Ԫ������(set��ֻ�᷵��0��1)���ɽ�˴ﵽ�����û�и�Ԫ�ص�����
		cout << "yes" << endl;
	}

	cout << st.size() << endl;//���С
	st.clear();//���
	cout << st.empty() << endl;//�п�

	return 0;
}


//�÷���
//������ȥ��
//ά��˳��
//Ԫ���Ƿ���ֹ�
//ע�⣺����������st[2]��д���Ǵ����