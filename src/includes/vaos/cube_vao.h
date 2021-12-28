#pragma once
#include "../gl_objs.h"
#include "../vbos/cube/tex_vbo.h"
#include "../vbos/cube/vert_vbo.h"

static VBO *vbos[] = {&cubeVBOVerts, &cubeVBOTex};

VAO cubeVAO = {
    0,
    0,
    2,
    36,
    vbos
};