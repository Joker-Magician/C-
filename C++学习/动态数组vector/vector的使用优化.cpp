#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		:x(x), y(y), z(z)
	{
	}

	Vertex(const Vertex& vertex)
		:x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

int main()
{
	std::vector<Vertex> vertices1;

	vertices1.push_back(Vertex(1, 2, 3));//���vertices.push_back({1, 2, 3})����������һ����
	vertices1.push_back(Vertex(4, 5, 6));
	vertices1.push_back(Vertex(7, 8, 9));//ʹ�ù��캯��������
/* �������ӡ6��"Copied" */
/*������Ϊ����ʵ���������������ĵ�ǰ֡ջ�й�����������main��ջ�ϴ�����������Ҫ�����ǰ����ŵ����vector�У�
���������Ҫ��main���������������vertex�ŵ�ʵ�ʵ�vector������ڴ��У�Ҳ�������ǽ�vertex��main�������Ƶ�vector����
���Ƿ��ĵ�һ������Ҳ�ǿ����Ż��ĵط���
��һ����vector�ڴ�������1��3�仯�����Σ��������һ�θ���*/

	std::cout << std::endl;

	/*��������㹻�˽����ǵĻ�����֪��Ҫ������Ԫ�أ���Ϊʲô��ֱ�Ӹ������أ���ֱ�������㹻3��������ڴ棬�����Ͳ���������δ�С�ˣ���ڶ����Ż�*/
	std::vector<Vertex> vertices2;//ֱ���ڹ��캯���д���3����������������ͨ������ʵ�ʻṹ������vertex�������ǲ����빹���κζ�������ֻ�����㹻���ڴ�����������
	vertices2.reserve(3);//reserve����Ϊ�����ṩ�㹻�Ŀռ�
	vertices2.push_back(Vertex(1, 2, 3));
	vertices2.push_back(Vertex(4, 5, 6));
	vertices2.push_back(Vertex(7, 8, 9));
	/* ������ֻ����ӡ3��"Copied" */
	//������Ȼ��һ�θ�������Ϊ����main�����й���ģ�Ȼ���Ƶ�ʵ�ʵ�vector��

	std::cout << std::endl;



	std::vector<Vertex> vertices3;
	vertices3.reserve(3);
	vertices3.emplace_back(1, 2, 3);//ʹ��emplace_back����ֻ�����˹��캯���Ĳ����б��������vector
	vertices3.emplace_back(4, 5, 6);//������ʵ�ʵ�vector�ڴ��У�ʹ�����²���������һ��vertex����
	vertices3.emplace_back(7, 8, 9);
	/* �����Ͳ����ӡ"Copied"����û�ж���ĸ����� */

	std::cin.get();
}

/*�Ż�������Ҫ����֮һ���˽���Ļ�������֪����������������ģ��Ҹ���ô����Ӧ��Ӧ�ûᷢ��ʲô
vector�����������㴴��һ��vector,Ȼ��ʼpush_backԪ��(���Ԫ��)�����vector�����������󣬲�����������Ҫ����Ԫ�أ���vector��Ҫ�����µ��ڴ棬�����㹻������Щ��Ҫ�������Ԫ��
��ǰvector�����ݣ����ڴ��о�λ�ø��Ƶ��ڴ��е���λ�ã�Ȼ��ɾ����λ�õ��ڴ档
���������һ���µ�Ԫ�أ����ڴ�����ͻ������С�����·��䡣����ǽ�����������ԭ��֮һ��
��ʵ�ϣ�������Ҫ���ϵķ��䣬��Ҫ������������Ԫ�أ�����һ�������Ĳ�����������Ҫ����ġ�*/
//������ǵ��Ż����Ծ�����α��⸴�ƶ���
