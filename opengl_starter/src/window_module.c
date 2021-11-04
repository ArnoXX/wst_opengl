#include <stdio.h>
#include "window_module.h"


/*
Resizable
Maximazed
Doublebuffer
opengl_api
core_profile
main_cycle
event_processing
//input_processing
cursor_manipulation
keyboard_reading
//event_processing
framebuffer_watch
buffer_swapping
context_control


*/

void module_init()
{

	if (!glfwInit())
	{
		int code = glfwGetError(NULL);

		if (code != GLFW_NO_ERROR)
			error_handle(code, "Failed initialization.");
	}

	glfwSetErrorCallback(error_handle);
}

GLFWwindow* window_init()
{
	GLFWmonitor* primary_monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(primary_monitor);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Window", primary_monitor, NULL);


}

void window_end(GLFWwindow* window)
{
	glfwDestroyWindow(window);
}

void error_handle(int code, const char* description)
{
	printf("ERROR::%c - %s", code, description);
}

