#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "../core/Types.h"
namespace Engine
{
	class Window
	{
	public:
		Window(std::string title);
		~Window();

		bool Init();

		inline GLFWwindow* GetGLFWwindowInstance() { return window; }

		std::string& Title() { return title; }
		i32& Width() { return width; }
		i32& Height() { return height; }

		bool ShouldClose();
		void SwapBuffers();
	private:
		GLFWwindow* window;

		std::string title;
		i32 width;
		i32 height;
	};
}