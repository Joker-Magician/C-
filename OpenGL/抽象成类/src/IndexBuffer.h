#pragma once

class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count); // ��Ϊ���ﲻ��Ҫ̫��������ֱ��ʹ���޷�������unsigned int,����ʹ��32��16λ��
	~IndexBuffer();		// ����Ϊ�����ṩ��unsigned int������void������û��Ҫʹ���ֽڴ�С��������Ҫ����ͳ�����������ṩ�˶�������
						//����ʹ��size��count�������������ʣ���ʹ��sizeʱ���������������ֽ�Ϊ��λ(������ǿ�������ע��)������size��ʾ�ֽ���,count��ʾԪ����,�������������Ҫ��������������������ζ��д6���Ǿ���ͳ�ƣ�û��д6*4=24 ���ǻ���size
	void Bind() const;
	void Unbind() const;
};