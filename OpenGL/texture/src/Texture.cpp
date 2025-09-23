#include "Texture.h"

#include "stb_image/stb_image.h"

Texture::Texture(const std::string& path)
	: m_RendererID(0), m_FilePath(path), m_LocalBuffer(nullptr),
	m_Width(0), m_Height(0), m_BPP(0) //��ʼ��
{
	stbi_set_flip_vertically_on_load(1); //��ֱ��ת���ǵ�������ΪOpenGLϣ�����ǵ��������ش����½�(0,0)��ʼ
	m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4); //�ú�����Ϊ��д���ȡ��߶ȡ�ÿ����λ�ȣ�Ϊ����д�뵽��Щʵ�ʵı����������Ҵ�����Щ������ָ�룻���Ĳ�����Ԥ��ͨ������Ϊ��Ҫʹ��RGBA������4

	GLCall(glGenTextures(1, &m_RendererID));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

	//��������������Ҫָ�����ĸ������������ָ����ֻ��õ�һ����ɫ������
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)); // �����κ��������,i��ָ����Ϊint;GL_TEXTURE_MIN_FILTER��С����������ʾ�������Ҫ��Ⱦ�ı���������ҪС�����ǵ�������α�ģ������;���Ĳ�������������ȡ��
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)); // MAG�Ŵ������
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE)); // Ƕ��ģʽ(ʵ��Ϊ����ģʽ),WRAP_S��ˮƽ���ƣ����������ҪǶ������ζ�����ǲ�ϣ��������������һ��ѡ����ƽ��
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE)); // S��T�е���x��y

	//��OpenGL����������m_LocalBuffer��ȡ��������
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer)) //GL_RGBA8������ʾָ��ÿ��ͨ����ʵ�ʱ���������ϣ��OpenGL��δ洢�������;��������û��׼�������ݿ����ȴ�һ����ָ�룬����ζֻ���Դ��Ϸ����˿ռ�
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer); //���m_LocalBufferȷʵ�����ݾ͵���stbi_image_free���ͷ��ڴ�
}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &m_RendererID));
}

void Texture::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot ));//ָ��һ�������,ʹ��ö��(enum)����
	GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
}

void Texture::Unibind()
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
