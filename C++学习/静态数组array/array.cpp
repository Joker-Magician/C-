#include<iostream>
#include<array>//�һ�ת���ĵ�����ֱ�Ӳ鿴�Ƚ���Ҫ��array��Դ����

void PrintArray(const std::array<int,5>& data)//������ʽ��ֱ�Ӵ�����5������ڲ�֪��������¿���ʹ��ģ��
{
	for (int i = 0; i < data.size(); i++)
		std::cout << data[i] << std::endl;
}
//����Ϊ�ο�����
template <int N>
void PrintArrayNew(const std::array<int, N>& arr)
{
	for (int i = 0; i < arr.size() :i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

void PrintArrayOld(int* array, unsigned int size)
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << std::endl;
}

int main()
{
	//std::array��C���Եķ����һ�µ�
	std::array<int, 5>data;
	data[0] = 2;
	data[4] = 1;
	data[5] = 2;
//ʹ��array����ڴ�ͳ��ʽ���Ե�������sort��SLT�����������
//������debugģʽ�£�array����һ���߽��飬����array��ֱ��data[5] = 2����ʾ������ͳC���Բ��ᣬʵ����������Ҳ�ǿ��Եģ�
	//��ֻ�Ḳ����ʵ���ϲ���ӵ�е����ݣ��㻹û�з��������

	int dataOld[5];
	dataOld[0] = 0;
	dataOld[5] = 0;

//������ʹ���������ڴ��еĴ洢��ʽ��һ���ģ����Ǵ洢�洢��ջ�ϵ�
//������std::vector��ĵط����ڶ��ϴ����ײ����ݴ洢��

	std::cin.get();
}

//��̬���鼴�Ǵ�С�̶�������
//�µ����Բ���һ��Ҫʹ�ã����Ǳ������ĸ��û�����Ǵ��������ϵ����������ƵĶ�����������ʹ����
//��ʹ�µ����������ǵĴ��뿴�������ã�ȴ������������û������ȥʹ����