#include "Game.h"
#include "../utils/file io/FileIO.h"
#include "../engine/Time.h"
Game::Game()
{
	window = new Window("Distant Lands");
}

Game::~Game()
{
	delete window;
}

bool Game::Init()
{
	if (!window->Init()) return false;
	running = true;
	start = TIME_NOW_SECONDS();
	return true;
}

void Game::Update(f64 dt)
{
	window->SwapBuffers();

	x += 1 * dt;
	if (x >= 1.f)
	{
		f64 elapsed = TIME_NOW_SECONDS() - start;
		std::cout << elapsed << "seconds. Average of " << 1 / dt << "fps. Average of " << elapsed << " seconds per pixel\n";
		x = 0;
		start = TIME_NOW_SECONDS();
	}
}

void Game::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
	running = !window->ShouldClose();
}
