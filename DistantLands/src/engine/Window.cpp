#include "Window.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	//std::string new_title = std::string("Size: ");
	//new_title += std::to_string(width);
	//new_title += ", ";
	//new_title += std::to_string(height);
	//glfwSetWindowTitle(window, new_title.c_str());
}
Window::Window(std::string title)
{
	this->title = title;
	window = NULL;
}

Window::~Window()
{
	glfwDestroyWindow(window);
}

bool Window::Init()
{
	window = glfwCreateWindow(100, 100, title.c_str(), NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwMaximizeWindow(window);
	return true;
}

i32 Window::Width()
{
	int w, h;
	glfwGetWindowSize(window, &w, &h);
	return w;
}

i32 Window::Height()
{
	int w, h;
	glfwGetWindowSize(window, &w, &h);
	return h;
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(window);
}
