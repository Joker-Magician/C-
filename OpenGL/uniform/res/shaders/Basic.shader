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

uniform vec4 u_Color;//这有一些命名约定,基本上任何以u_开头的变量都是一个统一变量

void main()
{
	//color = vec4(0.2, 0.3, 0.8, 1.0); 
	color = u_Color; //使用u_Color来替换，把我们的实际矩形的每一像素每一片段的颜色都设置成这个统一变量的值
};