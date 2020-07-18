#include "MainMenu.h"

MainMenu::MainMenu(SDL_Renderer* renderer) : Entity(renderer)
{
    //Initilizing background image
    SDL_Surface* surface = IMG_Load("Images/menuBackground.png");
    background = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //Initilizing start button image
    surface = IMG_Load("Images/playButton.png");
    startButton = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //Button height
    buttonH = 100;

    //Button width
    buttonW = 400;
}


MainMenu::~MainMenu()
{
	SDL_DestroyTexture(background);
    SDL_DestroyTexture(startButton);
}

bool MainMenu::startButtonPressed(SDL_Event* e)
{
    bool pressStart = false;

    //If mouse event happened
    if (e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        //Check if mouse is on start button
        if (x >= 200 && x <= 600 && y >= 50 && y <= 150) {
            pressStart = true;
        }
    }

    return pressStart;
}

void MainMenu::Render() {
    //Rendering background
    SDL_RenderCopy(renderer, background, NULL, NULL);

    //Start button location and size
    SDL_Rect destRect = { 200, 50, buttonW, buttonH };

    //Rendering start button
    SDL_RenderCopy(renderer, startButton, NULL, &destRect);
}

bool MainMenu::Run()
{
    bool exitGame = false;
    bool startPressed = false;

    // Main loop, while start is not clicked.
    while (!startPressed) {

        // Handle events
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                exitGame = true;
                break;
            }
        }

        SDL_RenderClear(renderer);

        //Render main menu
        this->Render();

        SDL_RenderPresent(renderer);

        //Check if start button is pressed. If true exit loop.
        startPressed = this->startButtonPressed(&e);
    }

    //Returns true if start button is pressed and false if close window is pressed
    return exitGame;
}