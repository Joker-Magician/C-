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

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

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
	window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
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
			-50.0f, -50.0f, 0.0f, 0.0f, // 0 
			 50.0f, -50.0f, 1.0f, 0.0f, // 1
			 50.0f,  50.0f, 1.0f, 1.0f, // 2
			-50.0f,  50.0f, 0.0f, 1.0f  // 3
		};

		unsigned int indices[] = { //构建索引缓冲区
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)); 

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float)); //在抽象后，这里就自动绑定了
		
		VertexBufferLayout layout;
		layout.Push<float>(2);		
		layout.Push<float>(2); //推入新增的浮点数
		va.AddBuffer(vb, layout);

		glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f); /*模型视图投影矩阵*/
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));; 
		//glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));; // 创建一个平移矩阵,将所有东西向左移动100单位(类似与相机拍摄物品，注意相对性)

		//glm::vec4 vp(100.0f, 100.0f, 0.0f, 1.0f);
		//glm::vec4 result = proj * vp; // 在CPU端模拟的乘法

		IndexBuffer ib(indices, 6);

		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

		Texture texture("res/textures/Clogo.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0); // 蒋纹理绑定到插槽0

		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();

		Renderer renderer;
		
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		glm::vec3 translationA(200, 200, 0);
		glm::vec3 translationB(400, 200, 0);

		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		float r = 0.0f;
		float increment = 0.05f;
		/* Loop until the user close the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			renderer.Clear();

			ImGui_ImplGlfwGL3_NewFrame(); //开启一个新的GL3帧,要确保把它放在imgui代码之间
			
			{
				glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
				glm::mat4 mvp = proj * view * model;
				shader.Bind();
				shader.SetUniformMat4f("u_MVP", mvp);
			
				renderer.Draw(va, ib, shader);
			}

			{
				glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
				glm::mat4 mvp = proj * view * model;
				shader.Bind();
				shader.SetUniformMat4f("u_MVP", mvp);

				renderer.Draw(va, ib, shader);
			}

			//shader.Bind();
			////shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f); // 因为我们在渲染一个纹理，不会用这个颜色或其他什么来吸引它，所以可以停止设置它
			//shader.SetUniformMat4f("u_MVP", mvp);

			//shader.SetUniformMat4f("u_MVP", mvp);
			//renderer.Draw(va, ib, shader);//渲染第二次

			if (r > 1.0f)
				increment = -0.05f;
			else if (r < 0.0f)
				increment = 0.05f;

			r += increment;

			{ //创建一个简单的窗口
				ImGui::SliderFloat3("Translation A", &translationA.x, 0.0f, 960.0f);  
				ImGui::SliderFloat3("Translation B", &translationB.x, 0.0f, 960.0f);  
				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			}

			ImGui::Render();

			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}

//投影矩阵(projection)，本质上是一种数学，将空间中的所有3D点转换成2D窗口中的东西
//标准空间意味着在每个xyz轴上都有一个-1和1之间的坐标系统

//本次使用了InGui，是一个GUIA(图形界面接口)库