#pragma once
#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>

class MainMenu : public Entity
{
public:
	MainMenu(SDL_Renderer* renderer);
	~MainMenu();

	void Render();
	bool Run();

	bool startButtonPressed(SDL_Event* e);

private:
	SDL_Texture* background;
	SDL_Texture* startButton;

	int buttonH;
	int buttonW;
};