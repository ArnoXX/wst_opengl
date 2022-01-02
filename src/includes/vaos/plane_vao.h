#pragma once
#include "../gl_objs.h"
#include "../vbos/plane/tex_vbo.h"
#include "../vbos/plane/vert_vbo.h"

static VBO *vbos[] = {&planeVBOVerts, &planeVBOTex};

VAO planeVAO = {
    0,
    0,
    2,
    6,
    vbos
};