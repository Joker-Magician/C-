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
	auto a = 5;//auto会自动推断出a的类型，当鼠标的贯标放到a上是会显示"int a"
//使用auto可以直接在修改变量的值，而不用再修改前面定义的类型
	std::cout << a << std::endl;


	auto name1 = GetName_1();//这里auto就会自动推断name的类型为std::string,这也意味着如果上面类型即使改为char*这里也会自动修改，不必二次修改
	auto a1 = name1.size();

	//std::string name2 = GetName_2();//如果使用std::string这里会有一个隐式构造并且可以正常使用.size取大小,如果使用auto下面的.size操作会报错(如果将上面的函数类型从char*改回std::string就可以了)
	//int a2 = name2.size();
//这相当于硬币的两面性，一方面如果我改变我的api,即如果我改变GetName函数的返回值类型为std::string,未来可能将其改为char*，客户端不需要做任何改动，这很好我不知道api已经改动了
//同时这也是一件坏事，因为我不知道api已经改变，它可能会破坏依赖于特定类型的代码

//auto可能的使用场景
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++){
		std::cout << *it << std::endl;
	}
	for (auto it = strings.begin(); it != strings.end(); it++) {//使用auto来代替识别那个巨大的类型
		std::cout << *it << std::endl;
	}


	DeviceManager dm;
	const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();
	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	
	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;
	const DeviceMap& devices = dm.GetDevices();
	//可以用以上两种方式来避免使用这种巨大的类型,如果想要维护一些比较老旧的代码可以用typedef

	const auto& devices = dm.GetDevices();//这里也可以使用auto来避免巨大的类型，同时使用const和&来避免一次复制操作

	std::cin.get();
}

//如果你的代码是int、char、float等请避免使用auto，因为这样会降低代码的可读性，但是对于长类型这非常有用