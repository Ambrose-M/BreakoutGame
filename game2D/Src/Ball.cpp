#include "Ball.h"

Ball::Ball(SDL_Renderer* renderer) : Entity(renderer) {

    //Initilize texture for ball
    SDL_Surface* surface = IMG_Load("Images/ball.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //Initilize coordinates on board
    x = 0;
    y = 0;

    //Initilize width and height of ball
    width = 24;
    height = 24;

    //Speed of ball in pixels per second
    speed = 550;

    //Set direction of the ball
    SetDirection(1, 1);
}

Ball::~Ball() {
    SDL_DestroyTexture(texture);
}

void Ball::Update(float delta) {
    //Update direction of ball on x axis
    x += dirX * delta;

    //Update direction of ball on y axis
    y += dirY * delta;
}

void Ball::Render(float delta) {
    //Set destination rectangle of ball
    SDL_Rect rect;
    rect.x = (int)(x + 0.5f);
    rect.y = (int)(y + 0.5f);
    rect.w = width;
    rect.h = height;

    //Render copy of ball
    SDL_RenderCopy(renderer, texture, 0, &rect);
}

void Ball::SetDirection(float dirX, float dirY) {
    // Normalize the direction vector and multiply by speed
    float length = sqrt(dirX * dirX + dirY * dirY);

    //Set direction on x axis
    this->dirX = speed * (dirX / length);

    //Set direction on y axis
    this->dirY = speed * (dirY / length);
}

void Ball::IncreaseSpeed()
{
    speed = speed + 100;
}

void Ball::ResetSpeed()
{
    speed = 550;
}