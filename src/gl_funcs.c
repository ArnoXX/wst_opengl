#include "includes/glad/glad.h"
#include "includes/gl_objs.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void compileShaderProgram(ShaderProgram *program)
{
    program->id = glCreateProgram();
    for(int i = 0; i < program->shaderc; i++)
    {
        if(!compileShader(program->shaders[i]))
        {
            checkShaderCompile(program->shaders[i]);
            continue;
        }
        program->shaders[i]->compiled = 1;
        glAttachShader(program->id, program->shaders[i]->id);
    }
    glLinkProgram(program->id);
    

    int success;
    glGetProgramiv(program->id, GL_LINK_STATUS, &success);
    if(!success) checkShaderPrCompile(program->id);
    else program->linked = 1;
}
int compileShader(Shader *shader)
{
    shader->id = glCreateShader(shader->type);
    glShaderSource(shader->id, 1, shader->source, NULL);
    glCompileShader(shader->id);

    int success;
    glGetShaderiv(shader->id, GL_COMPILE_STATUS, &success);
    return success;
}
void initializeVBO(VBO *vbo)
{
    glGenBuffers(1, &(vbo->id));
    glBindBuffer(GL_ARRAY_BUFFER, vbo->id);
    glBufferData(GL_ARRAY_BUFFER, vbo->data_size, vbo->data, vbo->usage);

    vbo->initialized = 1;
}
void initializeVAO(VAO *vao)
{
    glGenVertexArrays(1, &(vao->id));
    glBindVertexArray(vao->id);

    for(int i = 0; i < vao->vboc; i++)
    {
        initializeVBO(vao->vbos[i]);
        glVertexAttribPointer(i, vao->vbos[i]->unit_size, vao->vbos[i]->data_type, vao->vbos[i]->normalized, vao->vbos[i]->unit_size * sizeof(float), (void*)0);
        glEnableVertexAttribArray(i);
    }  

    vao->initialized = 1;
}
void checkShaderCompile(Shader *shader)
{
    int s = 512;
    char infoLog[s];
    glGetShaderInfoLog(shader->id, s, NULL, infoLog);
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
    int width, height, nrChannels;
    unsigned char *data = stbi_load(texture->filepath, &width, &height, &nrChannels, 0);
    glGenTextures(1, &(texture->id));
    glActiveTexture(GL_TEXTURE0 + texture->unit);
    glBindTexture(GL_TEXTURE_2D, texture->id);
    if(!data)
    {
        printf("Failed to load texture data");
        return;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, texture->internal_format, width, height, 0, texture->format, texture->data_type, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    texture->initialized = 1;

    stbi_image_free(data);
}