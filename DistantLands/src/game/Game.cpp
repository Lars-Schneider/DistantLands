#include "Game.h"
#include "../utils/file io/FileIO.h"
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
	return true;
}

void Game::Update(f32 dt)
{
	fps = 1 / dt;
	glClear(GL_COLOR_BUFFER_BIT);
	window->SwapBuffers();
	glfwPollEvents();

	running = !window->ShouldClose();
}
