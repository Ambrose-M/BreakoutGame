#pragma once
#include "Entity.h"

class Lives : public Entity {

public:
	//Initilizes texture and variables
	Lives(SDL_Renderer* renderer);

	//Delete object's resources
	~Lives();

	//Render hearts to screen
	void Render();

	//Reduce lives by 1
	void LoseLife();

	//Reset lives to 3
	void ResetLives();

	//Return number of lives left
	int GetLivesLeft();

	//Number of lives the player currently has
	int livesLeft;

private:
	//Heart texture
	SDL_Texture* texture;
};