#pragma once
#include "Entity.h"

class Lives : public Entity {

public:
	Lives(SDL_Renderer* renderer);
	~Lives();

	void Render();

	void LoseLife();

	void ResetLives();

	int GetLivesLeft();

	int livesLeft;

private:
	SDL_Texture* texture;
};