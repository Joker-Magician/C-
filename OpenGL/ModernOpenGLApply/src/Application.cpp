#include <GL/glew.h>    //注意在包含任何其他OpenGL相关的头文件之前就要包含glew.h，不然会发生一些命名冲突
#include <GLFW/glfw3.h>

#include <iostream>

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

    /*if (glewInit() != GLEW_OK) 在这里初始化是错误的，想要正确的初始化需要有一个渲染OpenGL的有效上下文后面
        std::cout << "Error!" << std::endl;
        */

        /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    unsigned int buffer;
    glGenBuffers(1,&buffer);//1表示只需要一个缓冲，第二个参数需要一个无符号整型指针(因为这个函数返回void,即函数不返回生成的缓冲区id,我们需要给它提供一个整数指针,然后函数把id写入这个整数的内存,这就是为什么需要一个指针)
/*现在我们有了一个id,一旦创建缓冲区后，我们现在就要选择那个缓冲区，并且选择(selecting)在OpenGL中称为(binding)*/
    glBindBuffer(GL_ARRAY_BUFFER, buffer);//第一个参数是目标，对我们来说这只是一个内存缓冲区，所以我们要用GL_ARRAY_BUFFER,也就是说这只是一个数组

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f( 0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}



// warning LNK4098: 默认库“MSVCRT”与其他库的使用冲突；请使用 /NODEFAULTLIB:library
//出现该错误是在静态链接上出现了错误，因为这里需要的是动态链接，本代码中使用的是静态链接(在任何情况下都推荐使用静态链接)，所以需要在预处理器中提前定义GLEW_STATIC

/*顶点缓冲区(Vertex Buffer),它基本上就是去掉vertex这个单词，它只是一个缓冲区，一个内存缓冲区，一个内存字节数组,那是它的本质，只是个缓冲区
它就是一块用来存字节的内存，它与存数组的缓冲区不同在于它是一个存储字节的内存，这意味着它实际上在显卡上，在我们的VRAM(显存)中，也就是Video RAM.
所以要绘制三角形的基本思路是： 
1.我要把它放如显卡的VRAM中
2.然后还需要发出DrawCall指令，这是一个绘制指令，意思是，嘿，你的显存中有一堆数据，读取它，并且把它绘制在屏幕上，实际上，我们还需要告诉显卡如何读取和解释这些数据，以及如何把它放到我们屏幕上*/
/*我们需要告诉显卡它要做什么，所以选哟对显卡编程，并且，那就是着色器
着色器，是一个运行在显卡上的程序，是一堆我们可以编写的可以在显卡上运行的代码，它可以在显卡上以一种非常特殊又非常强大的方式运行*/

//基本OpenGl渲染代码的就是，嘿这有一堆数据，给我绘制出来

//需要注意的是，OpenGL具体的操作就是一个状态机，也就是说你们不需要把它看成对象或类似的东西
//你们所需要做的是设置一系列的状态，然后当你们说一些事情。比如，给我绘制个三角形，那是与上下文相关的，这不是在说“嘿，给我绘制个三角形”之后，然后才传给OpenGL绘制三角形所需要的东西，实际上，它已经知道它绘制三角形所需要的东西，因为那是状态的一部分
//换句话说，我想让你选择这个缓冲区，用这个着色器，然后给我绘制个三角形，然后根据你选择的缓冲区和着色器决定绘制什么样的三角形，绘制在哪里等等
//那就是OpenGL的原理，它是一个状态机