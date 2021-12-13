#version 430 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uv;

out vec3 col;
out vec2 tex_uv;

void main()
{
    col = pos;
    tex_uv = uv;
    gl_Position = vec4(pos, 1.0);
}