#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << "," << vertex.y << "," << vertex.z;
	return stream;
}

void Function(const std::vector<Vertex>& vertices)//�ڽ�vector���뺯����ʱҪȷ��ͨ�����ô��ݣ���������ȷ��û�а��������鸴�Ƶ����������
{

}


int main()
{
	std::vector<Vertex> vertices;//std::vector<��������> ����;
	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 });
	Function(vertices);

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	for (Vertex& v : vertices)//�������&���൱�ڽ�ÿ��vertex���Ƶ����for��Χѭ���У�������Ӧ�þ������⸴������Ҫ����&,��ȻҲ���Լ���const
		std::cout << v << std::endl;

	vertices.erase(vertices.begin() + 1);//ɾ������Ԫ�أ�������Ҫ��һ��������

	for (Vertex& v : vertices)
		std::cout << v << std::endl;

	vertices.clear();//���vertices�б������Ὣ�������С���0

	std::cin.get();
}