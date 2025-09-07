#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

void main()
{
	gl_Position = position;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;//����һЩ����Լ��,�������κ���u_��ͷ�ı�������һ��ͳһ����

void main()
{
	//color = vec4(0.2, 0.3, 0.8, 1.0); 
	color = u_Color; //ʹ��u_Color���滻�������ǵ�ʵ�ʾ��ε�ÿһ����ÿһƬ�ε���ɫ�����ó����ͳһ������ֵ
};