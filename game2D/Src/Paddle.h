#pragma once
#include "Entity.h"
#include "Ball.h"

class Paddle : public Entity {
public:
    //Initilizes paddle texture and variables 
    Paddle(SDL_Renderer* renderer);

    //Deletes paddle's resources
    ~Paddle();

    //Renders paddle to screen
    void Render(float delta);

    //Sticks ball to paddle
    void StickBall(Ball* ball);

private:
    //Paddle texture
    SDL_Texture* texture;
};