#define GLFW_DLL
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "cglm/call.h"

#include "basic.vs.h"
#include "basic.fs.h"


typedef struct
{
    GLenum data_type;
    void *data;
    size_t data_size;
    GLenum usage;
    GLenum normalized;
    unsigned int vbo_id; // id of the vbo
    int unit_size; // size of one vertex
} VBO;
typedef struct 
{
    unsigned int vao_id;
} VAO;
typedef struct 
{
    GLenum type;
    const char **source;
    unsigned int shader_id;
} Shader;
typedef struct 
{
    VAO *vao;
    int shaderc;
    unsigned int program_id;
    int *uniform_locations;
} ShaderProgram;
typedef struct
{
    int uniform_location;
    char *name;
} Uniform;

typedef struct 
{
    int width, height, nrChannels;
    unsigned char *data;
    unsigned int tex_id;
    GLenum data_type;
    GLenum internal_format;
    GLenum format;
    char *filepath;
    int tex_unit;
} Texture;
typedef struct
{
    vec3 camPos;
    vec3 camDir;
    vec3 camUp;
    float camSpeed, lastX, lastY, yaw, pitch;
} InputState;

void process_input(GLFWwindow *window, InputState *state, float time_delta);
void initializeVBO(VBO *vbo);
void initializeVAO(VAO *vao, int vboc, VBO **vbos);
void checkShaderPrCompile(unsigned int program);
int compileShader(Shader *shader);
void initializeTexture(Texture *texture);
void checkShaderCompile(Shader *shader);
int initGL();
int initGLFW();
void compileShaderProgram(ShaderProgram *program, int shaderc, Shader **shaders, char **uniform_names, int uniformc, Uniform *uniforms);
void checkShaderPrCompile(unsigned int program);
void opengl_error_callback(GLenum source, GLenum type, GLint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

