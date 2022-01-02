#include <stdio.h>
#include <stdlib.h>
#include "includes/main.h"

#include "includes/gl_objs.h"
#include "includes/objects/structures/map.h"
#include "includes/objects/shapes/plane.h"


#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FREE_CAM

void error_callback(int code, char* description)
{
    printf("%s", description);
}
void renderLoop(GLFWwindow* window)
{
    InputState state = {
        {-10.0f, 20.0f, 10.0f}, 
        {0.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        1.5f, 
        640.0f, 
        360.0f, 
        0.0f, 
        0.0f, 
        45.0f,
        1
    };


    

    glmc_vec3_sub(state.camDir, state.camPos, state.camDir);
    glmc_vec3_normalize(state.camDir);

    state.pitch = glm_deg(asin(state.camDir[1]));
    state.yaw = glm_deg(asin(state.camDir[2]/cos(glm_rad(state.pitch))));

    glfwSetWindowUserPointer(window, (void*)&state);


    mat4 v;
    glmc_mat4_identity(v);

    mat4 p;
    glmc_mat4_identity(p);
    

    float current_time, delta_time, last_frame;

    char map_data[2][2] = {{1, 1}, {0, 1}};

    Map game_map = {
        .w = 2,
        .h = 2
    };
    map_init(&game_map, &map_data);


    while(!glfwWindowShouldClose(window))
    {
        

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

        glmc_look(state.camPos, state.camDir, state.camUp, v);

        glmc_perspective(glm_rad(state.fov), (float)WINDOW_WIDTH/(float)WINDOW_HEIGHT, 0.1f, 100.0f, p);

        
        map_render(&game_map, &v, &p);


        current_time = glfwGetTime();
        
        glfwSwapBuffers(window);
        glfwPollEvents();

        
        
        delta_time = current_time - last_frame;
        last_frame = current_time;
        process_input(window, &state, delta_time);
    }
    
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{ 
    #ifdef FREE_CAM

    InputState *state = (InputState*)glfwGetWindowUserPointer(window);
    if(state->firstMouse)
    {
        state->lastX = xpos;
        state->lastY = ypos;
        state->firstMouse = 0;
    }

    float xoffset = xpos - state->lastX;
    float yoffset = state->lastY - ypos;

    state->lastX = xpos;
    state->lastY = ypos;

    const float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    state->yaw += xoffset;
    state->pitch += yoffset;

    if(state->pitch > 89.0f)
        state->pitch = 89.0f;
    if(state->pitch < -89.0f)
        state->pitch = -89.0f;

    state->camDir[0] = cos(glm_rad(state->yaw)) * cos(glm_rad(state->pitch));
    state->camDir[1] = sin(glm_rad(state->pitch));
    state->camDir[2] = sin(glm_rad(state->yaw)) * cos(glm_rad(state->pitch));  

    #else

    #endif 
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    InputState *state = glfwGetWindowUserPointer(window);

    state->fov += (float)yoffset;
    if(state->fov < 1.0f) state->fov = 1.0f;
    if(state->fov > 45.0f) state->fov = 45.0f;
}
void process_input(GLFWwindow *window, InputState *state, float time_delta)
{   
    vec3 inv_dir, right, inv_right;
    float speed = state->camSpeed * time_delta;
    glmc_vec3_negate_to(state->camDir, inv_dir);

    glmc_vec3_cross(state->camDir, state->camUp, right);
    glmc_vec3_normalize(right);
    glmc_vec3_negate_to(right, inv_right);

    #ifdef FREE_CAM

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) 
        glmc_vec3_muladds(state->camDir, speed, state->camPos);
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        glmc_vec3_muladds(inv_dir, speed, state->camPos);
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        glmc_vec3_muladds(inv_right, speed, state->camPos);
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        glmc_vec3_muladds(right, speed, state->camPos);
    // printf("%f %f\n", state->pitch, state->yaw);
    #else

    #endif
}
void APIENTRY opengl_error_callback(GLenum source, GLenum type, GLint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
    printf("%s", message);
}

int initGL()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        return 0;
    }
    int flags; 
    glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback((GLDEBUGPROC) opengl_error_callback, (const void*)0);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(1);
}
int initGLFW()
{
    glfwSetErrorCallback((GLFWerrorfun) error_callback);
    if(!glfwInit())
    {
        printf("Failed to initialize GLFW");
        return 0;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
}
int main()
{
    if(!initGLFW()) return 0;
    
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "w", NULL, NULL);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback); 
    glfwSetScrollCallback(window, scroll_callback); 
    

    if(!initGL()) return 0;

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glEnable(GL_DEPTH_TEST);
    

    renderLoop(window);

    char c;
    scanf(&c);
    glfwTerminate();
    return 0;

}