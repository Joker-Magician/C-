#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();//��ֻ����һ��ָ���������ݿ�ʼ��ָ��
  //const char* src = &source[0];//����Ҳ�ǿ��Եģ������ַ����ĵ�һ���ַ���Ȼ�󷵻������ڴ��ַ
	glShaderSource(id, 1, &src, nullptr);//���￴������Ҫ����ָ�룬��ʵ����ֻ��Ҫһ��ָ�룬����һ��˫����ָ�룬�������Ͼ�����Ҫһ��ָ��ָ��ʵ�ʵ�ָ��
	glCompileShader(id);

	// TODO: Error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);//iָ����һ��������vָ��������Ҫһ��ʸ��
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);//����֪��������Ϣ�ĳ���
		//char message[length];����ʵ���Ͽ��������ﹹ��һ�ֶ�ջ������ַ�,����C++���ǲ�������������ģ����Կ���ʹ������ķ����������ڶ�ջ��
		char* message = (char*)alloca(length * sizeof(char));//alloca��һ��C���������������ڶ�ջ�϶�̬����
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" <<(type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << 
			std::endl;//�ж�������ɫ����������
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	
	return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{ /* �ڸú����У�����ѡ����Щ������������ɫ������Ҫ�Ĵ��룬������������£�������Ҫ�����´�����ɫ��ʵ�ʵ�Դ����Ϊ��Щʵ�ʵ��ַ���������������Ҫ�ṩһ��������ɫ����һ��Ƭ����ɫ�� */
	unsigned int program = glCreateProgram();//�ú����᷵��һ���޷�������,֮���Բ�ʹ��GL����������(��GLint)����Ϊ�ڸ������ڴ������ͼ�νӿ�ʱ�����ܻ���Ҫ��������GL,����Ҫ
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);//������ɫ��
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);//Ƭ����ɫ��
 
	// ���������������ļ�(vs��fs),����ѡӴ���������ӵ�һ�������У���˲ſ���ͬʱʹ������
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);//����ɾ�����ǵ���ɫ������Ϊ�����Ѿ������ӵ�һ�������У��������ǿ���ɾ����Щ�м��ļ��������ʹ��C++,���ǵõ�һЩobj�м��ļ�����������ʹ��΢�������ʱ�������Ƕ����ļ���������ǿ���ɾ����Щ�ļ�����Ϊ����ʵ�����Ѿ��õ���һ��ʵ�ʵĳ����������Ѿ��洢�ڳ�������

	return program;
}

int main(void)
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
		 0.5f, -0.5f,
	};


	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0, 0.0, 0.0, 1.0);\n" //������ɫΪ��ɫ����ɫ��ͼ�α���Ǵ�ͳ��ֻ�Ǻ�1֮��ĸ���������һ�ַ�HDR�����У�������0���Ǻ�ɫ��1���ǰ�ɫ�����־���RGBA
		"}\n";

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	/* Loop until the user close the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteShader(shader);

	glfwTerminate();
	return 0;
}