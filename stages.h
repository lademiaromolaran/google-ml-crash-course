/*
* Author: Aidan Stout
* File Name: stages.h
* File Description: This file contains functions for the
                    different stages of the application.
* Date Created: 11/12/2024
* Date Last Modified: 11/19/2024
*/

#ifndef STAGES_H
#define STAGES_H

#include "SDL_Plotter.h"
#include "Point.h"
#include "match_helpers.h"
#include "helpers.h"
#include "config.h"
#include "Player.h"

/*
*   @function: mainMenu()
*   @description: First screen shown. Allows the user to go to different
                  stages of application such as playMatch or options
*   @pre-condition: None
*   @post-condition: The next stage is defined and returned
*   @return: copy of Stage type
*/
Stage mainMenu(SDL_Plotter& g); //WIP

/*
*   @function: options()
*   @description: Allows the user to set the different
                  options for the match.
*   @pre-condition: None
*   @post-condition: Settings updated with new options
*   @return: nothing
*/
void options(SDL_Plotter& g, Settings& s); //WIP

/*
*   @function: playMatch()
*   @description: Runs the match and handles all aspects of the game
                  such as the board, stone placement, and scoring.
*   @pre-condition: None
*   @post-condition: Plotter updated
*   @return: nothing
*/
void playMatch(SDL_Plotter& g, Settings& s); //WIP

#endif
