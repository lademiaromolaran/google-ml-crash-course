/*
* Author: Aidan Stout, Ryan Limprecht
* File Name: match_helpers.h
* File Description: This file contains functions that help
                    the playMatch stage specifically in stages.h
* Date Created: 11/13/2024
* Date Last Modified: 12/5/2024
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

/*
*   @function: drawBoard()
*   @description: Plots the entire Go board
*   @pre-condition: None
*   @post-condition: Plotter updated with board
*   @return: nothing
*/
void drawBoard(SDL_Plotter& g, Point** board, int boardSize,
               int pointLength, point offset = point(0,0));


/*
*   @function: isPlaceable()
*   @description: Returns true if stone can be placed on Point, else false
*   @pre-condition: None
*   @post-condition: true if placable, else false
*   @return: true if p is within bounds of board,
             and Point does not have a stone, else false
*/
bool isPlaceable(Point** board, int** territory, StoneType stoneType, point p, int pointLength,
                 int boardSize, Player pB, Player pW, point offset = point(0,0));

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
void drawHover(SDL_Plotter& g, point center, int pointLength, color stone, color highlight);

/*
*   @function: isStringSurrounded()
*   @description: Revursively checks whether a string of same type stones is capturable
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
void captureStones(Point** &board, int size, SDL_Plotter& g, int pointLength, 
	point offset, Player& pB, Player& pW, int** &territory);

/*
*   @function: unMarkStones()
*   @description: Unmarks all marked stones
*   @pre-condition: none
*   @post-condition: All marks will be cleared
*   @return: none
*/
void unMarkStones(Point** &board, int size);


#endif
