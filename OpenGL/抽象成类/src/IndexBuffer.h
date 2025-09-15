#pragma once

class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count); // 因为这里不需要太复杂所以直接使用无符号整数unsigned int,而不使用32或16位的
	~IndexBuffer();		// 又因为上面提供是unsigned int而不是void，所以没必要使用字节大小，我们想要的是统计现在我们提供了多少索引
						//可以使用size和count来区分这两个词，当使用size时，它几乎总是以字节为单位(如果不是可以留下注释)，但是size表示字节数,count表示元素数,如绘制正方形需要六个索引，六个索引意味着写6，那就是统计，没有写6*4=24 ，那会是size
	void Bind() const;
	void Unbind() const;
};