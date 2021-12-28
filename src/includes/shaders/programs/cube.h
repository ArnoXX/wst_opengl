#pragma once
#include "../../gl_objs.h"
#include "../vertex/cube.h"
#include "../fragment/cube.h"

static Shader *shaders[] = {&cubeVertexShader, &cubeFragmentShader};

ShaderProgram cubeShaderProgram = {
    0,
    0,
    2,
    shaders
};