#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>

static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{ /* �ڸú����У�����ѡӴ����Щ������������ɫ������Ҫ�Ĵ��룬������������£�������Ҫ�����´�����ɫ��ʵ�ʵ�Դ����Ϊ��Щʵ�ʵ��ַ���������������Ҫ�ṩһ��������ɫ����һ��Ƭ����ɫ�� */
	unsigned int program = glCreateProgram();//�ú����᷵��һ���޷�������
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