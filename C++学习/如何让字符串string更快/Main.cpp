#include<iostream>
#include<string>

static uint32_t s_AllocCount = 0;//����������(ע��Ҫ��32λ��x86������)

void* operator new(size_t size)//�����ڴ棬����new���������鿴�ڴ汻�����˶��ٴ�
{
	s_AllocCount++;//�����������
	std::cout << "Allocating " << size << " bytes\n";//��ӡ����Ĵ�С
	return malloc(size);
}
#define STRING_VIEW 1//ʹ��ԭʼ�ַ�
#if STRING_VIEW//�ص�STRING_VIEW
void PrintName(std::string_view name)
{
	std::cout << name << std::endl;
}
#else
void PrintName(const std::string& name)//��Ȼ���ܵ���const���ã�������Ȼ��ҪΪ���ǹ���һ��std::string,��������Ҫ�����ڴ�
{
	std::cout << name << std::endl;
}
#endif

int main()
{
	//std::string name = "Yan Chernikov";//��Ҫ���������0������������ȫ��ʹ��std::string
	////const char* name = "Yan Chernikov";//����һ����̬�ַ�������ȫû�б�Ҫʹ��std::string

	//PrintName(name);
	//
	//std::cout << s_AllocCount << " allocations" << std::endl;//��ӡ�������
	//
	//s_AllocCount = 0; std::cout << std::endl;//1

	//std::string name = "Yan Chernikov";

	std::string name = "Yan Chernikov";
#if STRING_VIEW
	std::string_view firstName(name.c_str(),3);//��������ù��캯����ָ�����ַ���,ͨ��name.c_str()����������ַ���namedconst char*����
	std::string_view lastName(name.c_str() + 4, 9);
	//std::string_view firstName(name, 3);
	//std::string_view lastName(name + 4, 9);
#else
	std::string firstName = name.substr(0, 3);
	std::string lastName = name.substr(4, 9);//��������û�������ٲ������Ѿ���3�������ˣ��������һЩʵʱ���еĳ�����Ӧ�û���Ϸ�����ƵĶ�������ÿ֡�����������£�����ѻ����������������֡����
#endif

	PrintName("Cherno");
	PrintName(firstName);
	PrintName(lastName);//ʹ��string_view��ֻ��1�η�����
	//PrintName(name.substr(0, 3));//������������4�����䣬��Ϊ���������Ǵ�����һ��ȫ�µ��ַ����������Ա仯�����Լ����ڴ棬������������Ҫ�����Ǹ��ַ�����ʵ��ͼ�������Ҫstring_view����������

	std::cout << s_AllocCount << " allocations" << std::endl;//��ӡ�������

//std::string_view��Ȼ��C++17�������ԣ�ʵ������C++17֮ǰ�Ϳ����á���������ֻ��һ��ָ�������ڴ��ָ�룬���仰˵������һ��const charָ�룬ָ��������ӵ�е������ַ������ټ���һ����Сsize
//��˶���Yan Chernikov������֣��ҿ�����һ��ָ���һ���ַ���ָ�룬Ȼ���С��3����������ǵ����ַ�����Ȼ���ҿ�����һ��ָ��ָ���Ǹ��ַ����Ŀ�ͷ�����ĸ��ֽڣ����Ҵ����Ǹ�lastName�Ŀ�ͷ
//���仰˵�����ڴ���һ�����ڣ�һ�����������ڴ��С��ͼ�������Ƿ���һ���µ��ַ�������substr()����һ���µ��ַ���
//�������ĺô����Ҳ����ڴ����Լ����ַ�������ֻ���ڹ۲�һ�����е��ַ�����û���ڴ���䣬��ֵ�����ַ�����ͼ�Ƿǳ���������
	
	std::cin.get();
}

//�������кܶ��ַ�����������ʽ���ı���������־��¼��ʹ����ȷ��ʽ��ʹ�����ַ����ȵȣ��Ⲣ����ֻ������һ���ַ�û�������⣬���ҷǳ���,������Ϊ����Ҫ�����ڴ�
//�ڶ��Ϸ����ڴ沢��һ���Ǽ����£���ʵ���ںܶ���������ǲ��ɱ���ģ����������Ա������Ӧ�ñ��⣬��Ϊ���ή�ͳ�����ٶȣ�std::string�����ĺܶຯ����ϲ�����䣬����ʵ���ϲ�������


//�����ܹ������������һ����ʹ���ַ�������һ����ʹ���ַ�����ͼ