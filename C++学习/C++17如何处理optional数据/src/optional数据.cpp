#include<iostream>
#include<optional>
#include<fstream>
//����һʹ��bool�ж������Ƿ���Ч
//std::string ReadFileAsString(const std::string& filepath,bool& outSuccess)//��һ����������ȡ�ļ�
//{
//	std::ifstream stream(filepath);//������һ���ļ������������ȡ����������Ҫ��ȡ���ļ�·��
//	//�������������ļ���������Ҫ�����Ƕ�ȡ�������������Ч�Ļ����ļ����ǳɹ��ģ��ֻ�������Ч�����޷��򿪣�������ҲҪ������
//	if (stream)
//	{
//		std::string result;
//		//read file
//		stream.close();
//		outSuccess = true;
//		return result;//�������Ƕ������ַ���
//	}
//
//	outSuccess = false;
//
//	return std::string();//���ɹ����Է���һ�����ַ���return ""��Ҳ���Է���һ������������ַ���
//}

//������ʹ��std::optional�ж������Ƿ���Ч
std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		//read file
		stream.close();
		return result;
	}

	return {};//�����Ƿ���һ��std::opional��������{}
}

int main()
{

//	bool fileOpenedSuccessfully;
//	//���ص������Ǻ���֪���ļ��Ƿ񱻳ɹ���
//	std::string data = ReadFileAsString("data.txt",fileOpenedSuccessfully);
//	//if (data != "")//һ�������ж�data�Ƿ�Ϊ�գ����������Ǻܺá����Ǹ���֪�������ܷ񱻳ɹ���ȡ�ķ���
//	//{}				//��ΪҲ���Ǹ��ļ���������ǿյģ�������������Ч�ģ�������Ҫһ�ַ�����ȷ�����Ƿ���Ч
////��һ�ַ��������һ������ֵ, ����ȡ��Ϊsuccess
//	if(fileOpenedSuccessfully)//��ȿ��ַ���Ҫ��
//	{ }
 
//�ڶ��ַ�������ʹ��std::optional
	std::optional<std::string> data = ReadFileAsString("data.txt");
	
	std::string value = data.value_or("Not present"); //data.value_or�����ǣ��������ȷʵ������std::optional�У��������ظ������Ǹ��ַ�������������ڣ����᷵�����Ǵ�����κ�ֵ
//���ڽ����ļ�ʱ�ǳ����ã�������ȡ�������κ��Ѿ����õ�Ԫ�أ���Ϊͨ������ܻ����ļ���һЩ�����ǿ�ѡ�ģ����ĳ������û�����ļ������ã������ʹ����ָ����Ĭ��ֵ
	std::cout << value << std::endl;

	//std::optional<int> count;//������ǿ�������һ����׼���ԣ����ļ����������ڻ�׼�����еĴ���
	//int c = count.value_or(100);//����ļѴ��ڣ����ǿ�����ȡ�������,��������ڣ�����ʹ��Ĭ��ֵ100

	if (data.has_value())//���data.has_value��true������ζ�ſ�ѡ���Ѿ�������;����Ҳ����д��if(data),��Ϊdata������һ��bool�����
	{
		std::cout << "File read successfully!\n";
	}
	else
	{
		//std::string& string = *data;//��������ͨ�ַ�������ʽ������
		//data.value();����Ҳ����
		std::cout << "File could not be opened!\n";
	}
//����ǰ���ڸ���Ŀ����ǰ����һ��data.txt�ļ�.r����ֶ��ڸ���Ŀ��ɾ�����ļ�������˵�ļ����ܴ�
	std::cin.get();
}

/*�ܶ�ʱ��������һ���������ݵĺ����������������ڶ�ȡһ���ļ��������������ļ����ܱ���ȡ���ᷢ��ʲô�����Ƿ񲻴��ڣ��ֻ������ݲ��������������ĸ�ʽ
�ܶ�ʱ��������Ȼ��Ҫ�Ӻ����з���һЩ������������ض�������£������ֻ����һ�����ַ��������Ⲣ���Ǻܺã���Ϊû�ж�����塣
����ļ��ǿյģ�����Ӧ���а취���������Ǵ��ڻ��ǲ����ڣ������Ҫ�õ�std::optional�ĵط�������һ��C++17��������*/