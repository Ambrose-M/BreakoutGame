#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <stdio.h>

#include "Board.h"
#include "Paddle.h"
#include "Ball.h"
#include "MainMenu.h"
#include "GameOverMenu.h"
#include "Collision.h"
#include "Lives.h"
#include "LevelCounter.h"
#include <string>

using namespace std;

class Game {
public:
    //Sets window and renderer to 0
    Game();

    ~Game();

    //Initilizes game window, renderer, texture and variables
    bool Init();

    //Runs game
    void Run();

    //Displays main menu to screen
    bool DisplayMainMenu(); 

    //Displays game over menu
    string DisplayGameOverMenu();

private:
    //Game window
    SDL_Window* window;

    //Renders textures
    SDL_Renderer* renderer;

    //Textures for rendering
    SDL_Texture* texture;

    //For timing
    unsigned int lasttick, fpstick, fps, framecount;

    //Entities
    Board* board;
    Paddle* paddle;
    Ball* ball;
    Lives* lives;
    LevelCounter* levelCounter;

    //True if ball is stuck to paddle
    bool paddlestick; 

    //Cleans object's resources
    void Clean();

    //Updates entities
    void Update(float delta);

    //Renders entities
    void Render(float delta);

    //Creates new game
    void NewGame();

    //Brings game to next level
    void NextLevel();

    //Sets paddle x coordinate
    void SetPaddleX(float x);

    //Check for board collisions
    void CheckBoardCollisions();
};