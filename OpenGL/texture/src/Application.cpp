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
			-0.5f, -0.5f, 0.0f, 0.0f, // 0 ,�������һ��vec2(0,0),Ϊÿ����������������������������ǵ���������
			 0.5f, -0.5f, 1.0f, 0.0f, // 1
			 0.5f,  0.5f, 1.0f, 1.0f, // 2
			-0.5f,  0.5f, 0.0f, 1.0f  // 3
		};

		unsigned int indices[] = { //��������������
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)); //���(Blend)��ʽ,�ڶ���������ʾ����λ��alpha(͸����)����
//��ȾһЩ��͸����alpha�����ʱ�����ʹ�û�ϣ����ֻ�Ǿ�����������ν������ɫ��Ŀ�껺�������Լ����ڵ���ɫ�������

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float)); //�ڳ����������Զ�����
		
		VertexBufferLayout layout;
		layout.Push<float>(2);		
		layout.Push<float>(2); //���������ĸ�����
		va.AddBuffer(vb, layout);

		glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f); // ��������һ������������һ��4��3���ݺ�ȣ�һ�������������Ͼ��ǰ����е�����ӳ�䵽2Dƽ���ϵ�һ�ַ���

		IndexBuffer ib(indices, 6);

		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
		shader.SetUniformMat4f("u_MVP", proj);

		Texture texture("res/textures/Clogo.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0); // ������󶨵����0

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

//Ϊ�˴���pngͼƬ��������⣬��ȡ���ݲ����䷢�͵�GPU������ʹ��stb_image��

/* ���ƻ�ϵķ�ʽ������ 
1.glEnable(GL_BLEND) - glDisable(GL_BLEND) �������ֹ
2.glBlendFunc(src, dest)
	src = ��μ���src��RGBA���ӵķ�ʽ(Ĭ��ֵΪGL_ONE)
	dest = ��μ���dest��RGBA���ӵķ�ʽ(Ĭ��ֵΪGL_ZERO)	
3.glBlendEquation(mode)
	mode = ����������src��dest��ɫ(Ĭ��������(GL_FUNC_ADD)) //����src����ɫ*1�����src��ɫ,�ټ���dest����ɫ*0����dest����ɫ
	��Ĭ������£�1 + 0 = 1������ζ��ʹ��srcֵ(���ﲻ��ָsrc��alpha�������е���ɫͨ��������src��ʲô�����Ǹ�src��ɫ����dest)
�����������õĻ�Ϻ�����
	src = GL_SRC_ALPHA
	dest = GL_ONE_MINUS_SRC_ALPHA
�������ȫ͸��ʱ����src alpha=0;dest��Ҫ��dest = 1 - 0 = 1
��Ϊalphaͨ��Ϊ0˵������ȫ͸���ģ����ǲ�Ӧ��дһ������ֻ��ʹ��Ŀ�껺���������غ�����κ�ֵ
*/

//Ϊ�˴���ͼ�δ����ݺ��ת����������ʹ������ѵ���ѧ��glm,glm��һ��ֻ����ͷ�ļ��Ŀ⣬����ζ��û��cpp�ļ��������ǲ���Ҫ��������
//�����ʹ��ͶӰ����ķ�����������൱�ڽ�3Dת��Ϊ2Dƽ���ϣ�����Ҳ���������