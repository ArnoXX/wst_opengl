#include "includes/objects/shapes/cube.h"
#include "includes/shaders/programs/cube.h"
#include "includes/textures/cube/main_texture.h"
#include "includes/vaos/cube_vao.h"
#include "includes/cglm/call.h"
#include "includes/glad/glad.h"


void cube_init(Object *obj)
{
    if(!cubeShaderProgram.linked) compileShaderProgram(&cubeShaderProgram);
    if(!cubeTexture.initialized) initializeTexture(&cubeTexture);
    if(!cubeVAO.initialized) initializeVAO(&cubeVAO);

    obj->texturec = 1;
    obj->texture_ids = calloc(obj->texturec, sizeof(unsigned int));
    obj->texture_units = calloc(obj->texturec, sizeof(unsigned int));

    obj->vao_id = cubeVAO.id;
    obj->texture_ids[0] = cubeTexture.id;
    obj->texture_units[0] = cubeTexture.unit;
    obj->program_id = cubeShaderProgram.id;
    obj->vert_count = cubeVAO.vert_count;

    obj->initialized = 1;
}

void cube_render(Object *obj)
{
    glBindVertexArray(obj->vao_id);
    glUseProgram(obj->program_id);
    for(int i = 0; i < obj->texturec; i++)
    {
        glActiveTexture(GL_TEXTURE0 + obj->texture_units[i]);
        glBindTexture(GL_TEXTURE_2D, obj->texture_ids[i]);
    }

    glDrawArrays(GL_TRIANGLES, 0, obj->vert_count);
}

void cube_uniform_mat4f(Object *obj, char* uniform_name, mat4 mat)
{
    glUseProgram(obj->program_id);
    glUniformMatrix4fv(glGetUniformLocation(obj->program_id, uniform_name), 1, GL_FALSE, mat[0]);
}

void cube_place(Object *obj, mat4 model_mat)
{
    glmc_mat4_identity(model_mat);
    glmc_translate(model_mat, obj->pos);
}