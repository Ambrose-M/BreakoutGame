#pragma once
#include "Entity.h"
#include<string>

using namespace std;

class GameOverMenu : public Entity
{
public:
	//Initilizes menu's textures and variables
	GameOverMenu(SDL_Renderer* renderer);

	//Delete's menu's resources
	~GameOverMenu();

	//Renders menu to screen
	void Render();

	//Checks if button has been pressed and returns string indicating which one was
	string buttonPressed(SDL_Event* e);

	//Renders menu and checks if buttons are clicked
	string Run();

private:
	//Background texture
	SDL_Texture* background;

	//Yes button texture
	SDL_Texture* yesButton;

	//No button texture
	SDL_Texture* noButton;

	//Button height
	int buttonH;

	//Button width
	int buttonW;
};