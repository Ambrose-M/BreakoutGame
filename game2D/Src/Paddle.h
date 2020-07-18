#pragma once
#include "Entity.h"
#include "Ball.h"

class Paddle : public Entity {
public:
    Paddle(SDL_Renderer* renderer);
    ~Paddle();

    void Render(float delta);

    void StickBall(Ball* ball);

private:
    SDL_Texture* texture;
};