#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

int main()
{
	std::vector<int> values = { 3, 5, 1, 4, 2 };
	std::sort(values.begin(), values.end());//������ṩ�κ�ν�ʻ����������������ᰴ����������
	
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;

//�����Ҫ�ṩĳ�ַ�ʽ�������򣬿���ͨ������һ��������ʵ�֣����ȿ�����һ���㴴���Ľṹ���ڵĺ�����Ҳ������һ��lambda��Ҳ���������ú���
	std::sort(values.begin(), values.end(), std::greater<int>());//��ᰴ�մӴ�С����
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;

//bool cmp(const Type1 &a, const Type2 &b)����ȽϺ����᷵��һ��boolֵ��ture��false��������Ǵ���ĵ�һ����������ǰ��Ļ�����ô����ture
	std::sort(values.begin(), values.end(), [](int a, int b)//����������Ǹ�������ֵa��b����һ��Ӧ������ǰ�棬���������Ҫȷ����
		{//�������ture������ζ��a�ᱻ����b֮ǰ����������Ƿ���false����ôb�ͻ���a֮ǰ
			return a < b;//���a<b���������е��б��ǰ��
		});//����ʹ��lambda
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;

	std::sort(values.begin(), values.end(), [](int a, int b)//����������Ǹ�������ֵa��b����һ��Ӧ������ǰ�棬���������Ҫȷ����
		{
			return a > b;
		});
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;

	//��1�ŵ����
	std::sort(values.begin(), values.end(), [](int a, int b)//����������Ǹ�������ֵa��b����һ��Ӧ������ǰ�棬���������Ҫȷ����
		{
			if (a == 1)
				return false;
			if (b == 1)
				return true;

			return a < b;
		});
	for (int value : values)
		std::cout << value << std::endl;
	std::cout << std::endl;


	std::cin.get();
}

//��C++����std::sort�У�������Ҫ�����ṩһ��������������һ����ʼ��������һ���������������������ڵ����ж���������������ṩ��ĳ��ν������
//���ǿ��Բ��ṩν���ô���᳢�Ի������ͽ�����������Ҳ���Ը����ṩһ����������lambda��������Щ�����������
//std::sortû���κη���ֵ������ĸ��Ӷ���N*logN