#ifndef _GLOBJS_H_
#define _GLOBJS_H_
#include "glad/glad.h"
#include "cglm/call.h"




typedef struct
{
    int initialized, unit_size, data_size;
    GLenum data_type, usage, normalized;
    void *data;
    unsigned int id;
} VBO;

typedef struct 
{
    unsigned int id;
    int initialized, vboc, vert_count;
    VBO **vbos;
} VAO;

typedef struct 
{
    int compiled;
    const char **source;
    GLenum type;
    unsigned int id;
} Shader;

typedef struct 
{
    unsigned int id;
    int linked, shaderc;
    Shader **shaders;
} ShaderProgram;

typedef struct 
{
    int initialized, unit;
    unsigned int id;
    char *filepath;
    GLenum data_type, internal_format, format;
} Texture;

typedef struct 
{
    vec3 pos, scale, rot_ax;
    float rot_angle;
    int vert_count, texturec, initialized;
    unsigned int vao_id, program_id, *texture_ids, *texture_units;
} Object;

void initializeVBO(VBO *vbo);
void initializeVAO(VAO *vao);
void checkShaderPrCompile(unsigned int program);
int compileShader(Shader *shader);
void initializeTexture(Texture *texture);
void checkShaderCompile(Shader *shader);
void compileShaderProgram(ShaderProgram *program);

#endif