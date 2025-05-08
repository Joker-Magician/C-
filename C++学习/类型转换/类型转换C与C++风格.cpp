#include<iostream>

class Base
{
public:
	Base() { }
	virtual ~Base() { }
};

class Derived : public Base
{
public:
	Derived() { }
	~Derived() { }
};

class AnotherClass : public Base
{
public:
	AnotherClass() { }
	~AnotherClass() { }
};

int main()
{
//C���Է������ת������Բ������ָ��ǿ��ת�������ͣ�Ȼ��������Ҫǿ��ת���ı���
	double value = 5.25;
	double a1 = value + 5.3;
	std::cout << a1 << std::endl;//10.55
	double a2 = (int)value + 5.3;//��ʽת��
	std::cout << a2 << std::endl;//10.3

//C++���Է������ת����һ����static_cast��reinterpret_cast��dynamic_cast��const_cast������Ҫ��cast
	double s1 = static_cast<int>(value) + 5.3;
	/*double s2 = reinterpret_cast<AnotherClass*>(&value) + 5.3;����C++������˫�ؾͻ���һ����飬˵����Ĵ������������C��������ʱ����������*/
	

	//��Ҫ��ʶ�����ǣ����ǲ����κ�C�������ת�������������飬���ǿ��ܻ������������飬��ʵ�ʽ��Ҳֻ��һ���ɹ�������ת�����ѣ�C����ǿ��ת������ʵ��������Щ��
//�Ⲣ��������¹��ܣ���ֻ�������һЩ�﷨�ǵ���Ĵ�����

/*���磬���ǽ�ʵ��ִ��һ����飬���ת�����ɹ������ܷ���NULL,���������˶�������飬��Ҳ��ζ����ʵ���ϻ�����Ĵ��������������ڴ��������£�C++��������ת��Ҳ������������飬
����ֻ�ǷŽ�ȥӢ�ﵥ�ʣ�����static_cast����˼�Ǿ�̬����ת�����ھ�̬����ת��������£����ǻ�����һЩ�����ı���ʱ��飬��������ת���Ƿ���Ŀ���*/
/*reinterpret_castҲһ��������������˵��������˫����Ӣ�����Ա�����һ����reinterpret_cast����˼���Ұ�����ڴ����½��ͳɱ�Ķ��� */
/*const_cast,�Ƴ�������ӱ�����const�޶�*/

/*����ô��cast�ĺô��ǣ����˿����յ�����Щ����ʱ���֮�⣬�������ڴ��������������
C���Է������������������������������Ӣ�ĵ��ʿ��Ժ�����ȥ����*/

	Derived* derived = new Derived();

	Base* base = derived;//���������������ʵ��֪��base��Derived���һ��ʵ���������Ǽ�װ��֪��

	AnotherClass* ac1 = dynamic_cast<AnotherClass*>(base);//�������ʹ��static_cast��û����ģ���������C���Ե�����ת����һ���ģ�����ֱ�Ӹ����Ǹ�ֵ�����Ժ���ܻ�����⣬��Ϊ��֪��ac����AnotherClaee��ʵ��������Derived���ʵ��
	if (ac1)//����ac��NULL����Ϊac��Derived�಻��AnotherClass
	{

	}
	Derived* ac2 = dynamic_cast<Derived*>(base);
	if (ac2)//���������ָ������Ч�ģ���Ϊ���ת���ǳɹ���
	{

	}
/*����dynamic_cast��һ���ܺõķ��������ת���Ƿ�ɹ�����������ʱ������ϢRTTI(runtime type information)������ϵ*/

	std::cin.get();
}

//C++��һ��ǿ�������ԣ������һ��������Ϊint���Ͳ��ܰ�������double��float�����ƵĶ�����ʹ�ã��ұ������ҵ����ͣ�������һ���򵥵���ʽת��������ζ��C++֪�����������������֮��ת��������û��������ʧ���������ʽת��
//������һ����ʾת�������Ǹ���C++���٣�����Ҫ���������ת�����������

// cast ��Ϊ static_cast dynamic_cast reinterpret_cast const_cast
// static_cast static_cast ���ڽ��бȽϡ���Ȼ���͵ͷ��յ�ת���������ͺ͸����͡��ַ���֮��Ļ���ת��, ��������ָ�����͵�ǿ��ת��
// reinterpret_cast ���ڽ��и��ֲ�ͬ���͵�ָ��֮��ǿ��ת��
// const_cast �����ڽ���ȥ�� const ���Ե�ת��
// dynamic_cast �����ת����ȫ�ԣ�������ʱ��飬�������ת��������null