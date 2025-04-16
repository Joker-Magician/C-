#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<memory>

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print();

};



int main()
{
	{
		std::shared_ptr<Entity>e0;//ʹ�ù���ָ��shared_ptr����copy

		std::weak_ptr<Entity>e1;

		//ע��ʹ��unique_ptrָ�벻��copyָ�룬��ͻ�������ָ��ָ��ͬһ���ڴ棬������һ��ָ���ͷ��ڴ��ʱ����һ��ָ����Ȼָ����ڴ�ͻᷢ������
		{
			//����ʹ��unique_ptr�ķ�����һ��ֱ�ӵ���new�����ڴ����
			//std::unique_ptr<Entity>entity(new Entity());//ע�����ﲻ��ʹ����ʽת������Ϊunique_ptr�Ĺ��캯����explicit����Ҫ��ʾ���ù��캯�� 
			std::unique_ptr<Entity>entity = std::make_unique<Entity>();//�������ֳ����쳣��ȫ���ǣ������ڹ��캯�������׳��쳣��ʱ�����ȫ�����ղ�����Ϊ�õ�һ��û�����ÿ�ָ��������ڴ�й©


			std::shared_ptr<Entity>sharedEntity = std::make_shared<Entity>();//unique_ptr��ֱ�ӵ���new����Ϊ�쳣��ȫ����shared_ptr������Ϊ����������һ��������ƿ���ڴ棬�����洢���������������new Entity�ͻ��������ڴ����
			//����new Entity���ڴ���䣬Ȼ����shared_ptr�Ŀ��ƿ�ķ��䣬���ʹ��make_shared���Ϳ��԰��������������������Ч�ʸ���
			std::weak_ptr<Entity> weakEntity = sharedEntity;//weak_ptr���Ժ�shared_ptr����ʹ�ã����������ĺ�֮ǰ����sharedEntityһ������֮ǰ���������ü���,�����ﲻ���������ü���
//�����һ��shared_ptr��ֵ����һ��ʱ�������������ü���������ֵ��weak_ptr�򲻻ᣬ�������㲻��Entity������Ȩ����ǳ����á����򲻻��������ü��������������ᱣ֤�ײ����һֱ���
			e0 = sharedEntity;
			e1 = sharedEntity;

			entity->Print();
		}//shared_ptr�����ﲻ��������׷��shared_ptr��ջ������󣬵����������󣬵������ڴ汻�ͷţ����ж�����������ʱ�������ĵײ�Entity��ɾ����ʱ��
	}
	//����shared_ptr������
	std::cin.get();
}

//����ָ�����˵�����ڵ���new�����ڴ�ʱ�������Լ�ȥ����delete
//ʵ�����ںܶ�ʹ������ָ��������������������ȥ����new
//����ָ��ʵ�����Ƕ�ԭʼָ��İ�װ���������newΪ�������ڴ棬Ȼ�������ʹ�õ�����ָ�룬������ڴ����ĳһʱ���Զ��ͷ�

//����ʹ������ָ��ʱ������ʹ��unique_ptr����Ϊ�������Ľϵͣ������Ҫ������ʹ��shared_ptr�������Ϊ��һ��������ڴ�����������Ĵ�һ��