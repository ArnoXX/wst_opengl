#pragma once
#include "../../glad/glad.h"
#include "../../gl_objs.h"
#include "../sources/basic.vs.h"

Shader cubeVertexShader = {
    0,
    &basicvs,
    GL_VERTEX_SHADER,
    0
};