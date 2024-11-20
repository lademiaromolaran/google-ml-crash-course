/*
* Author: Aidan Stout
* File Name: config.h
* File Description: This file contains the applications global variables,
                    Settings struct, and custom errors.
* Date Created: 11/12/2024
* Date Last Modified: 11/19/2024
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <exception>
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
const color C_BLACK(0,0,0);
const color C_WHITE(255,255,255);


struct Settings
{
    int boardSize;
    bool isPvAI;
    bool isPlayerWhite;
    double komi;
    color validHighlight;
    color invalidHighlight;
    color whiteStone;
    color blackStone;

    Settings(): boardSize(BOARD_SIZE),
                isPvAI(IS_PvAI),
                isPlayerWhite(IS_PLAYER_WHITE),
                komi(KOMI),
                validHighlight(VALID_HIGHLIGHT),
                invalidHighlight(INVALID_HIGHLIGHT),
                whiteStone(C_WHITE),
                blackStone(C_BLACK){}
};


//Errors
class GoGameException: public exception
{
private:
    string errorMessage;
public:
    GoGameException(const string& message): errorMessage(message){}

    const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
};



#endif
