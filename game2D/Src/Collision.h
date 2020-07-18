#pragma once

#include "Ball.h"
#include "Board.h"
#include "Paddle.h"

class Collision
{
public:
    float GetReflection(Paddle* paddle, float hitX);

    void CheckPaddleCollisions(Paddle* paddle, Ball* ball);

    void CheckBrickCollisions(Board* board, Ball* ball);

    void BallBrickResponse(Ball* ball, int dirIndex);
};