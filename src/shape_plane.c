

static float plane_vertices[] = {
    -1.0f, 1.0f, 0.0f, 
    1.0f, -1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f,
    -1.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
    1.0f, -1.0f, 0.0f
};

static float plane_uvs[] = {
    0.0f, 1.0f,
    1.0f, 0.0f, 
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f 
};

// static VBO plainVBOVerts = {
//     GL_FLOAT, 
//     plain_vertices,
//     sizeof(plain_vertices),
//     GL_STATIC_DRAW,
//     GL_FALSE,
//     0,
//     3
// };

// static VBO plainVBOTex = {
//     GL_FLOAT,
//     plain_uvs,
//     sizeof(plain_uvs),
//     GL_STATIC_DRAW,
//     GL_FALSE,
//     0,
//     2
// };

// static VAO plainVAO = {
//     0
// };

// static Shader plainVertexShader = {
//     GL_VERTEX_SHADER,
//     &basicvs,
//     0
// };

// static Shader plainFragmentShader = {
//     GL_FRAGMENT_SHADER,
//     &basicfs,
//     0
// };