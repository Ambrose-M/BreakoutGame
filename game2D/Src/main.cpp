#pragma once
#include "Game.h"

int main(int argc, char* argv[]) {

    // Create new game
    Game* game = new Game();

    // Initialize game
    if (game->Init()) {

        //Returns true if close window is clicked and false if start button is clicked
        bool exitGame = game->DisplayMainMenu();

        //If start button is pressed
        if (!exitGame) {
            //Run game
            game->Run();
        }

        //If close window is clicked, exit without running game.
    }

    delete game;

    return 0;
}