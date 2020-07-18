#pragma once

#include <math.h>
#include "Entity.h"

class Ball : public Entity {
public:
    Ball(SDL_Renderer* renderer);
    ~Ball();

    void Update(float delta);
    void Render(float delta);

    void SetDirection(float dirX, float dirY);

    void IncreaseSpeed();
    void ResetSpeed();

    float speed;
    float dirX, dirY;

private:
    SDL_Texture* texture;
};