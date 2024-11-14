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
* Date Last Modified: 11/13/2024
*/

#include <iostream>
#include "SDL_Plotter.h"
#include "config.h"
#include "stages.h"
#include "helpers.h"

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(SCREEN_X, SCREEN_Y);
    Stage stage;

    createSettingsFile();

    try
    {
        do
        {
            stage = mainMenu(g);

            if(stage == S_OPTIONS)
            {
                options(g);
            }

            if(stage == S_PLAY)
            {
                playMatch(g);
            }
        } while(stage != S_QUIT);
    }
    catch(...)
    {
        cout << "Error!!!" << endl;
    }

    return 0;
}
