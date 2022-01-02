#ifndef _CUBE_H_
#define _CUBE_H_
#include "../../gl_objs.h"
#include "../../cglm/call.h"

void cube_init(Object *obj);
void cube_render(Object *obj, mat4 *v, mat4 *p);
void cube_uniform_mat4f(Object *obj, char* uniform_name, mat4 mat);
void cube_place(Object *obj, mat4 model_mat);
void cube_set_pos(Object *obj, float x, float y, float z);


#endif
