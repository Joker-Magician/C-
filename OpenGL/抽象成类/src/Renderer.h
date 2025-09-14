#pragma once

#include<GL/glew.h>

#define ASSERT(x) if (!(x)) __debugbreak(); 
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__,__LINE__ ))

void GLClearError();//取消静态，让它成为一个实际的声明而不是定义
bool GLLogCall(const char* function, const char* file, int line);