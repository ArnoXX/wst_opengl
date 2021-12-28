#pragma once
#include "../../glad/glad.h"
#include "../../gl_objs.h"

float cube_uvs[] = {
    0.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,

    0.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,

    0.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f
};

VBO cubeVBOTex = {
    0,
    2,
    sizeof(cube_uvs),
    GL_FLOAT, 
    GL_STATIC_DRAW,
    GL_FALSE,
    cube_uvs,
    0
};