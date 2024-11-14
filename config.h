/*
* Author: Aidan Stout
* File Name: config.h
* File Description: This file contains the applications global variables.
* Date Created: 11/12/2024
* Date Last Modified: 11/13/2024
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "SDL_Plotter.h"

const int SCREEN_X = 750;
const int SCREEN_Y = 750;

enum StoneType {ST_BLACK, ST_WHITE, ST_EMPTY};
enum Direction {UP, DOWN, LEFT, RIGHT};
enum Stage {S_NONE, S_PLAY, S_OPTIONS, S_QUIT};

const color BOARD(220,179,92);



//Default Settings
const int BOARD_SIZE       = 19;
const bool IS_PvAI         = false;
const bool IS_PLAYER_WHITE = false;
const double KOMI          = 0.0;
const color VALID_HIGHLIGHT(255, 255, 0);
const color INVALID_HIGHLIGHT(255, 0, 0);


#endif
