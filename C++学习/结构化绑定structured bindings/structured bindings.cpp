#include<iostream>
#include<string>
#include<tuple>

/*struct Person
{
	std::string Name;
	int Age;
};��ֻ��ҪPerson.Name\Person.Age�Ϳ��Է�����*/

std::tuple<std::string, int> CreatePerson()//һ���˵����������䣬���һ��Ԫ�飬<ֻд���ͼ���>
{
	return { "Cherno",24 };
}//ֻ�����������Խ�tuple��Ϊpair��tuple<>���������չ�����������

int mian()
{
	/*auto person = CreatePerson();//auto����Ϊstd::tuple<std::string, int>����������Ϊ������Щ��
	std::string& name = std::get<0>(person);//ͨ��get<0>��ȡ���ݿ���Ϊ0�ģ�Ҳ����std::string����
	int age = std::get<1>(person);*/

	//ʹ��tie
	//std::string name;
	//int age;
	//std::tie(name, age) = CreatePerson();
//����û��person�����ǽṹ�壬������һ�����ͣ���ֻ��һ���������������������Ҫ�Ķ�����������һ��string��һ��int.
//ʹ��tie������������tuple��Ư��һЩ������Ҫ��ȡ��Ա��ô�鷳��������Ȼ��Ҫ���д��룬��������Ȼ��̫�Ѻã��ҿ�����Ȼ���ýṹ��
	
	auto[name, age] = CreatePerson();//��������һ�����Ŀ����->C/C++->����->��C++��ΪC++17(Ĭ�Ͽ���Ҳ������)
	std::cout << name;


	std::cin.get();
}


//�ṹ���󶨽�������C++17������һ���µ����ԣ������Ǹ��õĴ���෵��ֵ
//�������ԭ�����ýṹ�崦��෵��ֵ�Ļ�������չ��һ�ִ���������·������ر�����δ���Ԫ��(tuple)�Ͷ���(pairs)�Լ������������Ķ���
//�ṹ���󶨼������ǵĴ��룬��������ǰ������������.һ���ж������ֵ�Ͱ������һ��Ԫ��ȵȣ�ʹ���ǵĴ���ɹ���
