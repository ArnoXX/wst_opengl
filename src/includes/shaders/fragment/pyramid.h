#pragma once
#include "../../gl_objs.h"
#include "../sources/pyramid.fs.h"
#include "../../glad/glad.h"

Shader pyramidFragmentShader = {
    0,
    &pyramidfs,
    GL_FRAGMENT_SHADER,
    0
};