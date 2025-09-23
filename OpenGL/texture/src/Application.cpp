#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;
	{
		float positions[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, // 0 ,添加了另一个vec2(0,0),为每个顶点添加两个浮点数，这是我们的纹理坐标
			 0.5f, -0.5f, 1.0f, 0.0f, // 1
			 0.5f,  0.5f, 1.0f, 1.0f, // 2
			-0.5f,  0.5f, 0.0f, 1.0f  // 3
		};

		unsigned int indices[] = { //构建索引缓冲区
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)); //混合(Blend)方式,第二个参数表示了如何混合alpha(透明度)像素
//渲染一些有透明度alpha概念的时候可以使用混合，混合只是决定了我们如何将输出颜色与目标缓冲区中以及存在的颜色结合起来

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float)); //在抽象后，这里就自动绑定了
		
		VertexBufferLayout layout;
		layout.Push<float>(2);		
		layout.Push<float>(2); //推入新增的浮点数
		va.AddBuffer(vb, layout);

		glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f); // 这里会产生一个正交矩阵中一个4：3的纵横比，一个正交矩阵本质上就是把所有的坐标映射到2D平面上的一种方法

		IndexBuffer ib(indices, 6);

		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
		shader.SetUniformMat4f("u_MVP", proj);

		Texture texture("res/textures/Clogo.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0); // 蒋纹理绑定到插槽0

		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();

		Renderer renderer;
		
		float r = 0.0f;
		float increment = 0.05f;
		/* Loop until the user close the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			renderer.Clear();

			shader.Bind();
			shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

			renderer.Draw(va, ib, shader);

			if (r > 1.0f)
				increment = -0.05f;
			else if (r < 0.0f)
				increment = 0.05f;

			r += increment;

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}

//为了处理png图片解码等问题，获取数据并将其发送到GPU，这里使用stb_image库

/* 控制混合的方式有三种 
1.glEnable(GL_BLEND) - glDisable(GL_BLEND) 启用与禁止
2.glBlendFunc(src, dest)
	src = 如何计算src的RGBA因子的方式(默认值为GL_ONE)
	dest = 如何计算dest的RGBA因子的方式(默认值为GL_ZERO)	
3.glBlendEquation(mode)
	mode = 我们如何组合src和dest颜色(默认是增加(GL_FUNC_ADD)) //如用src的颜色*1这就是src颜色,再加上dest的颜色*0就是dest的颜色
	即默认情况下，1 + 0 = 1，这意味着使用src值(这里不单指src的alpha而是所有的颜色通道，无论src是什么就用那个src颜色覆盖dest)
我们这里设置的混合函数是
	src = GL_SRC_ALPHA
	dest = GL_ONE_MINUS_SRC_ALPHA
如果在完全透明时，即src alpha=0;dest被要求：dest = 1 - 0 = 1
因为alpha通道为0说明是完全透明的，我们不应该写一个像素只需使用目标缓冲区中像素后面的任何值
*/

//为了处理图形窗口纵横比转换问题这里使用了免费的数学库glm,glm是一个只包含头文件的库，这意味着没有cpp文件，即我们不需要编译它们
//这里会使用投影矩阵的方法来解决，相当于将3D转换为2D平面上，这里也是这个道理