#pragma once
#include "../../glad/glad.h"
#include "../../gl_objs.h"

static float plane_vertices[] = {
    -1.0f, 1.0f, 0.0f, 
    1.0f, -1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f,
    -1.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
    1.0f, -1.0f, 0.0f
};

VBO planeVBOVerts = {
    0, 
    3, 
    sizeof(plane_vertices),
    GL_FLOAT, 
    GL_STATIC_DRAW, 
    GL_FALSE, 
    plane_vertices, 
    0
};