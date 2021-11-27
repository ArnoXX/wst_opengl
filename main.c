#include <stdio.h>
#define GLFW_DLL
#include "GLFW/glfw3.h"
#include "glad/glad.h"

int main()
{
    if(!glfwInit())
    {
        printf("Failed");
        return 0;
    }
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(1280, 720, "w", NULL, NULL);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }


    char c;
    scanf(&c);
    glfwTerminate();
    return 0;

}