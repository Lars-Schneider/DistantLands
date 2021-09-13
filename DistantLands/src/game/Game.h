#pragma once
#include "../engine/Window.h"

class Game
{
public:
	Game();
	~Game();

	bool Init();

	void Update(f32 dt);

	bool Running() { return running; }
private:
	bool running = false;
	Window* window;
	f32 fps;
};
