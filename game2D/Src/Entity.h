#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Entity {
public:
    //Initilizes entity's variables and renderer
    Entity(SDL_Renderer* renderer);
    virtual ~Entity();

    //Entity's x coordinate, y coordinate, width and height
    float x, y, width, height;

    //Update entity
    virtual void Update(float delta);

    //Render entity to screen
    virtual void Render(float delta);

    //Checks for collision with other entity
    bool Collides(Entity* other);

protected:
    //Used to render object to screen
    SDL_Renderer* renderer;

};