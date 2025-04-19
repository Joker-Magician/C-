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

void Function(const std::vector<Vertex>& vertices)//在将vector传入函数中时要确保通过引用传递，这样可以确保没有把整个数组复制到这个函数中
{

}


int main()
{
	std::vector<Vertex> vertices;//std::vector<数组类型> 名称;
	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 });
	Function(vertices);

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	for (Vertex& v : vertices)//如果不加&就相当于将每个vertex复制到这个for范围循环中，但我们应该尽量避免复制所以要加上&,当然也可以加上const
		std::cout << v << std::endl;

	vertices.erase(vertices.begin() + 1);//删除单个元素，这里需要填一个迭代器

	for (Vertex& v : vertices)
		std::cout << v << std::endl;

	vertices.clear();//清除vertices列表，这样会将该数组大小设回0

	std::cin.get();
}