#include "includes/objects/shapes/pyramid.h"
#include "includes/shaders/programs/pyramid.h"
#include "includes/textures/pyramid/main_texture.h"
#include "includes/vaos/pyramid_vao.h"
#include "includes/cglm/call.h"
#include "includes/glad/glad.h"


void pyramid_init(Object *obj)
{
    if(!pyramidShaderProgram.linked) compileShaderProgram(&pyramidShaderProgram);
    if(!pyramidTexture.initialized) initializeTexture(&pyramidTexture);
    if(!pyramidVAO.initialized) initializeVAO(&pyramidVAO);

    obj->texturec = 1;
    obj->texture_ids = calloc(obj->texturec, sizeof(unsigned int));
    obj->texture_units = calloc(obj->texturec, sizeof(unsigned int));

    obj->vao_id = pyramidVAO.id;
    obj->texture_ids[0] = pyramidTexture.id;
    obj->texture_units[0] = pyramidTexture.unit;
    obj->program_id = pyramidShaderProgram.id;
    obj->vert_count = pyramidVAO.vert_count;

    obj->initialized = 1;
}

void pyramid_render(Object *obj)
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

void pyramid_uniform_mat4f(Object *obj, char* uniform_name, mat4 mat)
{
    glUseProgram(obj->program_id);
    glUniformMatrix4fv(glGetUniformLocation(obj->program_id, uniform_name), 1, GL_FALSE, mat[0]);
}

void pyramid_place(Object *obj, mat4 model_mat)
{
    glmc_mat4_identity(model_mat);
    glmc_translate(model_mat, obj->pos);
}