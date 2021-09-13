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
    f64 t = 0.0;
    f64 dt = 1 / 60.0;

    f64 currentTime = TIME_NOW_SECONDS();
    f64 newTime;
    f64 frameTime;
    f32 deltaTime;
    while (game->Running())
    {
        newTime = TIME_NOW_SECONDS();
        frameTime = newTime - currentTime;
        currentTime = newTime;

        while (frameTime > 0.0)
        {
            f32 deltaTime = fmin(frameTime, dt);
            game->Update(dt);
            frameTime -= deltaTime;
            t += deltaTime;
        }

        game->Render();
    }

    return 0;
}