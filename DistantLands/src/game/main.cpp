#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "../engine/Window.h"
#include "Game.h"
#include "../engine/Time.h"

int main(void)
{
    //TODO: move to renderer
    if (!glfwInit())
    {
        return -1;
    }

    //Create and initialize game.
    Game* game = new Game();

    if (!game->Init())
    {
        return -1;
    }

    //Timing variables
    f64 frame_start = 0;
    f64 dt = 0.16;

    //Game Loop
    while (game->Running())
    {
        frame_start = TIME_NOW_SECONDS();
        game->Update(dt);
        dt = TIME_NOW_SECONDS() - frame_start;
    }

    return 0;
}