#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void apple_print(const std::string& text)
{
	std::cout << text << std::endl;
}//��ͳ��C������û�������ռ��д��Ӧ���������ģ����Ա���������ͻ

namespace apple { namespace function {
//������VS�Զ���������ʽ(�����Ų�����)����������д�����ڷ����༶�����ռ�Ƕ���ǣ�������һ��������������������������������
		void print(const char* text)
		{
			std::cout << text << std::endl;
		}
	}
}

namespace orange {

	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}

}


int main()
{
	apple::function::print("Hello");//::�������ռ��������д�Ͼ���ζ�Ž�������������ռ�



	std::cin.get();
}

//�����ռ����ҪĿ���Ǳ���������ͻ
//������ϣ���ܹ��ڲ�ͬ���������е�����ͬ�ķ��ţ��Ϳ����õ������ռ�