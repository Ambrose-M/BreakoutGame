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
    //Brick color
    int type;

    //True if brick exist, false if not
    bool state;
};

class Board : public Entity {
public:
    //Initilizes board and brick's textures and varaibles
    Board(SDL_Renderer* renderer);

    //Deletes board's resources
    ~Board();

    //Renders board and bricks to screen
    void Render(float delta);

    //Creates full set of bricks
    void CreateLevel();
    
    //Return number of bricks on the board
    int GetBrickCount();

    //The x and y offset for bricks
    float brickoffsetX, brickoffsetY;

    // 2D array of bricks
    Brick bricks[BOARD_WIDTH][BOARD_HEIGHT];

private:
    //Brick texture
    SDL_Texture* bricktexture;

    //Side of board texture
    SDL_Texture* sidetexture;
};
