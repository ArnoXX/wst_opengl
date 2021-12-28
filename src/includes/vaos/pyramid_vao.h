#pragma once
#include "../gl_objs.h"
#include "../vbos/pyramid/tex_vbo.h"
#include "../vbos/pyramid/vert_vbo.h"

static VBO *vbos[] = {&pyramidVBOVerts, &pyramidVBOTex};

VAO pyramidVAO = {
    0,
    0,
    2,
    12,
    vbos
};