#include<iostream>
#include<memory>

void* operator new(size_t size)//�⴮�������˼�ǲ�Ҫʹ�ñ�׼���е�new��������������ʵ���ϻ����ӵ����������
{//��Ϊnew��ͨ������������еģ��������Ǻ���������һЩ����
	std::cout << "Allocating " << size << " bytes\n";//����д����һ���ô��ǿ��Ժ�������return����һ���ϵ�

	return malloc(size);//��Ϊ����Ӱ��������У���ֻ�򵥷���malloc(size)
}//����һ��voidָ��,��ֻ��һ���ڴ��ַ
//����Ҫ�����Ƿ����ʵ��������ڴ棬������һ��ָ����ڴ��ָ��

struct Object
{
	int x, y, z;
};

void operator delete(void* memory, size_t size)
{
	std::cout << "Allocating " << size << " bytes\n";//����д����һ���ô��ǿ��Ժ�������return����һ���ϵ�

	free(memory);
}

int main()
{

	//Object* obj = new Object;//�ѷ��䣬�����ص������μ�������Ķ���
	{
		//���ʹ������ָ�룬����ʾ����new������
		std::unique_ptr<Object> obj = std::make_unique<Object>();
		//���Ͽ���ͨ����operator new�����в���һ���ϵ㣬Ȼ���һ�ת����룬��ȷ��׷����Щ���ݷ������Դ
	}

	std::string string = "Cherno";
	std::cin.get();
}


//