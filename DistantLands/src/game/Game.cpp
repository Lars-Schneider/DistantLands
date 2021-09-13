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
	return true;
}

void Game::Update(f64 dt)
{
	//Swap Buffers
	window->SwapBuffers();
	//Clear
	glClear(GL_COLOR_BUFFER_BIT);
	//Poll Events
	glfwPollEvents();
	//Exit conditions
	running = !window->ShouldClose();
}