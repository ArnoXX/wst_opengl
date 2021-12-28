#ifndef _PYRAMID_H_
#define _PYRAMID_H_
#include "../../gl_objs.h"
#include "../../cglm/call.h"

void pyramid_init(Object *obj);
void pyramid_render(Object *obj);
void pyramid_uniform_mat4f(Object *obj, char* uniform_name, mat4 mat);
void pyramid_place(Object *obj, mat4 model_mat);


#endif