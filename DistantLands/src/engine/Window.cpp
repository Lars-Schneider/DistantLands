#include "Window.h"
namespace Engine
{
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
		std::cout << title.c_str();
		window = glfwCreateWindow(100, 100, title.c_str(), NULL, NULL);

		if (!window)
		{
			glfwTerminate();
			return false;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		glfwMaximizeWindow(window);
		return true;
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(window);
	}
}