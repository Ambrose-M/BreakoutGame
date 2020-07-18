#pragma once

#include <stdlib.h>
#include <time.h>
#include "Entity.h"

// Dimensions of board and bricks
#define BOARD_WIDTH 12
#define BOARD_HEIGHT 11
#define BOARD_BRWIDTH 64
#define BOARD_BRHEIGHT 24

class Brick {
public:
    int type;
    bool state;
};

class Board : public Entity {
public:
    Board(SDL_Renderer* renderer);
    ~Board();

    void Render(float delta);
    void CreateLevel();
    
    int GetBrickCount();

    float brickoffsetX, brickoffsetY;

    // 2D array of bricks
    Brick bricks[BOARD_WIDTH][BOARD_HEIGHT];

private:
    SDL_Texture* bricktexture;
    SDL_Texture* sidetexture;
};
