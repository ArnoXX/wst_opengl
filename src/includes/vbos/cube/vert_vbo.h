#pragma once
#include "../../glad/glad.h"
#include "../../gl_objs.h"

float cube_vertices[] = {
    -1.0f, 1.0f, 1.0f, //front
    1.0f, 1.0f, 1.0f,
    -1.0f, -1.0f,1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,

    -1.0f, 1.0f, -1.0f, //back
    1.0f, 1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,

    -1.0f, 1.0f, -1.0f, // top
    1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,

    -1.0f, -1.0f, -1.0f, //bottom
    1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,

    1.0f, 1.0f, -1.0f, //right
    1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,

    -1.0f, 1.0f, -1.0f, //left
    -1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f
};

VBO cubeVBOVerts = {
    0, 
    3, 
    sizeof(cube_vertices),
    GL_FLOAT, 
    GL_STATIC_DRAW, 
    GL_FALSE, 
    cube_vertices, 
    0
};