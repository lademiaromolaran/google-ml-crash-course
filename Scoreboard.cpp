/*
* Author: Lademi Aromolaran
* File Name: Scoreboard.h
* File Description: This file contains implements functions
                    that render the scoreboard.
* Date Created: 12/6/2024
* Date Last Modified: 12/6/2024
*/


#include "Scoreboard.h"
#include "Player.h"

Scoreboard::Scoreboard(SDL_Plotter& g, Player black, Player white, Point pos, int w, int h)
    : plotter(&g), blackPlayer(black), whitePlayer(white), position(pos), width(w), height(h) {}


void Scoreboard::render() const {

    for (int y = position.y; y < position.y + height; y++) {
        for (int x = position.x; x < position.x + width; x++) {
            plotter->plotPixel(x, y, color(200, 200, 200));
        }
    }

    drawPlayerInfo(blackPlayer, position.y + 10);
    drawPlayerInfo(whitePlayer, position.y + height / 2);
}


void Scoreboard::update(const Player& black, const Player& white) {
    blackPlayer = black;
    whitePlayer = white;
}


void Scoreboard::drawPlayerInfo(const Player& player, int yOffset) const {
    string playerInfo = "Name: " + player.getName();
    playerInfo += " | Color: " + (player.getStoneType() == ST_BLACK ? "Black" : "White");
    playerInfo += " | Timer: " + to_string(player.getTimer());
    playerInfo += " | Score: " + to_string(player.getScore());
    renderText(position.x + 10, yOffset, playerInfo, color(0, 0, 0));
}


void Scoreboard::renderText(int x, int y, const string& text, color c) const {
    int currentX = x;
    for (char ch : text) {
        if (ch == ' ') {
            currentX += 10;
            continue;
        }

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {

                if (ch != ' ') {
                    plotter->plotPixel(currentX + i, y + j, c);
                }
            }
        }

        currentX += 10;
    }
}
