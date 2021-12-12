#include <stdio.h>
#define GLFW_DLL
#include "glad/glad.h"
#include "GLFW/glfw3.h"


#include "basic.vs.h"
#include "basic.fs.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

typedef struct
{
    GLenum data_type;
    void *data;
    size_t data_size;
    unsigned int vao_index;
    GLenum usage;
    GLenum normalized;
    unsigned int vbo_id;
    int unit_size;
} VBO;
typedef struct 
{
    int vboc;
    VBO **vbos;
    int stride;
    int *offsets;
    unsigned int vao_id;
} VAO;
typedef struct 
{
    GLenum type;
    char **uniforms;
    int uniformc;
    char **source;
    unsigned int shader_id;
} Shader;
typedef struct 
{
    VAO *vao;
    int shaderc;
    Shader *shaders;
    unsigned int program_id;
} ShaderProgram;

void error_callback(int code, char* description)
{
    printf("%s", description);
}

// void initializeVBO(VBO *vbo)
// {
//     glGenBuffers(1, &(vbo->vbo_id));
//     glBindBuffer(GL_ARRAY_BUFFER, vbo->vbo_id);
//     glBufferData(GL_ARRAY_BUFFER, vbo->data_size, vbo->data, vbo->usage);
// }
void initializeVBO(unsigned int *vbo, size_t data_size, float* data)
{
    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, data_size, data, GL_STATIC_DRAW);
}


int compileShader(unsigned int *shader, const char **source, GLenum type)
{
    *shader = glCreateShader(type);
    glShaderSource(*shader, 1, source, NULL);
    glCompileShader(*shader);

    int success;
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
    return success;
}

void checkShaderCompile(unsigned int shader)
{
    int s = 512;
    char infoLog[s];
    glGetShaderInfoLog(shader, s, NULL, infoLog);
    printf("Shader compilation error: %s", infoLog);
}
int compileShaderProgram(unsigned int *program, int shaderc, unsigned int **shaders)
{
    *program = glCreateProgram();
    for(unsigned int i = 0; i < shaderc; i++)
    {
       
    }
    glAttachShader(*program, *shaders[0]);
    glAttachShader(*program, *shaders[1]);
    glLinkProgram(*program);

    int success;
    glGetProgramiv(*program, GL_LINK_STATUS, &success);
    return success;
}
void checkShaderPrCompile(unsigned int program)
{
    int s = 512;
    char infoLog[s];
    glGetProgramInfoLog(program, s, NULL, infoLog);
    printf("Shader program compilation error: %s", infoLog);
}
void init()
{
    // float vertices[] = {
    //     -1.0f, 1.0f, 0.0f,
    //     1.0f, 1.0f, 0.0f,
    //     -1.0f, -1.0f,0.0f,
    //     1.0f, 1.0f, 0.0f,
    //     1.0f, -1.0f, 0.0f,
    //     -1.0f, -1.0f, 0.0f
    // };

    // VBO basic_vbo_verts = {
    //     GL_GLOAT, 
    //     vertices,
    //     sizeof(vertices) * sizeof(float),
    //     0,
    //     GL_STATIC_DRAW,
    //     GL_FALSE,
    //     0,
    //     3
    // };

    // VAO basic_vao = {
    //     1,
    //     {&basic_vbo_verts},
    //     0,
    //     {0},
    //     0
    // };

    // Shader basicVertexShader = {
    //     GL_VERTEX_SHADER,
    //     NULL,
    //     0,
    //     &basicvs,
    //     0
    // };
    // Shader basicFragmentShader = {
    //     GL_FRAGMENT_SHADER,
    //     NULL,
    //     0,
    //     &basicfs,
    //     0
    // };

    // ShaderProgram = {
    //     &basic_vao,
    //     2,
    //     {&basicVertexShader, &basicFragmentShader},
    //     0
    // };










    unsigned int vertexShaderBasic;
    unsigned int fragmentShaderBasic;
    unsigned int *shaders[] = {
        &vertexShaderBasic,
        &fragmentShaderBasic
    };
    unsigned int shaderProgramBasic;

    unsigned int basicVBO;
    unsigned int basicVAO;

    

    
    // if(!compileShader(&vertexShaderBasic, &basicvs, GL_VERTEX_SHADER)) 
    // checkShaderCompile(vertexShaderBasic);
    // if(!compileShader(&fragmentShaderBasic, &basicfs, GL_FRAGMENT_SHADER))
    // checkShaderCompile(fragmentShaderBasic);

    // if(!compileShaderProgram(&shaderProgramBasic, 2, shaders))
    // checkShaderPrCompile(shaderProgramBasic);
    


    // glGenVertexArrays(1, &basicVAO);
    // glBindVertexArray(basicVAO);
    // initializeVBO(&basicVBO, 18 * sizeof(float), vertices);
    
    
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // glEnableVertexAttribArray(0);

    // glUseProgram(shaderProgramBasic);
    
}
void render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
    
}

int main()
{
    printf("%i", sizeof(GL_FLOAT));
    glfwSetErrorCallback((GLFWerrorfun) error_callback);
    if(!glfwInit())
    {
        printf("Failed to initialize GLFW");
        return 0;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "w", NULL, NULL);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        return 0;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    init();
    

    while(!glfwWindowShouldClose(window))
    {
        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
        process_input(window);
    }


    char c;
    scanf(&c);
    glfwTerminate();
    return 0;

}