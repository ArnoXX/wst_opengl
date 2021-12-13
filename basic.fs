#version 430 core
out vec4 FragColor;
in vec3 col;
in vec2 tex_uv;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, tex_uv) * vec4(col, 1.0f);
}