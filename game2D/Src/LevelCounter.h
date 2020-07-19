#pragma once
#include "Entity.h"
#include "SDL_ttf.h"
#include <string>

using namespace std;

class LevelCounter : public Entity
{
public:
	//Initilize texture, font, and variables
	LevelCounter(SDL_Renderer* renderer);

	//Delete object's resources
	~LevelCounter();

	//Render to screen
	void Render();

	//Increase level by 1
	void LevelUp();

	//Reset level to 1
	void ResetLevel();

	//Update text displayed on screen
	void UpdateText();

private:
	//Text texture
	SDL_Texture* texture;

	//Text surface
	SDL_Surface* surface;

	//Font used
	TTF_Font* font;

	//Text height
	int textH;

	//Text width
	int textW;

	//Level the player is currently one
	int currentLevel;

	//String displayed on screen
	string levelStr;
};