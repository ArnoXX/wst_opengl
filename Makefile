main: shaders bare
	
shaders:
	python copy_contents_as_string.py basic.vs
	python copy_contents_as_string.py basic.fs

bare:
	gcc -o main main.c glad.c -I. -L. -lgdi32 -lglfw3dll

test:
	gcc -o test test.c glad.c -I. -L. -lgdi32 -lglfw3dll