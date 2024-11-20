/*
* Author: Aidan Stout
* File Name: Stone.h
* File Description: This file contains the Stone class
* Date Created: 11/13/2024
* Date Last Modified: 11/19/2024
*/

#ifndef STONE_H
#define STONE_H

#include "SDL_Plotter.h"
#include "config.h"
#include "helpers.h"

class Stone
{
private:
    color _color;
    StoneType type;
    color* playerWhite;
    color* playerBlack;
public:

    /*
    *   @function: Stone()
    *   @description: Class constructor
    *   @pre-condition: None
    *   @post-condition: Class object created set to parameter.
                         Default parameter is set stone to type EMPTY.
    *   @return: nothing
    */
    Stone(StoneType type = ST_EMPTY);

    /*
    *   @function: setType()
    *   @description: Updates type to equal parameter type and updates color
                      to reflect type. If not BLACK or WHITE, default GREY.
    *   @pre-condition: Object exists
    *   @post-condition: type and color update
    *   @return: nothing
    */
    void setType(StoneType type);

    /*
    *   @function: setPlayerWhiteColor()
    *   @description: Sets the color for player white to point to the
                      parameter. Used for connecting white stone color
                      to settings.
    *   @pre-condition: Object exists
    *   @post-condition: playerWhite updated
    *   @return: nothing
    */
    void setPlayerWhiteColor(color* wPlayer);

    /*
    *   @function: setPlayerBlackColor()
    *   @description: Sets the color for player black to point to the
                      parameter. Used for connecting black stone color
                      to settings.
    *   @pre-condition: Object exists
    *   @post-condition: playerBlack updated
    *   @return: nothing
    */
    void setPlayerBlackColor(color* bPlayer);

    /*
    *   @function: getType()
    *   @description: Returns a copy of the type of Stone
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: copy of StoneType
    */
    StoneType getType() const;

    /*
    *   @function: getColor()
    *   @description: Returns a copy of the color of Stone
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: copy of color
    */
    color getColor() const;

    /*
    *   @function: isEmpty()
    *   @description: Returns true if Stone is empty, else false
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: True if type is ST_EMPTY, else false
    */
    bool isEmpty();
};

#endif
