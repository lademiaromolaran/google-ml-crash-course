//
//  Scoreboard.cpp
//  CSI 1440 Group Project
//
//  Created by Oluwalademi Aromolaran on 12/7/24.
//

#include "Scoreboard.h"

Scoreboard::Scoreboard(SDL_Plotter& g, Player black, Player white, point pos, int w, int h)
    : plotter(&g), blackPlayer(black), whitePlayer(white), position(pos), width(w), height(h) {}

void Scoreboard::render(int xOffset, int yOffset) const {
    // Render scoreboard background
    for (int y = position.y + yOffset; y < position.y + height + yOffset; y++) {
        for (int x = position.x + xOffset; x < position.x + width + xOffset; x++) {
            plotter->plotPixel(x, y, color(200, 200, 200)); // Light gray background
        }
    }

    // Draw player information
    drawPlayerInfo(blackPlayer, position.y + yOffset + 10); // Black player info at the top
    drawPlayerInfo(whitePlayer, position.y + yOffset + height / 2 + 10); // White player info below
}

void Scoreboard::update(const Player& black, const Player& white) {
    blackPlayer = black;
    whitePlayer = white;
}

void Scoreboard::drawPlayerInfo(const Player& player, int yOffset) const {
    string playerInfo = "Name: " + player.getName();
    playerInfo += " | Color: " + std::string(player.getStoneType() == ST_BLACK ? "Black" : "White");
    playerInfo += " | Timer: " + to_string(player.getTimerSeconds()) + "s";
    playerInfo += " | Score: " + to_string(player.getScore());

    renderText(position.x + 10, yOffset, playerInfo, color(0, 0, 0)); // Black text
}

void Scoreboard::renderText(int x, int y, const string& text, color c) const {
    int currentX = x;
    for (char ch : text) {
        if (ch == ' ') {
            currentX += 10;  // Space between words
            continue;
        }

        // Render each character (basic 8x8 block for simplicity)
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                plotter->plotPixel(currentX + i, y + j, c);
            }
        }
        currentX += 10;  // Move to the next character
    }
}

void Scoreboard::setName(bool isBlack, const string& playerName) {
    if (isBlack) {
        blackPlayer.setName(playerName);
    } else {
        whitePlayer.setName(playerName);
    }
}

string Scoreboard::getName(bool isBlack) const {
    return isBlack ? blackPlayer.getName() : whitePlayer.getName();
}

size_t Scoreboard::getTimer(bool isBlack) const {
    return isBlack ? blackPlayer.getTimerSeconds() : whitePlayer.getTimerSeconds();
}
