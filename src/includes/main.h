#ifndef _MAIN_H_
#define _MAIN_H_
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "cglm/call.h"

typedef struct
{
    vec3 camPos;
    vec3 camDir;
    vec3 camUp;
    float camSpeed, lastX, lastY, yaw, pitch, fov;
    int firstMouse;
} InputState;

void process_input(GLFWwindow *window, InputState *state, float time_delta);
int initGL();
int initGLFW();
void opengl_error_callback(GLenum source, GLenum type, GLint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);


#endif