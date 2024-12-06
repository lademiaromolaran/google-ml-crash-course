/*
* Author: Aidan Stout, Ryan Limprecht
* File Name: Point.h
* File Description: This file contains the Point class
* Date Created: 11/12/2024
* Date Last Modified: 12/4/2024
*/

#ifndef POINT_H
#define POINT_H

#include "SDL_Plotter.h"
#include "Stone.h"
#include "config.h"
#include "helpers.h"

class Point
{
private:
    int row;
    int col;
    Stone stone;
    bool marked;

    //List of the 4 neighboring Points, if border then nullptr
    Point** liberties;


    /*
    *   @function: drawStone()
    *   @description: Plots the stone for the Point
    *   @pre-condition: None
    *   @post-condition: Stone drawn
    *   @return: nothing
    */
    void drawStone(SDL_Plotter& g, point center, int radius);

public:

    /*
    *   @function: Point()
    *   @description: Class constructor
    *   @pre-condition: None
    *   @post-condition: Class object created set to parameters.
                         Default parameters is row = 0, col = 0,
                         liberties points to a list of 4 Point pointers
                         which point to nullptrs.
    *   @return: nothing
    */
    Point(int row=0, int col=0, Stone stone=Stone(ST_EMPTY));

    /*
    *   @function: ~Point()
    *   @description: Class destructor
    *   @pre-condition: Object exists
    *   @post-condition: All memory allocated to object is deallocated
    *   @return: nothing
    */
    ~Point();

    /*
    *   @function: setLiberty()
    *   @description: updates pointer to point to neighbor
                      in specified direction
    *   @pre-condition: Object exists
    *   @post-condition: liberties updated
    *   @return: nothing
    */
    void setLiberty(Point* neighbor, Direction direction);

    /*
    *   @function: setRow()
    *   @description: updates row to equal parameter row
    *   @pre-condition: Object exists
    *   @post-condition: row updates
    *   @return: nothing
    */
    void setRow(int row);

    /*
    *   @function: setCol()
    *   @description: updates col to equal parameter col
    *   @pre-condition: Object exists
    *   @post-condition: col updates
    *   @return: nothing
    */
    void setCol(int col);

    /*
    *   @function: setStone()
    *   @description: updates stone to equal parameter stone
    *   @pre-condition: Object exists
    *   @post-condition: stone updates
    *   @return: nothing
    */
    void setStone(Stone stone);

    /*
    *   @function: getRow()
    *   @description: returns a copy of row
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: copy of row
    */
    int getRow() const;

    /*
    *   @function: getCol()
    *   @description: returns a copy of col
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: copy of col
    */
    int getCol() const;

    /*
    *   @function: getStone()
    *   @description: returns a copy of stone
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: copy of stone
    */
    Stone getStone() const;

    /*
    *   @function: getStoneType()
    *   @description: returns a copy of type of stone
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: copy of stone type
    */
    StoneType getStoneType() const;
    
    /*
	*   @function: getLiberty()
	*   @description: returns a pointer to an adjacent point
	*   @pre-condition: Object exists
	*   @post-condition: Object unchanged
	*   @return: copy of adjacent Point pointer
	*/
	Point* getLiberty(Direction d) const;

    /*
    *   @function: drawPoint()
    *   @description: Plots the entire point including background,
                      point lines, and stone
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged, SDL_Plotter updated
    *   @return: nothing
    */
    void drawPoint(SDL_Plotter& g, int pointLength, point offset=point(0,0));

    
	/*
	*   @function: isMarked()
	*   @description: returns marked as a bool
	*   @pre-condition: Object exists
	*   @post-condition: Object unchanged
	*   @return: bool
	*/
	bool isMarked() const;
	
	/*
	*   @function: setMarked()
	*   @description: updates Marked bool
	*   @pre-condition: Object exists
	*   @post-condition: Marked is updated
	*   @return: nothing
	*/
	void setMarked(bool b);
	
	/*
	*   @function: isOppositeType()
	*   @description: returns true/false based on if the parameter Point
			contains a stone of different color and is not empty
	*   @pre-condition: Object exists
	*   @post-condition: Object unchanged
	*   @return: bool
	*/
	bool isOppositeType(Point p) const;
	
	/*
	*   @function: isOppositeType()
	*   @description: returns true/false based on if the parameter Point pointer
			contains a stone of different color and is not empty
	*   @pre-condition: Object exists
	*   @post-condition: Object unchanged
	*   @return: bool
	*/
	bool isOppositeType(Point *p) const;
	
	
	
};

#endif
