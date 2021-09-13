#pragma once
#include "../engine/Window.h"

class Game
{
public:
	Game();
	~Game();

	bool Init();

	void Update(f64 dt);

	void Render();

	bool Running() { return running; }
private:
	bool running = false;
	Window* window;
	f64 x = 0;
	f64 start;
};
