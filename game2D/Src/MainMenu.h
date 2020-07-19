#pragma once
#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>

class MainMenu : public Entity
{
public:
	//Initilize textures and variables
	MainMenu(SDL_Renderer* renderer);

	//Delete menu's resources
	~MainMenu();

	//Render menu to screen
	void Render();

	//Renders menu to screen and checks if start button is pressed.
	bool Run();

	//Returns true if start button is pressed, false if not.
	bool startButtonPressed(SDL_Event* e);

private:
	//Menu's background
	SDL_Texture* background;

	//Start button
	SDL_Texture* startButton;

	//Button height
	int buttonH;

	//Button width
	int buttonW;
};