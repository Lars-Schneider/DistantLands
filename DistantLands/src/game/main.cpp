#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "../engine/Window.h"
#include "Game.h"



int main(void)
{
    if (!glfwInit())
    {
        return -1;
    }

    Game* game = new Game();
    if (!game->Init())
    {
        return -1;
    }
    while (game->Running())
    {
        game->Update(1);
    }
    return 0;
}