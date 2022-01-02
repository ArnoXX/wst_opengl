#pragma once
#include "../../glad/glad.h"
#include "../../gl_objs.h"

static float plane_uvs[] = {
    0.0f, 1.0f,
    1.0f, 0.0f, 
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f 
};

VBO planeVBOTex = {
    0,
    2,
    sizeof(plane_uvs),
    GL_FLOAT, 
    GL_STATIC_DRAW,
    GL_FALSE,
    plane_uvs,
    0
};