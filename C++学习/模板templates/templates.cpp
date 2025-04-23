#include<iostream>
#include<string>


void Print(int value)
{
	std::cout << value << std::endl;
}

void Print(std::string value)
{
	std::cout << value << std::endl;
}

void Print(float value)
{
	std::cout << value << std::endl;
}

//����ʹ��ģ����ʵ��
template<typename T>	//����ѡ��typename��Ϊģ������(ʵ������class��һ���ģ�����classͨ�������뵽��)����T��Ϊ����
void Print_t(T value)	//����T�����;����������洫��Ĳ��������ͣ������������ʵ����ʽ�ĵõ���
{
	std::cout << value << std::endl;
}
//���ͨ��template����ľ���ģ�壬�����ڱ����ڱ���������������ʵ���ϲ�������Ĵ��룬Ҳ������ĺ�����ֻ�е�����ʵ�ʵ�������ʱ����Щ�����ű���Ĵ���
//ʵ���ϴ�����C++��׼ģ���ͬ����ȫʹ����ģ�壬ģ�岢�����������ں�����Ҳ���Խ���ת����һ��ģ��

//template<int N>
//class Array
//{
//private:
//	int m_Array[N];//�����N��Ϊ��ջ�ϴ���������Ҫʵ��ȷ���ģ��������ģ�屻����ʱ��������
//public:
//	int GetSize() const { return N; }
//};

template<typename T,int N>
class Array
{
private:
	T m_Array[N];//���������������ǿɱ��
public:
	T GetSize() const { return N; }
};


int main()
{
	Print(5);
	Print("Hello");//�������Ҫ��ӡ�ַ�������Ҫ��Print��������
	Print(5.5f);//�������������ͬ�ĺ����������ǳ�������������Ͳ�ͬ����������ͬ��(��Ϊcout���Խ������е�����)
	
	std::cout << std::endl;

	Print_t<int>(5);//����Ҳ����ʹ��<>��ָ������
	Print_t("Hello");
	Print_t(5.5f); //����Ĳ�������C++�ı��������Զ��Ƶ�������TӦ����ʲô,Ȼ�������ս�T�滻�����Ｔʹ����һ������ֵҲ�ǿ��Ե�
	//Print_t�ڲ�������ʱ�ǲ����ڵģ�ֻ�е����ǵ���ʱ�Ż�������Ǹ�����ģ�����������

	std::cout << std::endl;

	//�����ഴ����
	Array<int,5> array;
	std::cout << array.GetSize() << std::endl;

	std::cin.get();
}

//ģ�壬��Java��C#�������ƵĽ������ͣ�����������ͬ��ģ��Ҫ����ǿ��

//ģ�������㶨��һ�����Ը��������;���б����ģ�壬�൱���ñ���������һ�׹����������
