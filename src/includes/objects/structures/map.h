#pragma once
#include "../shapes/cube.h"
#include "../../gl_objs.h"
#include "../../cglm/call.h"

typedef struct 
{
    int w, h;
    char *data;
    Object *objects;
} Map;

void map_init(Map *map, char (*data)[map->w][map->w]);
void map_render(Map *map, mat4 *v, mat4 *p);
