#include "Game.h"

//Object for checking collisions
Collision* collision = new Collision();

Game::Game() {
    window = 0;
    renderer = 0;
}

Game::~Game() {
}

bool Game::Init() {
    SDL_Init(SDL_INIT_VIDEO);

    //Initilize SDL_ttf for text rendering
    if (TTF_Init() == -1) {
        //If problem initilizing print error message
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

    //Create window
    window = SDL_CreateWindow("Breakout Game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 650, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    //If window is not created print error message
    if (!window) {
        std::cout << "Error creating window:" << SDL_GetError() << std::endl;
        return false;
    }

    // Create renderer. Includes Vsync to cap FPS at around 60.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //If renderer is not created print error message
    if (!renderer) {
        std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize surface and texture
    SDL_Surface* surface = IMG_Load("test.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // Initialize timing
    lasttick = SDL_GetTicks();
    fpstick = lasttick;
    fps = 0;
    framecount = 0;

    return true;
}


bool Game::DisplayMainMenu() {

    MainMenu mainMenu(renderer);

    //Runs main menu 
    bool exitGame = mainMenu.Run();

    return exitGame;
}

string Game::DisplayGameOverMenu()
{
    string playAgain = "";

    GameOverMenu gameoverMenu(renderer);

    playAgain = gameoverMenu.Run();

    return playAgain;
}

void Game::Run() {

    //Initilize entities
    board = new Board(renderer);
    paddle = new Paddle(renderer);
    ball = new Ball(renderer);
    lives = new Lives(renderer);
    levelCounter = new LevelCounter(renderer);

    //Create new game
    NewGame();

    // Main game loop
    while (1) {
        //Create event handler
        SDL_Event e;

        if (SDL_PollEvent(&e)) {
            //If user clicks close window break out of main loop
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        // Set delta for updating and rendering entities
        float delta = 0.017;

        // Update entities
        Update(delta);

        //Render entities
        Render(delta);

        //For checking if user clicks exit window while in game over menu
        bool exitGame = false;

        //If player has no more lives the game is over
        if (lives->GetLivesLeft() == 0)
        {

            bool displayGameOver = true;

            //Display game over screen that asks if they want to play again or quit
            while (displayGameOver) {
                //Function returns a string when user clicks on an option
                string playAgain = DisplayGameOverMenu();

                //If player clicks yes to play again
                if (playAgain.compare("yes") == 0)
                {
                    //Restart game
                    NewGame();

                    //Exit loop
                    displayGameOver = false;
                }
                //If player clicks no or the close window
                else if (playAgain.compare("no") == 0)
                {
                    //Set to true to exit the main loop.
                    exitGame = true;

                    //Exit current loop
                    displayGameOver = false;
                }
            }
        }

        //If play does not want to play again, exit the main loop.
        if (exitGame)
            break;
    }

    //deleting entities
    delete board;
    delete paddle;
    delete ball;
    delete lives;
    delete levelCounter;

    //Cleaning resources
    Clean();

    //Exiting external libraries
    TTF_Quit();
    SDL_Quit();
}

void Game::NewGame() {
    //Create level
    board->CreateLevel();

    //Reset paddle
    paddlestick = true;
    paddle->StickBall(ball);

    //Reset speed of ball
    ball->ResetSpeed();

    //Reset amount of lives to full
    lives->ResetLives();

    //Reset level counter
    levelCounter->ResetLevel();
}

//Ball speed is increased in each level
void Game::NextLevel() {
    //Create level
    board->CreateLevel();

    //Reset paddle
    paddlestick = true;
    paddle->StickBall(ball);

    ball->IncreaseSpeed();

    levelCounter->LevelUp();
}

//Render entities to screen
void Game::Render(float delta) {
    SDL_RenderClear(renderer);

    board->Render(delta);
    paddle->Render(delta);
    ball->Render(delta);
    lives->Render();
    levelCounter->Render();

    SDL_RenderPresent(renderer);
}

void Game::Update(float delta) {
    // Mouse input
    int mouseX, mouseY;
    Uint8 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

    //Set paddle coordinate on x axis
    SetPaddleX(mouseX - paddle->width / 2.0f);

    //If mouse is moving and clicked 
    if (mouseState & SDL_BUTTON(1)) {

        //If ball is stuck to paddle
        if (paddlestick) {

            //unstick the ball
            paddlestick = false;

            //Send it in this direction
            ball->SetDirection(1, -1);
        }
    }

    //If mouse has not been clicked
    if (paddlestick) {

        //Stick the ball to the paddle
        paddle->StickBall(ball);
    }

    //Check collisions
    CheckBoardCollisions();
    collision->CheckPaddleCollisions(paddle, ball);
    collision->CheckBrickCollisions(board, ball);

    //If all bricks are broken move to the next level
    if (board->GetBrickCount() == 0) {
        NextLevel();
    }

    //If ball is not stuck to paddle update its location
    if (!paddlestick) {
        ball->Update(delta);
    }
}

void Game::SetPaddleX(float x) {
    float newx;

    if (x < board->x) {
        // Upper bound
        newx = board->x;
    }
    else if (x + paddle->width > board->x + board->width) {
        // Lower bound
        newx = board->x + board->width - paddle->width;
    }
    else {
        newx = x;
    }
    paddle->x = newx;
}

void Game::CheckBoardCollisions() {
    // Top collisions
    if (ball->y < board->y) {
        // Keep the ball within the board and reflect the y-direction
        ball->y = board->y;
        ball->dirY *= -1;
    }
    //Bottom collisions. Ball is lost.
    else if (ball->y + ball->height > board->y + board->height) {
        //Reseting paddle. Sticking ball to paddle.
        paddlestick = true; //so ball will stick to paddle
        paddle->StickBall(ball);

        //Lose one life
        lives->LoseLife();
    }

    // Left collisions
    if (ball->x <= board->x) {
        // Keep the ball within the board and reflect the x-direction
        ball->x = board->x;
        ball->dirX *= -1;
    }
    //Right collisions
    else if (ball->x + ball->width >= board->x + board->width) {
        // Keep the ball within the board and reflect the x-direction
        ball->x = board->x + board->width - ball->width;
        ball->dirX *= -1;
    }
}

//Delete resources
void Game::Clean() {
    delete collision;

    SDL_DestroyTexture(texture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}