#include "LevelCounter.h"
#include <iostream>

LevelCounter::LevelCounter(SDL_Renderer* renderer) : Entity(renderer)
{
	//Starting level
	currentLevel = 1;

	//Text width
	textW = 200;

	//Text height
	textH = 37;

	//Setting font
	font = TTF_OpenFont("Fonts/blocksFont.ttf", 25);

	//Setting color to white
	SDL_Color color = { 255, 255, 255 };

	levelStr = "level " + to_string(currentLevel);

	//Creating text surface
	//SDL_Surface* surface = TTF_RenderText_Solid(font, levelStr.c_str(), color);

	surface = TTF_RenderText_Solid(font,
		levelStr.c_str(), color);

	//Initilizing texture from surface
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

}

LevelCounter::~LevelCounter()
{
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	font = NULL;
}

void LevelCounter::Render()
{
	//Location and size of text display
	SDL_Rect destRect = { 450, 610, textW, textH };

	//Render text texture
	SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

void LevelCounter::LevelUp()
{
	currentLevel++;

	UpdateText();
}

void LevelCounter::ResetLevel()
{
	currentLevel = 1;

	UpdateText();
}

//Updating text with current level
void LevelCounter::UpdateText()
{
	//Setting color to white
	SDL_Color color = { 255, 255, 255 };

	//String that will be displayed on screen
	levelStr = "level " + to_string(currentLevel);

	//Create surface with string
	SDL_Surface* temp = TTF_RenderText_Solid(font, levelStr.c_str(), color);

	//Initilizing texture from surface
	texture = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);

}