#include <stdio.h>
#include <stdlib.h>
#include "main.h"



#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
void compileShaderProgram(ShaderProgram *program, int shaderc, Shader **shaders, char **uniform_names, int uniformc, Uniform *uniforms)
{
    program->program_id = glCreateProgram();
    for(int i = 0; i < shaderc; i++)
    {
        if(!compileShader(shaders[i]))
        {
            checkShaderCompile(shaders[i]);
            continue;
        }
        glAttachShader(program->program_id, shaders[i]->shader_id);
    }
    glLinkProgram(program->program_id);

    int success;
    glGetProgramiv(program->program_id, GL_LINK_STATUS, &success);
    if(!success) checkShaderPrCompile(program->program_id);

    for(int i = 0; i < uniformc; i++)
    {
        uniforms[i] = (Uniform){glGetUniformLocation(program->program_id, uniform_names[i]), uniform_names[i]};
    }
}
int compileShader(Shader *shader)
{
    shader->shader_id = glCreateShader(shader->type);
    glShaderSource(shader->shader_id, 1, shader->source, NULL);
    glCompileShader(shader->shader_id);

    int success;
    glGetShaderiv(shader->shader_id, GL_COMPILE_STATUS, &success);
    return success;
}
void error_callback(int code, char* description)
{
    printf("%s", description);
}

void initializeVBO(VBO *vbo)
{
    glGenBuffers(1, &(vbo->vbo_id));
    glBindBuffer(GL_ARRAY_BUFFER, vbo->vbo_id);
    glBufferData(GL_ARRAY_BUFFER, vbo->data_size, vbo->data, vbo->usage);
}
void initializeVAO(VAO *vao, int vboc, VBO **vbos)
{
    glGenVertexArrays(1, &(vao->vao_id));
    glBindVertexArray(vao->vao_id);

    for(int i = 0; i < vboc; i++)
    {
        initializeVBO(vbos[i]);
        glVertexAttribPointer(i, vbos[i]->unit_size, vbos[i]->data_type, vbos[i]->normalized, vbos[i]->unit_size * sizeof(float), (void*)0);
        glEnableVertexAttribArray(i);
    }  

}
void checkShaderCompile(Shader *shader)
{
    int s = 512;
    char infoLog[s];
    glGetShaderInfoLog(shader->shader_id, s, NULL, infoLog);
    printf("Shader compilation error: %s", infoLog);
}

void checkShaderPrCompile(unsigned int program)
{
    int s = 512;
    char infoLog[s];
    glGetProgramInfoLog(program, s, NULL, infoLog);
    printf("Shader program compilation error: %s", infoLog);
}
void initializeTexture(Texture *texture)
{
    texture->data = stbi_load(texture->filepath, &(texture->width), &(texture->height), &(texture->nrChannels), 0);
    glGenTextures(1, &(texture->tex_id));
    glBindTexture(GL_TEXTURE_2D, texture->tex_id);
    if(!texture->data)
    {
        printf("Failed to load texture data");
        return;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, texture->internal_format, texture->width, texture->height, 0, texture->format, texture->data_type, texture->data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(texture->data);
}

void renderLoop(GLFWwindow* window)
{
    float vertices[] = {
        -1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f,0.0f,
        1.0f, 1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f
    };

    float uvs[] = {
        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f
    };

    VBO basicVBOVerts = {
        GL_FLOAT, 
        vertices,
        sizeof(vertices),
        GL_STATIC_DRAW,
        GL_FALSE,
        0,
        3
    };


    VBO basicVBOTex = {
        GL_FLOAT,
        uvs,
        sizeof(uvs),
        GL_STATIC_DRAW,
        GL_FALSE,
        0,
        2
    };

    VAO basicVAO = {
        0
    };

    Shader basicVertexShader = {
        GL_VERTEX_SHADER,
        &basicvs,
        0
    };

    Shader basicFragmentShader = {
        GL_FRAGMENT_SHADER,
        &basicfs,
        0
    };

    ShaderProgram basicShaderProgram = {
        &basicVAO,
        0,
        0,
        NULL
    };

    Texture catTexture = {
        0,
        0,
        0,
        NULL,
        0,
        GL_UNSIGNED_BYTE,
        GL_RGB,
        GL_RGB,
        "cat.jpg"
    }; 

    VBO *vbos[] = {&basicVBOVerts, &basicVBOTex};
    Shader *shaders[] = {&basicVertexShader, &basicFragmentShader};
    char *uniform_names[] = {};
    int uniformc = 0;
    Uniform *uniforms = malloc(uniformc * sizeof(Uniform));
    
    compileShaderProgram(&basicShaderProgram,  sizeof(shaders) / sizeof(shaders[0]), shaders, uniform_names, uniformc, uniforms);
    initializeTexture(&catTexture);
    initializeVAO(&basicVAO, sizeof(vbos) / sizeof(vbos[0]), vbos);
    glUseProgram(basicShaderProgram.program_id);

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
        process_input(window);
    }
    
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
    
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
    

    if(!initGL()) return 0;

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    

    renderLoop(window);

    char c;
    scanf(&c);
    glfwTerminate();
    return 0;

}