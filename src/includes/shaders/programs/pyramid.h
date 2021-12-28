#pragma once
#include "../../gl_objs.h"
#include "../vertex/pyramid.h"
#include "../fragment/pyramid.h"

static Shader *shaders[] = {&pyramidVertexShader, &pyramidFragmentShader};

ShaderProgram pyramidShaderProgram = {
    0,
    0,
    2,
    shaders
};