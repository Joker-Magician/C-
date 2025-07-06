#include <GL/glew.h>    //ע���ڰ����κ�����OpenGL��ص�ͷ�ļ�֮ǰ��Ҫ����glew.h����Ȼ�ᷢ��һЩ������ͻ
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

    /*if (glewInit() != GLEW_OK) �������ʼ���Ǵ���ģ���Ҫ��ȷ�ĳ�ʼ����Ҫ��һ����ȾOpenGL����Ч�����ĺ���
        std::cout << "Error!" << std::endl;
        */

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

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



// warning LNK4098: Ĭ�Ͽ⡰MSVCRT�����������ʹ�ó�ͻ����ʹ�� /NODEFAULTLIB:library
//���ָô������ھ�̬�����ϳ����˴�����Ϊ������Ҫ���Ƕ�̬���ӣ���������ʹ�õ��Ǿ�̬����(���κ�����¶��Ƽ�ʹ�þ�̬����)��������Ҫ��Ԥ����������ǰ����GLEW_STATIC