#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "GLFW inid failed!" << std::endl;
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(640, 480, "BattleCity", NULL, NULL);
    if (!pWindow)
    {
        std::cout << "GLFW create window failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);
    
    if (!gladLoadGL()){
        std::cout << "Can't load GLAD!" << std::endl;
        return -1;
    }
    
    std::cout << "Render " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGl version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;
    
    glClearColor(1, 1, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
