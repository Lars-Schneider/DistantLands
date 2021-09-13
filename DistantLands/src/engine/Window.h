#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "../utils/Types.h"
class Window
{
public:
	Window(std::string title);
	~Window();

	bool Init();

	inline GLFWwindow* GetGLFWwindowInstance() { return window; }

	std::string Title() { return title; }
	i32 Width();
	i32 Height();

	bool ShouldClose();
	void SwapBuffers();
private:
	GLFWwindow* window;

	std::string title;
	i32 width;
	i32 height;
};
