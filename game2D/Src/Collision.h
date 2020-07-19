#pragma once

#include "Ball.h"
#include "Board.h"
#include "Paddle.h"

class Collision
{
public:
    //Returns reflection of ball off of paddle
    float GetReflection(Paddle* paddle, float hitX);

    //Checks for paddle collisions
    void CheckPaddleCollisions(Paddle* paddle, Ball* ball);

    //Checks for brick collisions
    void CheckBrickCollisions(Board* board, Ball* ball);

    //How the ball responds to brick collisions
    void BallBrickResponse(Ball* ball, int dirIndex);
};