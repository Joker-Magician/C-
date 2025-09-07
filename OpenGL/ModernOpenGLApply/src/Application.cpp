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

    float positions[6] = { //这只是位置而不是顶点，所以叫做position
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };


    unsigned int buffer;
    glGenBuffers(1,&buffer);//1表示只需要一个缓冲，第二个参数需要一个无符号整型指针(因为这个函数返回void,即函数不返回生成的缓冲区id,我们需要给它提供一个整数指针,然后函数把id写入这个整数的内存,这就是为什么需要一个指针)
/*现在我们有了一个id,一旦创建缓冲区后，我们现在就要选择那个缓冲区，并且选择(selecting)在OpenGL中称为(binding)*/
    glBindBuffer(GL_ARRAY_BUFFER, buffer);//第一个参数是目标，对我们来说这只是一个内存缓冲区，所以我们要用GL_ARRAY_BUFFER,也就是说这只是一个数组
/*下一步就是将数据放入这个缓冲区，上面没有具体说明缓冲区的大小，只是创建了一个缓冲区，然后绑定它，则下一步是指定数据*/
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float),positions,GL_STATIC_DRAW);//再次指定目标GL_ARRAY_BUFFER,第二个参数大小是指我们希望这个缓冲区有多大，或者我们的数据有多大
/*注意此时我们还没有准备好绘制，因为我们还没有告诉OpenGL如何绘制(即只告诉了OpenGL的数据内容，但它并不理解要做什么，大概就像顶点的链接顺序一样)*/

//要启用或禁用通用的顶点属性组需要调用glEnableVertexAttribArray(),不然会出现黑屏，OpenGL只是一个状态机，它不会检查它是否被启用;这个函数仅需要传入索引量
//只要你的实际缓冲区是绑定的，你可以在任何地方去调用它，这里一般习惯在指针前去做这个
    glEnableVertexAttribArray(0);
//glVertexAttribPointer(GLuint index,GLint size, GLenum type,GLsizei stride,const GLvoid* pointer)需要的参数index(索引),size(大小),type(类型),normalized(标准化),stride(步幅),pointer(指针)，其中index为寻找你属性(attributes)的索引是什么
//size指的是每个通用顶点属性的组件数，它只能是1,2,3,4,所以这个size和字节没有任何关系或者和它们实际占用多少内存也没关系，它只是计数
//normalized(标准化)，这个不需要特别担心，如果我们处理的是浮点数，因为它们已经被规范化了，但这基本上是用来，假设我们需要指定一个字节在0到255之间，因为这是我们颜色的值，他需要被规范到0到1之间，在我们的实际着色器中作为一个浮点数(这不是我们可以在CPU上做的，我们可以让OpenGL来做)，所以我们把这个设为false,或是指定的GL_FALSE
//stride指针，stride就是连续通用顶点属性之间的字节偏移量，基本上stride就是每个顶点之间的字节数
//pointer,是第一个组件的一个偏移量，pointer是指向实际属性的指针
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//因为这个仅有一个属性，所以不需要偏移到下一个属性所以最后pointer为0(记住指针也仅是一个数字)
     

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES,0,3);//这是一个没有索引缓冲区时可以使用的方法
    //绘制三角形(TRIANGLES,triangles),从顶点列表的起始位置开始，所以第二个参数写0;最后一个参数count，也就是要渲染的索引的数量

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

/*顶点属性与内存布局*/
/*顶点属性，基本上就是OpenGL管道的工作方式
OpenGL管道的工作原理是我们为我们的显卡提供数据，我们在显卡上存储一些内存，它包含了我们想要绘制的所有数据，然后我们使用着色器，是一个在显卡上执行的程序来读取数据并完全显示在屏幕上，
基本上当我们绘制几何图形时就是使用一个叫顶点缓冲区的东西，这基本上时存储在显卡上的内存缓冲区，所以，当对着色器编程时，实际上时从读取顶点缓冲区开始的，它需要知道缓冲区的布局，这个缓冲区实际上包含的只是一堆浮点数，它们指定了每个顶点的位置，
所以我们需要告诉OpenGL内存中有什么，又是如何布局的(和C++中一样，如果 我写一个浮点数，然后给它赋值，我知道内存中有一个浮点数，因为我告诉C++这是一个浮点数，如果我将它转换为一个整数或者说一个整形指针，如果我们取浮点数的内存地址，并将其转换为整形指针，然后解引用，我将得到完全不同的东西，因为它对这块内存做了不同的解释)
所以我们需要告诉OpenGL前12个字节是三个浮点数，并且每个浮点数三个字节(这就是我的观点)，之后八个紫萼及是我的纹理坐标(texture coordinates)
而VertexAttribPointer()可以为我们做到这一切*/

/*顶点(Vertex)与位置(position)无关，顶点就是几何图形上的一个点，大多数人在视觉上对它们的明显印象是通过它的位置，一个顶点可以不仅仅包含一个位置，当说顶点时一般指的是构成顶点的所有数据，
这也可能包括位置、纹理坐标、法线(normals)、颜色(colors)、次法线(by normals)、切线(tangents)等等*/

//推荐一个基本上最好的查看OpenGL的网站：docs.gl