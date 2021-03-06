#pragma once

#include <math.h>
#include "Entity.h"

class Ball : public Entity {
public:
    //Initilizes texture and varaibles
    Ball(SDL_Renderer* renderer);

    //Delete's object's resources
    ~Ball();

    //Updates direction of ball's movement
    void Update(float delta);

    //Renders ball to screen
    void Render(float delta);

    //Sets direction of ball
    void SetDirection(float dirX, float dirY);

    //Increases speed of ball
    void IncreaseSpeed();

    //Resets speed of ball to original speed
    void ResetSpeed();

    //Speed of ball
    float speed;

    //Direction of ball's x and y coordinates
    float dirX, dirY;

private:
    //Texture used for rendering ball image
    SDL_Texture* texture;
};