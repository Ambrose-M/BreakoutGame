#pragma once
#include "Entity.h"
#include<string>

using namespace std;

class GameOverMenu : public Entity
{
public:
	GameOverMenu(SDL_Renderer* renderer);
	~GameOverMenu();

	void Render();

	string buttonPressed(SDL_Event* e);

	string Run();

private:
	SDL_Texture* background;
	SDL_Texture* yesButton;
	SDL_Texture* noButton;

	int buttonH;
	int buttonW;
};