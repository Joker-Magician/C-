#include<iostream>
#include<string>
//#��Ԥ����ָ��,Ԥ�������ڱ�������ǰԤ���������ȹ�һ����Ĵ���

#define LOG_1(x) std::cout << x << std::endl//����Դ��ݲ���

//�껹�����õ���Ϸ�������־ϵͳ�У�ʹ����Debugģʽ(���ڵ���)����������־�����¼��Ϣ����releaseģʽ�򲻻������־��¼��Ϣ
//���÷���:1.�һ�����Ŀ->����->C/C++->Ԥ������->��ȷ������Ϊdebug����Ԥ��������������"PR_DEBUG;"(PR���ֿ����������ǵ���Ŀ)
//		   2.�һ�����Ŀ->����->C/C++->Ԥ������->��ȷ������Ϊrelease����Ԥ��������������"PR_RELEASE"

//#ifdef PR_DEBUG����д������
//#define PR_DEBUG 0����ֱ�Ӷ���ͨ��������������PR_DEBUGE��Ҳ����ֱ�������ù�������ֱ�Ӷ���"PR_DEBUG=1"
//ע�⣬��Ҫд��"PR_DEBUG = 1"�пո����ʽ��������release�汾��һ������������debug�汾�»���ʾ����

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl //���л�Ϊrelease�汾�Ǹò��ֻᱻ����
//#else
#elif defined(PR_RELEASE)//���Խ�else�ĳ�elif����ʽ
#define LOG(x)	
#endif

#if 0

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl 
#elif defined(PR_RELEASE)
#define LOG(x)	
#endif

#endif//����ʹ��"#if 0"��"#endif"�������۵�

//ʹ��define�����Ҫ������Ҫ��ÿ�������� "\"

int main()
{

	LOG("Hello");//x����ճ������Ķ���Ȼ��ŵ�����
	
	std::cin.get();
}