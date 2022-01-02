#pragma once
#include "../../glad/glad.h"
#include "../../gl_objs.h"
#include "../sources/plane.vs.h"

Shader planeVertexShader = {
    0,
    &planevs,
    GL_VERTEX_SHADER,
    0
};