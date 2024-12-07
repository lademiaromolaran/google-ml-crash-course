//
//  Scoreboard.h
//  CSI 1440 Group Project
//
//  Created by Oluwalademi Aromolaran on 12/6/24.
//

#ifndef Scoreboard_h
#define Scoreboard_h

#include "SDL_Plotter.h"
#include "Player.h"

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
    void render() const;

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
};

#endif /* Scoreboard_h */
