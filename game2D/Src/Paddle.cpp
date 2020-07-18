#include "Paddle.h"

Paddle::Paddle(SDL_Renderer* renderer) : Entity(renderer) {
    //Initilize paddle texture
    SDL_Surface* surface = IMG_Load("Images/paddle.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //Paddle width
    width = 128;

    //Paddle height
    height = 32;

    //Paddle location on y axis
    y = 560;
}

Paddle::~Paddle() {
    SDL_DestroyTexture(texture);
}

void Paddle::Render(float delta) {
    //Set destination rectangle for paddle
    SDL_Rect destRect;
    destRect.x = (int)(x + 0.5f);
    destRect.y = (int)(y + 0.5f);
    destRect.w = width;
    destRect.h = height;

    //Render paddle
    SDL_RenderCopy(renderer, texture, 0, &destRect);
}


void Paddle::StickBall(Ball* ball) 
{
    //Sets ball to middle of paddle on x axis
    ball->x = this->x + this->width / 2 - ball->width / 2;

    //Sets ball to height of paddle
    ball->y = this->y - ball->height;
}