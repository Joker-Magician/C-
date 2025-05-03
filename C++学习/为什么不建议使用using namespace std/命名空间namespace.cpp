#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void apple_print(const std::string& text)
{
	std::cout << text << std::endl;
}//��ͳ��C������û�������ռ��д��Ӧ���������ģ����Ա���������ͻ

namespace apple1 { namespace function {
//������VS�Զ���������ʽ(�����Ų�����)����������д�����ڷ����༶�����ռ�Ƕ���ǣ�������һ��������������������������������
		void print(const char* text)
		{
			std::cout << text << std::endl;
		}
		
	}
}

namespace apple {

	void print(const char* text)
	{
			std::cout << text << std::endl;
	}

	void print_again();
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
	apple1::function::print("Hello");

	apple::print("Hello");//::�������ռ��������д�Ͼ���ζ�Ž�������������ռ�
//ͬ���ķ���Ҳ�����������У���Ϊ�౾����������ռ�

	/*using namespace orange/apple;�������������޸�
	print("Hello");*/
	using apple::print;//ֻ����ʹ��apple�е�print����
	print("Hello");
	apple::print_again();//������Ȼ��Ҫָ��print_again()�����ĸ������ռ�

	namespace a = apple;
	a::print("Hello");//���Ը�apple�����ռ�һ������

	namespace b = apple1::function;
	b::print("Hello");


	std::cin.get();
}

//�����ռ����ҪĿ���Ǳ���������ͻ
//������ϣ���ܹ��ڲ�ͬ���������е�����ͬ�ķ��ţ��Ϳ����õ������ռ�