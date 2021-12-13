const char *basicfs = "#version 430 core\n" 
"out vec4 FragColor;\n" 
"in vec3 col;\n" 
"in vec2 tex_uv;\n" 
"\n" 
"uniform sampler2D ourTexture;\n" 
"\n" 
"void main()\n" 
"{\n" 
"    FragColor = texture(ourTexture, tex_uv) * vec4(col, 1.0f);\n" 
"}\n" 
;