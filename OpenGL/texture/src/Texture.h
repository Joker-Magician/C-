#pragma once

#include "Renderer.h"

class Texture
{
private:
	unsigned int  m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP; //ʵ�������ÿ����λ(m_BPP)
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const; // unsigned int slot = 0��ʾ����һ����ѡ�����������ָ����Ϊ0��ָ�����Ǿ���������Ҫ������Ĳ��(slot)
	void Unibind();

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};
