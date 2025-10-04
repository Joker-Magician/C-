#pragma once

#include "Renderer.h"

class Texture
{
private:
	unsigned int  m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP; //实际纹理的每像素位(m_BPP)
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const; // unsigned int slot = 0表示这是一个可选参数，如果不指定即为0，指定的那就是我们想要绑定纹理的插槽(slot)
	void Unibind();

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};
