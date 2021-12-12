#define GLFW_DLL
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "basic.vs.h"
#include "basic.fs.h"


typedef struct
{
    GLenum data_type;
    void *data;
    size_t data_size;
    unsigned int vao_index; // vertexx attrib array index
    GLenum usage;
    GLenum normalized;
    unsigned int vbo_id; // id of the vbo
    int unit_size; // size of one vertex
} VBO;
typedef struct 
{
    int vboc;
    unsigned int vao_id;
    VBO **vbos;
} VAO;
typedef struct 
{
    GLenum type;
    char **uniforms;
    int uniformc;
    const char **source;
    unsigned int shader_id;
} Shader;
typedef struct 
{
    VAO *vao;
    int shaderc;
    unsigned int program_id;
    Shader *shaders;
} ShaderProgram;


void init();
void initializeVBO(VBO *vbo);
void initializeVAO(VAO *vao, int vboc, VBO **vbos);
void checkShaderPrCompile(unsigned int program);
int compileShader(Shader *shader);
void checkShaderCompile(Shader *shader);
void compileShaderProgram(ShaderProgram *program, int shaderc, Shader **shaders);
void checkShaderPrCompile(unsigned int program);
void opengl_error_callback(GLenum source, GLenum type, GLint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);

