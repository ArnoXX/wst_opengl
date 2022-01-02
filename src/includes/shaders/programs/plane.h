#pragma once
#include "../../gl_objs.h"
#include "../vertex/plane.h"
#include "../fragment/plane.h"

static Shader *shaders[] = {&planeVertexShader, &planeFragmentShader};

ShaderProgram planeShaderProgram = {
    0,
    0,
    2,
    shaders
};