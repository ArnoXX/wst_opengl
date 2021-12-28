#pragma once
#include "../../glad/glad.h"
#include "../../gl_objs.h"

float pyramid_vertices[] = {
    -1.0f, -1.0f, 1.0f,
    0.0f, 1.0f, 0.0f,
    1.0f, -1.0f, 1.0f,

    1.0f, -1.0f, 1.0f,
    0.0f, 1.0f, 0.0f,
    1.0f, -1.0f, -1.0f,

    1.0f, -1.0f, -1.0f,
    0.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    0.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, 1.0f
};

VBO pyramidVBOVerts = {
    0, 
    3, 
    sizeof(pyramid_vertices),
    GL_FLOAT, 
    GL_STATIC_DRAW, 
    GL_FALSE, 
    pyramid_vertices, 
    0
};