/*
* Author: Aidan Stout
* File Name: Player.h
* File Description: This file contains the Player class
* Date Created: 11/19/2024
* Date Last Modified: 11/19/2024
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <ctime>
#include "SDL_Plotter.h"
#include "config.h"

class Player
{
private:
    StoneType stoneType;
    int placedStones;
    int territoryCount;
    int capturedStones;
    time_t timerStart;
    unsigned int timerSeconds;
    bool isPaused;


public:

    /*
    *   @function: Player()
    *   @description: Class constructor
    *   @pre-condition: None
    *   @post-condition: Class object created set to parameters. Default
                         parameters is stoneType is ST_BLACK, placedStone is 0,
                         territoryCount is 0, capturedStones is 0, timerStart
                         is 0, timerSeconds is 0, and isPaused is True.
    *   @return: nothing
    */
    Player(StoneType stoneType = ST_BLACK);

    /*
    *   @function: startTimer()
    *   @description: Sets timerStart to the time it is called
    *   @pre-condition: Object exists
    *   @post-condition: timerStart updated, isPaused set to false
    *   @return: nothing
    */
    void startTimer();

    /*
    *   @function: pauseTimer()
    *   @description: Adds the time between startTimer and call to
                      pauseTimer to timerSeconds which pauses the timer.
                      Call startTimer() to get the timer to run again.
    *   @pre-condition: Object exists
    *   @post-condition: timerSeconds updated, isPaused set to true
    *   @return: nothing
    */
    void pauseTimer();

    /*
    *   @function: getTimerSeconds()
    *   @description: Returns the number of seconds since the timer started
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: number of seconds on timer
    */
    unsigned int getTimerSeconds() const;

    /*
    *   @function: getScore()
    *   @description: Returns the current score for the player
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: player score
    */
    int getScore() const;

    /*
    *   @function: getStoneType()
    *   @description: Returns the player's stone type
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: copy of player stoneType
    */
    StoneType getStoneType() const;

    /*
    *   @function: getPlacedStones()
    *   @description: Returns the number of stones the player has placed
    *   @pre-condition: Object exists
    *   @post-condition: Object unchanged
    *   @return: number of placed stones by player
    */
    int getPlacedStones() const;

    /*
    *   @function: addStones()
    *   @description: Increases the count of placed stones
                      by the number of stones in the parameter.
    *   @pre-condition: Object exists
    *   @post-condition: placedStones updated
    *   @return: none
    */
    void addStones(int stones);

    /*
    *   @function: removeStones()
    *   @description: Decreases the count of placed stones
                      by the number of stones in the parameter.
    *   @pre-condition: Object exists and the number of placed stones is
                        greater than or equal to the number of stones
                        to be removed
    *   @post-condition: placedStones updated
    *   @throw: if the number of stones to be removed is greater than
                the number of placed stones, a GoGameException is thrown
    *   @return: none
    */
    void removeStones(int stones);

    /*
    *   @function: setTerritoryCount()
    *   @description: Sets the territoryCount to the parameter
    *   @pre-condition: Object exists
    *   @post-condition: territoryCount updated
    *   @return: none
    */
    void setTerritoryCount(int territory);

    /*
    *   @function: addCapturedStones()
    *   @description: Increases the number of captured stones by number of
                      stones in the parameter
    *   @pre-condition: Object exists
    *   @post-condition: capturedStones updated
    *   @return: none
    */
    void addCapturedStones(int stones);
};

#endif
