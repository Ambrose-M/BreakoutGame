#include "Lives.h"

Lives::Lives(SDL_Renderer* renderer) :Entity(renderer)
{
    //Initilize heart texture for lives
    SDL_Surface* surface = IMG_Load("Images/heart.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //Initilize coordinates on board
    x = 0;
    y = 0;

    //Initilize width and height of hearts
    width = 40;
    height = 40;

    //Max amount of lives
    livesLeft = 3;
}

Lives::~Lives()
{
    SDL_DestroyTexture(texture);
}

void Lives::Render()
{
    //Destination rectangle for heart images
    SDL_Rect destRect = { 200, 605, width, height };

    //Render each heart 40 pixels away from the last on the x axis
    for (int i = 0; i < livesLeft; i++)
    {
        SDL_RenderCopy(renderer, texture, 0, &destRect);
        destRect.x = destRect.x + 40;
    }
}

void Lives::LoseLife()
{
    livesLeft = livesLeft - 1;
}

int Lives::GetLivesLeft()
{
    return livesLeft;
}

void Lives::ResetLives()
{
    livesLeft = 3;
}