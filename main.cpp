/*
* Authors: __Group 5__
           Aidan Stout,
           Lademi Aromolaran,
           Noon Salih,
           Nykayla Steadmon
           Ryan Limprecht
* Assignment Title: Go Game
* Assignment Description: Write an application that runs the game of Go
* Due Date: 12/08/2024
* Date Created: 11/12/2024
* Date Last Modified: 11/19/2024
*/


#include <iostream>
#include <string>
#include "SDL_Plotter.h"
#include "config.h"
#include "stages.h"
#include "helpers.h"
#include "Scoreboard.h"

using namespace std;

int main() {
    SDL_Plotter g(SCREEN_X, SCREEN_Y);
    Stage stage;
    Settings settings;

    point scoreboardPosition = { SCREEN_X - 250, 10 };
    int scoreboardWidth = 250;
    int scoreboardHeight = 100;

    Player blackPlayer(ST_BLACK);
    Player whitePlayer(ST_WHITE);

    blackPlayer.setName("Black Player");
    whitePlayer.setName("White Player");

    Scoreboard scoreboard(g, blackPlayer, whitePlayer, scoreboardPosition, scoreboardWidth, scoreboardHeight);

    try {
        do {
            stage = mainMenu(g);

            if (stage == S_OPTIONS) {
                options(g, settings);
            }

            if (stage == S_PLAY) {
                playMatch(g, settings);
                scoreboard.render(scoreboardPosition.x, scoreboardPosition.y);
            }

        } while (stage != S_QUIT);
    }
    catch (GoGameException& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (...) {
        cout << "Error!!!" << endl;
    }

    return 0;
}
