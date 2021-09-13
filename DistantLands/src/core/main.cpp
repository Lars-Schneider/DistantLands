#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "../engine/Window.h"



int main(void)
{
    if (!glfwInit())
    {
        return -1;
    }

    Engine::Window* window = new Engine::Window("Distant Lands");

    if (!window->Init())
    {
        return -1;
    }
    while (!window->ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        window->SwapBuffers();
        glfwPollEvents();
    }

    delete window;
    return 0;
}