#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();//这只返回一个指向我们数据开始的指针
  //const char* src = &source[0];//这样也是可以的，查找字符串的第一个字符，然后返回它的内存地址
	glShaderSource(id, 1, &src, nullptr);//这里看起来需要两个指针，它实际上只需要一个指针，这是一个双精度指针，它基本上就是需要一个指针指向实际的指针
	glCompileShader(id);

	// TODO: Error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);//i指定了一个整数，v指定了它需要一个矢量
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);//首先知道错误信息的长度
		//char message[length];我们实际上可以在这里构造一种堆栈分配的字符,但在C++中是不允许这样分配的，所以可以使用下面的方法来建立在堆栈上
		char* message = (char*)alloca(length * sizeof(char));//alloca是一个C函数，它允许你在堆栈上动态分配
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" <<(type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << 
			std::endl;//判断哪种着色器出了问题
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	
	return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{ /* 在该函数中，我们选则那些编译这两个着色器所需要的代码，现在这种情况下，我们需要做的事传入着色器实际的源码作为这些实际的字符串，所以我们需要提供一个顶点着色器和一个片段着色器 */
	unsigned int program = glCreateProgram();//该函数会返回一个无符号整数,之所以不使用GL的内置类型(如GLint)，因为在更倾向于处理多种图形接口时，可能会需要到处包含GL,这需要
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);//顶点着色器
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);//片段着色器
 
	// 上面我们有两个文件(vs和fs),所以选哟把它们链接到一个程序中，因此才可以同时使用它们
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);//可以删掉我们的着色器，因为它们已经被链接到一个程序中，所以我们可以删掉这些中间文件，如果在使用C++,我们得到一些obj中间文件，当我们在使用微软编译器时，它就是对象文件，最后我们可以删掉这些文件，因为我们实际上已经得到了一个实际的程序，现在它已经存储在程序中了

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
		"	color = vec4(1.0, 0.0, 0.0, 1.0);\n" //设置颜色为红色，颜色和图形编程是传统的只是和1之间的浮点数，在一种非HDR环境中，基本上0就是黑色，1就是白色，这种就是RGBA
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