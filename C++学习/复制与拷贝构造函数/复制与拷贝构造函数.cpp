#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

struct Vector2
{
	float x, y;
};

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];//new char[m_Size]��Ӧ���ټ�����ֹ��������+1
		memcpy(m_Buffer,string,m_Size + 1);//Ŀ�ġ���Դ����С��ʵ�ָ��Ƶ��������Ĺ���
		m_Buffer[m_Size] = 0;//Ҳ�����ֶ������ֹ��
	}

	String(const String& other)//��ȸ���(���)��C++���Զ�Ϊ�����ṩһ���������ƺ���
		:m_Size(other.m_Size)
	{
		std::cout << "Copied String!" << std::endl;

		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()//������������ڴ�й¶
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);//������Ϊ��Ԫʹ����Է��ʵ������ڲ���˽�б���
};

std::ostream& operator<<(std::ostream& stream, const String& string)//����<<������
{		//�൱�ڸ�<<��һ���Զ��幦�ܣ�������������Զ��������
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& string)//���ֱ�ӵ���PrintString(String string)����������Copied String!����ӡ����Ϊ������ÿ����һ���ַ����������ڶ��Ϸ����ڴ棬�������е��ڴ棬��������ͷ��ڴ棬����ȫû�б�Ҫ
{	//���������������ǣ������е��ַ���ֱ�ӽ������PrintString��������Ϊ����֪�����ǲ���Ҫ������������Ҫ������һ�����������ǿ���ֱ���������е�string���������Ǿ�ֻ��һ�����������Ʒ�����String second = string����������ֱ�Ӵ����ã���String�����ʵ���ϲ����޸��ַ�������������Ӧ�ñ��Ϊconst����
	
	String copy = string;//�������Ҫ���ƾ�Ӧ��������
	
	std::cout << string << std::endl;	//������ǲ����Ϊconst,����ζ�����ǿ���ֱ�ӱ༭�ַ���Ҳ��ζ�����ǿ��Խ���ʱ����ֵ���ݵ�ʵ�ʵĺ�����
}

//������İ�����֪������Ҫͨ��const����ȥ���ݶ�����Ϊ��д�ĺ�����������Ծ����Ƿ�Ҫ���ƣ��ں������ڲ�������û�����ɵ������ƣ����ǻ�������ĳ���



int main()
{
	Vector2 a = { 2, 3 };
	Vector2 b = a;
	b.x = 5;//��������ı�a��ֵ����Ϊb=aֻ���൱�ڽ�����һ����������ֵ������b


	Vector2* a1 = new Vector2();
	Vector2* b1 = a1;//�������൱�ڸ�����ָ�룬a��bͬʱָ��ͬһ���ڴ��ַ
	b1->x = 2;//���ͬʱӰ��a��b���������Ĳ���Ӱ��ָ�룬����Ӱ���ڴ��ַ

/*  ����д�Ⱥ�ʱ����ʹ�ø�ֵ����������һ����������Ϊ��һ������ʱ��������(����Ҫ���*��)�������ڸ���ֵ��
��������Ҫ�����Ǻ�*������Ϊ���á������������������һ�����ã���ʵ�㲻�����·������á����㸴������ʱ��
��һ�����ø�ֵ������һ�����ã���ʵ����ʵ�ڸı�ָ����Ϊ����ֻ�Ǳ���(��û�и���).�������ó���
    ÿ�����дһ����������ֵ��һ�������Ĵ���ʱ���������ڸ��ơ���ָ����ڵ�����£����ڸ���ָ�룬Ҳ�����ڴ��ַ���ڴ��ַ�����֣�
�������ֶ��ѣ�������ָ��ָ���ʵ���ڴ�*/


	String string = "Cherno";
	String second = string;//����������ǳ������C++����char*��unsigned int��ɵ�Sting��ֱ�Ӹ��Ƶ�һ���µ��ڴ��ַ���棬����µ��ڴ��ַ������second�ַ�����
	//������������String��������ͬ��char*��ֵ������ͬ���ڴ�ָ�롣���Ե����������ʱ�����������ᱻ���ã�Ҳ���ǳ�����ͼ�����ͷ�ͬһ���ڴ�
	//��ˣ�����ͻ������

	second[2] = 'a';

	//std::cout << string << std::endl;
	//std::cout << second << std::endl;

	PrintString(string);
	PrintString(second);


	std::cin.get();
}