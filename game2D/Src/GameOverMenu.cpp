#include "GameOverMenu.h"

GameOverMenu::GameOverMenu(SDL_Renderer* renderer) : Entity(renderer)
{
    //Initilizing background image
    SDL_Surface* surface = IMG_Load("Images/gameOverBackground.png");
    background = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //Initilizing yes button image
    surface = IMG_Load("Images/yesButton.png");
    yesButton = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //Initilizing no button image
    surface = IMG_Load("Images/noButton.png");
    noButton = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    //Button height
    buttonH = 50;

    //Button width
    buttonW = 200;
}

GameOverMenu::~GameOverMenu()
{
    //Destroy all textures
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(yesButton);
    SDL_DestroyTexture(noButton);
}

void GameOverMenu::Render()
{
    //Render background
    SDL_RenderCopy(renderer, background, NULL, NULL);

    //Yes button location and size
    SDL_Rect destRect = { 165, 410, buttonW, buttonH };

    //Render yes button
    SDL_RenderCopy(renderer, yesButton, NULL, &destRect);

    //No button location and size
    destRect = { 415, 410, buttonW, buttonH };

    //Render no button
    SDL_RenderCopy(renderer, noButton, NULL, &destRect);
}

string GameOverMenu::buttonPressed(SDL_Event* e)
{
    //String that holds which button is clicked
    string playAgain = "";

    //If mouse event happened
    if (e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        //Check if mouse is on yes button set playAgain to yes
        if (x >= 165 && x <= 165+buttonW 
            && y >= 410 && y <= 410+buttonH) {
            playAgain = "yes";
        }

        //Check if mouse is on no button set playAgain to no
        if (x >= 415 && x <= 415 + buttonW
            && y >= 410 && y <= 410 + buttonH) {
            playAgain = "no";
        }
    }

    //Return string indicating which button was clicked
    return playAgain;
}

string GameOverMenu::Run()
{
    //Hold yes or no depending on whether player clicks to play again or not
    string playAgain = "";

    // Main loop, while start button is not clicked.
    while (1) {
        // Handle events
        SDL_Event e;

        if (SDL_PollEvent(&e)) {
            //If user closes main window exit the game and set playAgain to 'no'
            if (e.type == SDL_QUIT) {
                playAgain = "no";
                break;
            }
        }

        SDL_RenderClear(renderer);

        //Render main menu
        this->Render();

        SDL_RenderPresent(renderer);

        //Check if start button is pressed
       playAgain = this->buttonPressed(&e);

       //If either button is clicked break from main loop and set playAgain string
       if (playAgain.compare("yes") == 0)
           break;
       else if (playAgain.compare("no") == 0)
           break;
    }

    //Return which button was pressed as a string.
    return playAgain;
}