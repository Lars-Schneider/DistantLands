#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "../engine/Window.h"
#include "Game.h"
#include "../engine/Time.h"

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

    //Loop
    f64 frame_start = 0;
    f64 dt = 0.16;
    while (game->Running())
    {
        frame_start = TIME_NOW_SECONDS();
        game->Update(dt);
        game->Render();
        dt = TIME_NOW_SECONDS() - frame_start;
    }

    return 0;
}