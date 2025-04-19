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

	vertices1.push_back(Vertex(1, 2, 3));//这和vertices.push_back({1, 2, 3})所做的事情一样的
	vertices1.push_back(Vertex(4, 5, 6));
	vertices1.push_back(Vertex(7, 8, 9));//使用构造函数来创建
/* 这样会打印6次"Copied" */
/*这是因为我们实际上是在主函数的当前帧栈中构造它，即在main的栈上创建，我们需要做的是把它放到这个vector中，
因此我们需要从main函数把这个创建的vertex放到实际的vector分配的内存中，也就是我们将vertex从main函数复制到vector类中
这是犯的第一个错误，也是可以优化的地方。
另一个是vector内存容量从1到3变化了两次，多产生了一次复制*/

	std::cout << std::endl;

	/*如果我们足够了解我们的环境，知道要放三个元素，那为什么不直接告诉它呢？，直接制造足够3个对象的内存，这样就不会调整两次大小了，这第二个优化*/
	std::vector<Vertex> vertices2;//直接在构造函数中传入3，它编译甚至不能通过，它实际会构造三个vertex对象，我们并不想构造任何对象，我们只想有足够的内存来储存它们
	vertices2.reserve(3);//reserve可以为我们提供足够的空间
	vertices2.push_back(Vertex(1, 2, 3));
	vertices2.push_back(Vertex(4, 5, 6));
	vertices2.push_back(Vertex(7, 8, 9));
	/* 这样就只会会打印3次"Copied" */
	//我们仍然有一次复制是因为是在main函数中构造的，然后复制到实际的vector中

	std::cout << std::endl;



	std::vector<Vertex> vertices3;
	vertices3.reserve(3);
	vertices3.emplace_back(1, 2, 3);//使用emplace_back我们只传递了构造函数的参数列表，它会告诉vector
	vertices3.emplace_back(4, 5, 6);//在我们实际的vector内存中，使用以下参数，构造一个vertex对象
	vertices3.emplace_back(7, 8, 9);
	/* 这样就不会打印"Copied"，即没有多余的复制了 */

	std::cin.get();
}

/*优化的最重要规则之一是了解你的环境，即知道事情是如何运作的，我该怎么做，应该应该会发生什么
vector工作机制是你创建一个vector,然后开始push_back元素(添加元素)，如果vector的容量不够大，不能容纳你想要的新元素，那vector需要分配新的内存，至少足够容纳这些想要加入的新元素
当前vector的内容，从内存中旧位置复制到内存中的新位置，然后删除旧位置的内存。
当我们添加一个新的元素，将内存用完就会调整大小，重新分配。这就是将代码拖慢的原因之一。
事实上，我们需要不断的分配，需要复制所有现有元素，这是一个缓慢的操作，这是需要避免的。*/
//因此我们的优化策略就是如何避免复制对象
