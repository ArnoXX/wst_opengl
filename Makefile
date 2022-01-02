CC = gcc
LIBS = -lglfw3 -lgdi32 -lopengl32 -lcglm
CFLAGS = -L./libs -I./src/includes
TARGET = main
SRC = ./src
SHADERS_FOLDER = ./shaders
SHADERS = basic.fs basic.vs plane.fs plane.vs pyramid.fs pyramid.vs
UTILS = ./utils


main: shaders bare

shaders: $(SHADERS)

$(SHADERS):
	python $(UTILS)/copy_contents_as_string.py $@

bare:
	$(CC) $(SRC)/*.c $(CFLAGS) $(LIBS) -o $(TARGET)

