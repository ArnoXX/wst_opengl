#pragma once
#include "../../gl_objs.h"
#include "../sources/basic.fs.h"
#include "../../glad/glad.h"

Shader cubeFragmentShader = {
    0,
    &basicfs,
    GL_FRAGMENT_SHADER,
    0
};