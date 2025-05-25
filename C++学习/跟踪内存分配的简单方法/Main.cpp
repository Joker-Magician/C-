#include<iostream>
#include<memory>

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;//��ʾ�ܹ�������ڴ�
	uint32_t TotalFreed = 0;//�ͷŵ��ڴ�

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }//��ǰʹ�õ��ڴ�
};

static AllocationMetrics s_AllocationMetrics;//����һ����̬ʵ��

void* operator new(size_t size)//�⴮�������˼�ǲ�Ҫʹ�ñ�׼���е�new��������������ʵ���ϻ����ӵ����������
{//��Ϊnew��ͨ������������еģ��������Ǻ���������һЩ����
	//std::cout << "Allocating " << size << " bytes\n";//����д����һ���ô��ǿ��Ժ�������return����һ���ϵ�

	s_AllocationMetrics.TotalFreed += size;

	return malloc(size);//��Ϊ����Ӱ��������У���ֻ�򵥷���malloc(size)
}//����һ��voidָ��,��ֻ��һ���ڴ��ַ
//����Ҫ�����Ƿ����ʵ��������ڴ棬������һ��ָ����ڴ��ָ��

void operator delete(void* memory, size_t size)//ͨ�����ص�delete���ͷ�����new���ڴ棬���ҿ���ͬ���size�ĺ�������ͨ����������ض��ĺ���ǩ������ȡ����Ϣ
{
	//std::cout << "Freeing " << size << " bytes\n";//����д����һ���ô��ǿ��Ժ�������return����һ���ϵ㣬Ȼ��۲쵽��ʵ��������ĳһ�����������������ɾ������ԭʼָ��  


	free(memory);
}
//ͨ�������������������ǾͿ��Դ����ڴ���������������ȷ�е�֪���ж����ڴ汻ʹ�ã��ж����ڴ汻���䣬�ж����ڴ汻�ͷ�

struct Object
{
	int x, y, z;
};

static void PrintMemoryUsage()
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main()
{

	////Object* obj = new Object;//�ѷ��䣬�����ص������μ�������Ķ���
	//{
	//	//���ʹ������ָ�룬����ʾ����new������
	//	std::unique_ptr<Object> obj = std::make_unique<Object>();
	//	//���Ͽ���ͨ����operator new�����в���һ���ϵ㣬Ȼ���һ�ת����룬��ȷ��׷����Щ���ݷ������Դ
	//}//��Ϳ�ͨ������delete�����ͷ��ˣ���ʵ���������unique_ptr������������ʵ������ɾ���˵ײ��ԭʼָ��


	//std::string string = "Cherno";

	PrintMemoryUsage();
	std::string string = "Cherno";
	PrintMemoryUsage();
	{
		std::unique_ptr<Object> obj = std::make_unique<Object>();
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

	std::cin.get();
}
