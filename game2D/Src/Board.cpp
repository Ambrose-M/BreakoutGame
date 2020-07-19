#include "Board.h"

Board::Board(SDL_Renderer* renderer) : Entity(renderer) {
    //Initilize brick texture
    SDL_Surface* surface = IMG_Load("Images/bricks.png");
    bricktexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //Initilize board sides texture
    surface = IMG_Load("Images/sides.png");
    sidetexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //For setting random colored bricks on board
    srand(time(0));

    //brick x coordinate
    x = 16;

    //brick y coordinate
    y = 0;

    //Board width
    width = 768;

    //Board height
    height = 600;

    //Offset of bricks on x and y axis
    brickoffsetX = 0;
    brickoffsetY = 16;
}

Board::~Board() {
    //Destory all textures
    SDL_DestroyTexture(bricktexture);
    SDL_DestroyTexture(sidetexture);
}


void Board::Render(float delta) {
    // Render bricks
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            Brick brick = bricks[i][j];

            // Check if the brick exists
            if (!brick.state)
                continue;

            //Create source rectangle for bricks
            SDL_Rect srcrect;
            srcrect.x = (brick.type % 2) * BOARD_BRWIDTH;
            srcrect.y = (brick.type / 2) * BOARD_BRHEIGHT;
            srcrect.w = BOARD_BRWIDTH;
            srcrect.h = BOARD_BRHEIGHT;

            //Create destination rectange for bricks
            SDL_Rect destRect;
            destRect.x = brickoffsetX + x + i * BOARD_BRWIDTH;
            destRect.y = brickoffsetY + y + j * BOARD_BRHEIGHT;
            destRect.w = BOARD_BRWIDTH;
            destRect.h = BOARD_BRHEIGHT;

            //Render brick
            SDL_RenderCopy(renderer, bricktexture, &srcrect, &destRect);
        }
    }

    //Render left side texture
    SDL_Rect destRect = { 0, 0, 16, 600 };
    SDL_RenderCopy(renderer, sidetexture, 0, &destRect);

    //Render right side texture
    destRect = { 800 - 16, 0, 16, 600 };
    SDL_RenderCopy(renderer, sidetexture, 0, &destRect);
}

void Board::CreateLevel() {
    //Traverse through 2D array
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            Brick brick;

            //Set random brick color
            brick.type = rand() % 4;   

            //Set brick state to present
            brick.state = true;         

            //Assign brick to 2D array location
            bricks[i][j] = brick;
        }
    }
}

int Board::GetBrickCount() {
    int brickcount = 0;

    //Traverse through the 2D array of bricks
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            Brick brick = this->bricks[i][j];

            //If brick exists
            if (brick.state) {
                //Increase brick count by 1
                brickcount++;
            }
        }
    }

    //Return amount of bricks currently on board
    return brickcount;
}
