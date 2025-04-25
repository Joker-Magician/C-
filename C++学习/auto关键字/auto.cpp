#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>


std::string GetName_1()
{
	return "Cherno";
}

//char* GetName_2()
//{
//	return "Cherno";
//}


class Device {};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};


int main()
{
	auto a = 5;//auto���Զ��ƶϳ�a�����ͣ������Ĺ��ŵ�a���ǻ���ʾ"int a"
//ʹ��auto����ֱ�����޸ı�����ֵ�����������޸�ǰ�涨�������
	std::cout << a << std::endl;


	auto name1 = GetName_1();//����auto�ͻ��Զ��ƶ�name������Ϊstd::string,��Ҳ��ζ������������ͼ�ʹ��Ϊchar*����Ҳ���Զ��޸ģ����ض����޸�
	auto a1 = name1.size();

	//std::string name2 = GetName_2();//���ʹ��std::string�������һ����ʽ���첢�ҿ�������ʹ��.sizeȡ��С,���ʹ��auto�����.size�����ᱨ��(���������ĺ������ʹ�char*�Ļ�std::string�Ϳ�����)
	//int a2 = name2.size();
//���൱��Ӳ�ҵ������ԣ�һ��������Ҹı��ҵ�api,������Ҹı�GetName�����ķ���ֵ����Ϊstd::string,δ�����ܽ����Ϊchar*���ͻ��˲���Ҫ���κθĶ�����ܺ��Ҳ�֪��api�Ѿ��Ķ���
//ͬʱ��Ҳ��һ�����£���Ϊ�Ҳ�֪��api�Ѿ��ı䣬�����ܻ��ƻ��������ض����͵Ĵ���

//auto���ܵ�ʹ�ó���
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++){
		std::cout << *it << std::endl;
	}
	for (auto it = strings.begin(); it != strings.end(); it++) {//ʹ��auto������ʶ���Ǹ��޴������
		std::cout << *it << std::endl;
	}


	DeviceManager dm;
	const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();
	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	
	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;
	const DeviceMap& devices = dm.GetDevices();
	//�������������ַ�ʽ������ʹ�����־޴������,�����Ҫά��һЩ�Ƚ��ϾɵĴ��������typedef

	const auto& devices = dm.GetDevices();//����Ҳ����ʹ��auto������޴�����ͣ�ͬʱʹ��const��&������һ�θ��Ʋ���

	std::cin.get();
}

//�����Ĵ�����int��char��float�������ʹ��auto����Ϊ�����ή�ʹ���Ŀɶ��ԣ����Ƕ��ڳ�������ǳ�����