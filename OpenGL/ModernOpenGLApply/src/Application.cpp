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

    unsigned int buffer;
    glGenBuffers(1,&buffer);//1��ʾֻ��Ҫһ�����壬�ڶ���������Ҫһ���޷�������ָ��(��Ϊ�����������void,���������������ɵĻ�����id,������Ҫ�����ṩһ������ָ��,Ȼ������idд������������ڴ�,�����Ϊʲô��Ҫһ��ָ��)
/*������������һ��id,һ���������������������ھ�Ҫѡ���Ǹ�������������ѡ��(selecting)��OpenGL�г�Ϊ(binding)*/
    glBindBuffer(GL_ARRAY_BUFFER, buffer);//��һ��������Ŀ�꣬��������˵��ֻ��һ���ڴ滺��������������Ҫ��GL_ARRAY_BUFFER,Ҳ����˵��ֻ��һ������

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

/*���㻺����(Vertex Buffer),�������Ͼ���ȥ��vertex������ʣ���ֻ��һ����������һ���ڴ滺������һ���ڴ��ֽ�����,�������ı��ʣ�ֻ�Ǹ�������
������һ���������ֽڵ��ڴ棬���������Ļ�������ͬ��������һ���洢�ֽڵ��ڴ棬����ζ����ʵ�������Կ��ϣ������ǵ�VRAM(�Դ�)�У�Ҳ����Video RAM.
����Ҫ���������εĻ���˼·�ǣ� 
1.��Ҫ���������Կ���VRAM��
2.Ȼ����Ҫ����DrawCallָ�����һ������ָ���˼�ǣ��٣�����Դ�����һ�����ݣ���ȡ�������Ұ�����������Ļ�ϣ�ʵ���ϣ����ǻ���Ҫ�����Կ���ζ�ȡ�ͽ�����Щ���ݣ��Լ���ΰ����ŵ�������Ļ��*/
/*������Ҫ�����Կ���Ҫ��ʲô������ѡӴ���Կ���̣����ң��Ǿ�����ɫ��
��ɫ������һ���������Կ��ϵĳ�����һ�����ǿ��Ա�д�Ŀ������Կ������еĴ��룬���������Կ�����һ�ַǳ������ַǳ�ǿ��ķ�ʽ����*/

//����OpenGl��Ⱦ����ľ��ǣ�������һ�����ݣ����һ��Ƴ���

//��Ҫע����ǣ�OpenGL����Ĳ�������һ��״̬����Ҳ����˵���ǲ���Ҫ�������ɶ�������ƵĶ���
//��������Ҫ����������һϵ�е�״̬��Ȼ������˵һЩ���顣���磬���һ��Ƹ������Σ���������������صģ��ⲻ����˵���٣����һ��Ƹ������Ρ�֮��Ȼ��Ŵ���OpenGL��������������Ҫ�Ķ�����ʵ���ϣ����Ѿ�֪������������������Ҫ�Ķ�������Ϊ����״̬��һ����
//���仰˵����������ѡ��������������������ɫ����Ȼ����һ��Ƹ������Σ�Ȼ�������ѡ��Ļ���������ɫ����������ʲô���������Σ�����������ȵ�
//�Ǿ���OpenGL��ԭ������һ��״̬��