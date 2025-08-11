#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>

static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{ /* 在该函数中，我们选哟白那些编译这两个着色器所需要的代码，现在这种情况下，我们需要做的事传入着色器实际的源码作为这些实际的字符串，所以我们需要提供一个顶点着色器和一个片段着色器 */
	unsigned int program = glCreateProgram();//该函数会返回一个无符号整数
}

int mian(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	float positions[6] = {
		-0.5f, -0.5f,
		 0.5f,  0.5f,
		 0.5f,  0.5f,
	};


	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glDrawArrays(GL_TRIANGLES, 0, 3);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate;
	return 0;
}