/*
* Author: Aidan Stout
* File Name: helpers.h
* File Description: This file contains functions that help with
                    a variety of different tasks for many files
* Date Created: 11/12/2024
* Date Last Modified: 11/19/2024
*/
#ifndef HELPERS_H
#define HELPERS_H

#include <fstream>
#include <cassert>
#include <string>
#include <cmath>
#include "SDL_Plotter.h"
#include "config.h"

/*
*   @function: drawLine()
*   @description: draws a line of color from start to end on plotter
*   @pre-condition: None
*   @post-condition: Plotter updated
*   @return: nothing
*/
void drawLine(SDL_Plotter& g, point start, point end, color _color);

/*
*   @function: drawCircle()
*   @description: Plots a solid circle
*   @pre-condition: None
*   @post-condition: Plotter updated
*   @return: nothing
*/
void drawCircle(SDL_Plotter& g, point center, int radius, color _color);

/*
*   @function: drawRing()
*   @description: Plots a ring
*   @pre-condition: None
*   @post-condition: Plotter updated
*   @return: nothing
*/
void drawRing(SDL_Plotter& g, point center, int radius,
              color _color, double thickness=1.0);

#endif
