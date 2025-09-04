#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>//字符串流

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};//结构体可以返回两个变量

static ShaderProgramSource ParseShader(const std::string& filepath) // 用于读取.shader文件，并将其中的片段和顶点着色器分割为两段字符串
{
	std::ifstream stream(filepath);//输入文件流

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];//创建两个字符串流
	ShaderType type = ShaderType::NONE;//存储当前读入的着色器类型
	while (getline(stream, line))//一行一行去浏览文件,这里用一个叫line的流
	{ //查看数据行或查找实际的行是否包含我们的着色器在这里自定义句法结构的标记，并且如果不等于std::string::npos，基本上是一个无效字符串位置，因为find会返回给我们实际的字符串位置
		if (line.find("shader") != std::string::npos)//不管它是否找到字符串，它实际上只是返回给我们它的位置，如果结果是正的说明没有，否则则是找到了相应的着色器
		{
			if (line.find("vertex") != std::string::npos)//如果找到了vertex顶点着色器，则将模式设置为顶点着色器
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else //如果它是其他的代码行，我们就需要把它添加到顶点或片段的着色器源码中
		{ //对于字符串流，基本上可以把数据行推到它里面去
			ss[(int)type] << line << '\n';
		}
	}
	return { ss[0].str(), ss[1].str() };
}

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

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)//定义一个静态函数，不希望它链接到其他翻译单元或C++文件
{ //向OpenGL提供我们实际的着色器源代码、我们的着色器文本,我们想让OpenGL编译哪个程序，将这两个链接到一个独立的着色器程序，然后给我们一些那个着色器返回的唯一标识符,这样我们就能绑定着色器并使用它
	unsigned int program = glCreateProgram();//该函数会返回一个无符号整数,之所以不使用GL的内置类型(如GLint)，因为在更倾向于处理多种图形接口时，可能会需要到处包含GL,这需要
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);//顶点着色器
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);//片段着色器
 
	// 上面我们有两个 文件(vs和fs),所以选哟把它们链接到一个程序中，因此才可以同时使用它们
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

	//std::string vertexShader =
	//	"#version 330 core\n"
	//	"\n"
	//	"layout(location = 0) in vec4 position;\n"
	//	"\n"
	//	"void main()\n"
	//	"{\n"
	//	"	gl_Position = position;\n"
	//	"}\n";

	//std::string fragmentShader =
	//	"#version 330 core\n"
	//	"\n"
	//	"layout(location = 0) out vec4 color;\n"
	//	"\n"
	//	"void main()\n"
	//	"{\n"
	//	"	color = vec4(1.0, 0.0, 0.0, 1.0);\n" //设置颜色为红色，颜色和图形编程是传统的只是和1之间的浮点数，在一种非HDR环境中，基本上0就是黑色，1就是白色，这种就是RGBA
	//	"}\n";

	ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
	unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
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

	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}