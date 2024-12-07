/*
* Author: Aidan Stout, Ryan Limprecht
* File Name: match_helpers.h
* File Description: This file contains functions that help
                    the playMatch stage specifically in stages.h
* Date Created: 11/13/2024
* Date Last Modified: 12/7/2024
*/

#ifndef MATCH_HELPERS_H
#define MATCH_HELPERS_H

#include "SDL_Plotter.h"
#include "Point.h"
#include "helpers.h"
#include "Player.h"

struct Coordinate
{
    int row;
    int col;
    Coordinate(int row=0, int col=0): row(row), col(col){}
};

struct Board
{
    Point** board;
    point* offset;
    int* pointLength;
    Stone* setterStone;
    Player* pB;
    Player* pW;
    int* boardSize;

    Board(): board(nullptr), offset(nullptr), pointLength(nullptr),
             setterStone(nullptr), pB(nullptr), pW(nullptr),
             boardSize(nullptr){}
};

/*
*   @function: drawBoard()
*   @description: Plots the entire Go board
*   @pre-condition: None
*   @post-condition: Plotter updated with board
*   @return: nothing
*/
void drawBoard(SDL_Plotter& g, Board& b);


/*
*   @function: isPlaceable()
*   @description: Returns true if stone can be placed on Point, else false
*   @pre-condition: None
*   @post-condition: true if placable, else false
*   @return: true if p is within bounds of board,
             Point does not have a stone,
             Point does not violate Ko rule,
             and Point would not result in a self capture,
             else false
*/
bool isPlaceable(Board& b, StoneType stoneType, point p);

/*
*   @function: pointToCoord()
*   @description: Converts a point(x,y) to a Coordinate(row,col)
*   @pre-condition: None
*   @post-condition: Coordinate is set to where point is
*   @return: copy of Coordinate at point
*/
Coordinate pointToCoord(point p, int pointLength, point offset = point(0,0));

/*
*   @function: coordInBounds()
*   @description: Returns true if Coordinate is within
                  bounds of board, else false
*   @pre-condition: None
*   @post-condition: true if in bounds, else false
*   @return: true if Coordinate is not negative and
             less than boardSize, else false
*/
bool coordInBounds(Coordinate c, int boardSize);


/*
*   @function: drawHover()
*   @description: Plots the Hover Stone with its highlight
*   @pre-condition: None
*   @post-condition: Hover Stone and highlight plotted
*   @return: nothing
*/
void drawHover(SDL_Plotter& g, point center, int pointLength,
               color stone, color highlight);

/*
*   @function: isStringSurrounded()
*   @description: Recursively checks whether a string of
                  same type stones is capturable
*   @pre-condition: none
*   @post-condition: true if string can be captured, false if not
*   @return: bool
*/
bool isStringSurrounded(Point** &board, Point &p);

/*
*   @function: captureStones()
*   @description: Captures all capturable stones
*   @pre-condition: none
*   @post-condition: All capturable stones are removed from the board
*   @return: none
*/
void captureStones(SDL_Plotter& g, Board& b);

/*
*   @function: unmarkStones()
*   @description: Unmarks all marked stones
*   @pre-condition: none
*   @post-condition: All marks will be cleared
*   @return: none
*/
void unmarkStones(Point** &board, int size);

/*
*   @function: koRule()
*   @description: Adds the Point to the bannedCapturePoint of the
                  player who last played it
*   @pre-condition: none
*   @post-condition: bannedCapturePoint updated for player
                     who previously played Point
*   @return: nothing
*/
void koRule(Board& b, Point* p);

/*
*   @function: captureRule()
*   @description: Runs the capture rule for the new Point.
*   @pre-condition: none
*   @post-condition: Captured stones removed,
                     Ko rule enacted for single captured stone,
                     Player score updated based on removed stones
*   @return: nothing
*/
void captureRule(SDL_Plotter& g, Board& b, Point& p);

/*
*   @function: isSelfCapture()
*   @description: Checks if the Point's placement would result in a
                  self capture same turn
*   @pre-condition: none
*   @post-condition: none
*   @return: True if the Point won't capture anything and
             immediately be capturable, else False
*/
bool isSelfCapture(Board& b, Point& p);


#endif
