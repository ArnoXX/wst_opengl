#pragma once
#include "../../gl_objs.h"
#include "../../cglm/call.h"

void plane_init(Object *obj);
void plane_render(Object *obj, mat4 *v, mat4 *p);
void plane_uniform_mat4f(Object *obj, char* uniform_name, mat4 mat);
void plane_place(Object *obj, mat4 model_mat);
void plane_set_pos(Object *obj, float x, float y, float z);