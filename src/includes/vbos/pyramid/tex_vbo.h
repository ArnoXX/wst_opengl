#pragma once
#include "../../glad/glad.h"
#include "../../gl_objs.h"

float pyramid_uvs[] = {
    0.0f, 0.0f,
    0.5f, 1.0f, 
    1.0f, 0.0f,

    0.0f, 0.0f,
    0.5f, 1.0f, 
    1.0f, 0.0f,

    0.0f, 0.0f,
    0.5f, 1.0f, 
    1.0f, 0.0f,

    0.0f, 0.0f,
    0.5f, 1.0f, 
    1.0f, 0.0f
};

VBO pyramidVBOTex = {
    0,
    2,
    sizeof(pyramid_uvs),
    GL_FLOAT, 
    GL_STATIC_DRAW,
    GL_FALSE,
    pyramid_uvs,
    0
};