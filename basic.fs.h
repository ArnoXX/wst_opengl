const char *basicfs = "#version 430 core\n" 
"out vec4 FragColor;\n" 
"in vec3 col;\n" 
"void main()\n" 
"{\n" 
"    FragColor = vec4(col, 1.0f);\n" 
"}\n" 
;