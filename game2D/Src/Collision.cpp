#include "Collision.h"

//Reflection of the ball off the paddle
float Collision::GetReflection(Paddle* paddle, float hitX) {

    // Make sure the ball hit is within the width of the paddle
    if (hitX < 0) {
        hitX = 0;
    }
    else if (hitX > paddle->width) {
        hitX = paddle->width;
    }

    //Ball is reflected left if it hits the left of paddle's center
    //Ball is reflected right if it hits the right of paddle's center
    hitX -= paddle->width / 2.0f;

    // Scale the reflection by 2.0f
    return 2.0f * (hitX / (paddle->width / 2.0f));
}


void Collision::CheckPaddleCollisions(Paddle* paddle, Ball* ball) {
    // Get center x coordinate of the ball
    float ballcenterx = ball->x + ball->width / 2.0f;

    //Check for paddle collision
    if (ball->Collides(paddle)) {
        ball->y = paddle->y - ball->height;
        float forReflection = (ballcenterx - paddle->x);
        ball->SetDirection(GetReflection(paddle, forReflection), -1);
    }
}


void Collision::BallBrickResponse(Ball* ball, int dirIndex) {
    // dirIndex 0: Left, 1: Top, 2: Right, 3: Bottom

    // Direction factors
    int mulX = 1;
    int mulY = 1;

    // Ball is moving in the positive x direction
    if (ball->dirX > 0) {
        
        // Ball is moving in the positive y direction
        if (ball->dirY > 0) {
            
            //If moving left or to the bottom
            if (dirIndex == 0 || dirIndex == 3) {
                mulX = -1;
            }
            else {
                mulY = -1;
            }
        }
        // Ball is moving in the negative y direction
        else if (ball->dirY < 0) {

            //If moving left or toward the top
            if (dirIndex == 0 || dirIndex == 1) {
                mulX = -1;
            }
            else {
                mulY = -1;
            }
        }
    }
    //If ball is moving in the negative x direction
    else if (ball->dirX < 0) {

        //If ball is moving in the positive y direction
        if (ball->dirY > 0) {

            //If moving to the right or bottom
            if (dirIndex == 2 || dirIndex == 3) {
                mulX = -1;
            }
            else {
                mulY = -1;
            }
        }
        //If ball is moving in the negative y direction
        else if (ball->dirY < 0) {
            
            //If moving to the top or right
            if (dirIndex == 1 || dirIndex == 2) {
                mulX = -1;
            }
            else {
                mulY = -1;
            }
        }
    }

    // Set new direction of ball by multiplying the old direction with the direction factors
    ball->SetDirection(mulX * ball->dirX, mulY * ball->dirY);
}


void Collision::CheckBrickCollisions(Board* board, Ball* ball) {

    //Traverse 2D array of bricks to check for collisions
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            Brick brick = board->bricks[i][j];

            // Check that brick exists
            if (brick.state) {
                // Brick x and y coordinates
                float brickx = board->brickoffsetX + board->x + i * BOARD_BRWIDTH;
                float bricky = board->brickoffsetY + board->y + j * BOARD_BRHEIGHT;

                // Center of the ball x and y coordinates
                float ballcenterx = ball->x + 0.5f * ball->width;
                float ballcentery = ball->y + 0.5f * ball->height;

                // Center of the brick x and y coordinates
                float brickcenterx = brickx + 0.5f * BOARD_BRWIDTH;
                float brickcentery = bricky + 0.5f * BOARD_BRHEIGHT;

                //If collision detected
                if (ball->x <= brickx + BOARD_BRWIDTH && ball->x + ball->width >= brickx && ball->y <= bricky + BOARD_BRHEIGHT && ball->y + ball->height >= bricky) {
                    // Remove the brick
                    board->bricks[i][j].state = false;

                    // Calculate y size
                    float ymin = 0;
                    if (bricky > ball->y) {
                        ymin = bricky;
                    }
                    else {
                        ymin = ball->y;
                    }

                    float ymax = 0;
                    if (bricky + BOARD_BRHEIGHT < ball->y + ball->height) {
                        ymax = bricky + BOARD_BRHEIGHT;
                    }
                    else {
                        ymax = ball->y + ball->height;
                    }

                    float ysize = ymax - ymin;

                    // Calculate x size
                    float xmin = 0;
                    if (brickx > ball->x) {
                        xmin = brickx;
                    }
                    else {
                        xmin = ball->x;
                    }

                    float xmax = 0;
                    if (brickx + BOARD_BRWIDTH < ball->x + ball->width) {
                        xmax = brickx + BOARD_BRWIDTH;
                    }
                    else {
                        xmax = ball->x + ball->width;
                    }

                    float xsize = xmax - xmin;

                    // Set collision response
                    if (xsize > ysize) {

                        //If it hits the bottom
                        if (ballcentery > brickcentery) {
                            // Move out of collision
                            ball->y += ysize + 0.01f; 
                            BallBrickResponse(ball, 3);
                        }
                        //If it hits the top
                        else {
                            // Move out of collision
                            ball->y -= ysize + 0.01f;
                            BallBrickResponse(ball, 1);
                        }
                    }
                    else {
                        //If it hits the left
                        if (ballcenterx < brickcenterx) {
                            // Move out of collision
                            ball->x -= xsize + 0.01f; 
                            BallBrickResponse(ball, 0);
                        }
                        //If it hits the right
                        else {
                            // Move out of collision
                            ball->x += xsize + 0.01f;
                            BallBrickResponse(ball, 2);
                        }
                    }
                    return;
                }
            }
        }
    }
}