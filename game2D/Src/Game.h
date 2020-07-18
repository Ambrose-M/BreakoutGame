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

#define FPS_DELAY 500

class Game {
public:
    Game();
    ~Game();

    bool Init();
    void Run();

    bool DisplayMainMenu(); 
    string DisplayGameOverMenu();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* texture;

    //For timing
    unsigned int lasttick, fpstick, fps, framecount;

    ////For testing
    //float testx, testy;

    //Entities
    Board* board;
    Paddle* paddle;
    Ball* ball;
    Lives* lives;
    LevelCounter* levelCounter;

    bool paddlestick; //true if ball is stuck to paddle

    void Clean();
    void Update(float delta);
    void Render(float delta);

    void NewGame();
    void NextLevel();

    void SetPaddleX(float x);

    void CheckBoardCollisions();
};