#pragma once
#include "Entity.h"
#include "SDL_ttf.h"
#include <string>

using namespace std;

class LevelCounter : public Entity
{
public:
	LevelCounter(SDL_Renderer* renderer);
	~LevelCounter();

	void Render();

	void LevelUp();

	void ResetLevel();

	void UpdateText();

private:
	SDL_Texture* texture;
	SDL_Surface* surface;
	TTF_Font* font;

	int textH;
	int textW;

	int currentLevel;

	string levelStr;
};