#include "Texture.h"

#include "stb_image/stb_image.h"

Texture::Texture(const std::string& path)
	: m_RendererID(0), m_FilePath(path), m_LocalBuffer(nullptr),
	m_Width(0), m_Height(0), m_BPP(0) //初始化
{
	stbi_set_flip_vertically_on_load(1); //垂直翻转我们的纹理，因为OpenGL希望我们的纹理像素从左下角(0,0)开始
	m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4); //该函数是为了写入宽度、高度、每像素位等，为我们写入到那些实际的变量，所以我传入这些变量的指针；最后的参数是预期通道，因为想要使用RGBA所以是4

	GLCall(glGenTextures(1, &m_RendererID));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

	//对于纹理我们需要指定这四个参数，如果不指定则只会得到一个黑色的纹理
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)); // 设置任何纹理参数,i是指类型为int;GL_TEXTURE_MIN_FILTER缩小过滤器，表示如果它需要渲染的比它的像素要小，我们的纹理如何被模拟下来;最后的参数是线性重新取样
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)); // MAG放大过滤器
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE)); // 嵌入模式(实际为环绕模式),WRAP_S是水平环绕，如果我们想要嵌入这意味着我们不希望它扩大区域，另一个选项是平铺
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE)); // S和T有点像x和y

	//给OpenGL我们在上面m_LocalBuffer读取到的数据
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer)) //GL_RGBA8参数表示指定每个通道的实际比特数，即希望OpenGL如何存储你的纹理;最后如果还没有准备好数据可以先传一个空指针，这意味只在显存上分配了空间
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer); //如果m_LocalBuffer确实有数据就调用stbi_image_free来释放内存
}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &m_RendererID));
}

void Texture::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot ));//指定一个纹理槽,使用枚举(enum)类型
	GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
}

void Texture::Unibind()
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
