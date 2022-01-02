#pragma once
#include "../../gl_objs.h"
#include "../sources/plane.fs.h"
#include "../../glad/glad.h"

Shader planeFragmentShader = {
    0,
    &planefs,
    GL_FRAGMENT_SHADER,
    0
};