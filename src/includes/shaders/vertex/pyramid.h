#pragma once
#include "../../glad/glad.h"
#include "../../gl_objs.h"
#include "../sources/pyramid.vs.h"

Shader pyramidVertexShader = {
    0,
    &pyramidvs,
    GL_VERTEX_SHADER,
    0
};