#include "includes/objects/shapes/plane.h"
#include "includes/shaders/programs/plane.h"
#include "includes/textures/plane/main_texture.h"
#include "includes/vaos/plane_vao.h"
#include "includes/cglm/call.h"
#include "includes/glad/glad.h"


void plane_init(Object *obj)
{
    if(!planeShaderProgram.linked) compileShaderProgram(&planeShaderProgram);
    if(!planeTexture.initialized) initializeTexture(&planeTexture);
    if(!planeVAO.initialized) initializeVAO(&planeVAO);

    obj->texturec = 1;
    obj->texture_ids = calloc(obj->texturec, sizeof(unsigned int));
    obj->texture_units = calloc(obj->texturec, sizeof(unsigned int));

    obj->vao_id = planeVAO.id;
    obj->texture_ids[0] = planeTexture.id;
    obj->texture_units[0] = planeTexture.unit;
    obj->program_id = planeShaderProgram.id;
    obj->vert_count = planeVAO.vert_count;

    obj->initialized = 1;
}

void plane_set_pos(Object *obj, float x, float y, float z)
{
    obj->pos[0] = x;
    obj->pos[1] = y;
    obj->pos[2] = z;
}

void plane_render(Object *obj, mat4 *v, mat4 *p)
{
    glBindVertexArray(obj->vao_id);
    glUseProgram(obj->program_id);
    for(int i = 0; i < obj->texturec; i++)
    {
        glActiveTexture(GL_TEXTURE0 + obj->texture_units[i]);
        glBindTexture(GL_TEXTURE_2D, obj->texture_ids[i]);
    }

    mat4 m, mvp;
    
    plane_place(obj, m);

    glm_mat4_mulN((mat4 *[]){p, v, &m}, 3, mvp);

    plane_uniform_mat4f(obj, "transform", mvp);

    glDrawArrays(GL_TRIANGLES, 0, obj->vert_count);
}

void plane_uniform_mat4f(Object *obj, char* uniform_name, mat4 mat)
{
    glUniformMatrix4fv(glGetUniformLocation(obj->program_id, uniform_name), 1, GL_FALSE, mat[0]);
}

void plane_place(Object *obj, mat4 model_mat)
{
    glmc_mat4_identity(model_mat);
    glmc_translate(model_mat, obj->pos);
}