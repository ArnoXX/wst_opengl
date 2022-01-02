#include "includes/objects/structures/map.h"
#include "includes/objects/shapes/cube.h"

void map_init(Map *map, char (*data)[map->w][map->w])
{
    map->data = data;

    Object *objects = calloc(map->w * map->h, sizeof(Object));
    for(int x = 0; x < map->w; x++)
    {
        for(int y = 0; y < map->h; y++)
        {
            if(map->data[x * map->w + y] == (char)0)
            {
                objects[x * map->w + y] = (Object){};
            } else
            {
                cube_set_pos(&objects[x * map->w + y], x * 2.4f, 0.0f, y * -2.4f);
                cube_init(&objects[x * map->w + y]);
            }
        }
    }
    map->objects = objects;
}
void map_render(Map *map, mat4 *v, mat4 *p)
{
    for(int x = 0; x < map->w; x++)
    {
        for(int y = 0; y < map->h; y++)
        {
            if(map->data[x * map->w + y] != (char)0) cube_render(&(map->objects[x * map->w + y]), v, p);
        }
    }
}

