//
//  Scoreboard.h
//  CSI 1440 Group Project
//
//  Created by Oluwalademi Aromolaran on 12/7/24.
//

#ifndef Scoreboard_h
#define Scoreboard_h


#include "SDL_Plotter.h"
#include "Player.h"
#include "Point.h"

using namespace std;

class Scoreboard {
private:
    Player blackPlayer;
    Player whitePlayer;
    SDL_Plotter* plotter;
    point position;
    int width;
    int height;

public:
    /*
    *   @function: Scoreboard()
    *   @description: Constructor that initializes the scoreboard with
                      the given parameters for players, position, and
                      dimensions.
    *   @pre-condition: Objects for blackPlayer and whitePlayer exist
    *   @post-condition: Scoreboard object created and initialized
    *   @return: Nothing
    */
    Scoreboard(SDL_Plotter& g, Player black, Player white, point pos, int w, int h);

    /*
    *   @function: render()
    *   @description: Renders the scoreboard, including background and
                      player information (name, color, timer, score).
    *   @pre-condition: Scoreboard object is initialized and players exist
    *   @post-condition: Scoreboard is rendered on the screen
    *   @return: Nothing
    */
    void render(int xOffset, int yOffset) const;

    /*
    *   @function: update()
    *   @description: Updates the scoreboard with new player data.
    *   @pre-condition: Scoreboard object exists and players are updated
    *   @post-condition: blackPlayer and whitePlayer are updated
    *   @return: Nothing
    */
    void update(const Player& black, const Player& white);

    /*
    *   @function: drawPlayerInfo()
    *   @description: Draws the information (name, color, timer, score) of
                      a given player at the specified vertical position.
    *   @pre-condition: Player object exists
    *   @post-condition: Player information is rendered on the scoreboard
    *   @return: Nothing
    */
    void drawPlayerInfo(const Player& player, int yOffset) const;

    /*
    *   @function: renderText()
    *   @description: Renders a given string of text at a specified position
                      on the screen, using the specified color.
    *   @pre-condition: Valid text string and position
    *   @post-condition: Text is rendered at the specified position
    *   @return: Nothing
    */
    void renderText(int x, int y, const string& text, color c) const;
    
    /*
     *   @function: setName()
     *   @description: Sets the name of the player (Black or White).
     *   @pre-condition: Object exists, isBlack indicates which player’s name is to be set.
     *   @post-condition: Corresponding player’s name is updated.
     *   @return: nothing
     */
    void setName(bool isBlack, const string& playerName);
    
    /*
     *   @function: getName()
     *   @description: Gets the name of the player (Black or White).
     *   @pre-condition: Object exists, isBlack indicates which player’s name to return.
     *   @post-condition: none
     *   @return: the name of the player.
     */
    string getName(bool isBlack) const;
    
    /*
     *   @function: getTimer()
     *   @description: Gets the time in seconds that the player (Black or White) has played.
     *   @pre-condition: Object exists, isBlack indicates which player's timer is being requested.
     *   @post-condition: none
     *   @param: isBlack - boolean to decide which player’s timer to get (true for black player, false for white player).
     *   @return: the timer value in seconds.
     */
    size_t getTimer(bool isBlack) const;

};


#endif /* Scoreboard_h */
