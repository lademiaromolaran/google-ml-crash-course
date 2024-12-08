//
//  stages.cpp
//  CSI 1440 Group Project
//
//  Created by Oluwalademi Aromolaran on 12/7/24.
//

#include "stages.h"
#include "Scoreboard.h"



Stage mainMenu(SDL_Plotter& g) //WIP
{
    Stage nextStage = S_NONE;

    /*
    -Needs Main Menu Screen Rendering
    --Mouse click detection to determine next stage
    */
    while(nextStage == S_NONE)
    {
        nextStage = S_PLAY; //Temporary. Remove when implementing Main Menu

        g.update();

        if(g.getQuit())
        {
            nextStage = S_QUIT;
        }
    }

    return nextStage;
}


void options(SDL_Plotter& g, Settings& s) //WIP
{
    bool exitOptions = false;

    /*
    -Needs Options Screen Rendering
    -Needs assignment of new values for options
    */
    while(!exitOptions)
    {

        if(g.getQuit())
        {
            exitOptions = true;
        }

        g.update();
    }
}

void playMatch(SDL_Plotter& g, Settings& s) {
    // Board setup
    Point** board = new Point*[s.boardSize];
    point offset(0, 0); // Adjust offset as necessary
    int pointLength = (SCREEN_X - offset.x * 2) / s.boardSize;
    point mouse, hover, center;
    Coordinate mCoord, hCoord;
    StoneType stoneType = ST_BLACK;
    Stone setterStone;
    color highlight;

    Player pB(ST_BLACK), pW(ST_WHITE);

    setterStone.setPlayerBlackColor(&s.blackStone);
    setterStone.setPlayerWhiteColor(&s.whiteStone);
    setterStone.setType(stoneType);

    Board b;
    b.board = board;
    b.offset = &offset;
    b.pointLength = &pointLength;
    b.setterStone = &setterStone;
    b.pB = &pB;
    b.pW = &pW;
    b.boardSize = &s.boardSize;

    // Initialize the board points
    for (int r = 0; r < s.boardSize; r++) {
        board[r] = new Point[s.boardSize];
        for (int c = 0; c < s.boardSize; c++) {
            board[r][c].setRow(r);
            board[r][c].setCol(c);
            if (r > 0) board[r][c].setLiberty(board[r - 1] + c, UP);
            if (r < s.boardSize - 1) board[r][c].setLiberty(board[r + 1] + c, DOWN);
            if (c > 0) board[r][c].setLiberty(board[r] + c - 1, LEFT);
            if (c < s.boardSize - 1) board[r][c].setLiberty(board[r] + c + 1, RIGHT);
        }
    }

    drawBoard(g, b); // Render the board

    // Start the timer for the black player
    pB.startTimer();

    // Initialize the scoreboard
    int scoreboardHeight = 100;
    Scoreboard scoreboard(g, pB, pW, point(0, SCREEN_Y - scoreboardHeight), SCREEN_X, scoreboardHeight);

    while (!g.getQuit()) {
        g.getMouseLocation(hover.x, hover.y);
        hCoord = pointToCoord(hover, pointLength, offset);

        // Check if the hovered point is within bounds
        if (coordInBounds(hCoord, s.boardSize)) {
            if (isPlaceable(b, stoneType, hover)) {
                highlight = s.validHighlight;
            } else {
                highlight = s.invalidHighlight;
            }
            center.x = offset.x + hCoord.col * pointLength + pointLength / 2;
            center.y = offset.y + hCoord.row * pointLength + pointLength / 2;

            drawHover(g, center, pointLength, setterStone.getColor(), highlight);
        }

        // Handle mouse clicks
        if (g.mouseClick()) {
            mouse = g.getMouseClick();
            if (isPlaceable(b, stoneType, mouse)) {
                mCoord = pointToCoord(mouse, pointLength, offset);
                board[mCoord.row][mCoord.col].setStone(setterStone);
                board[mCoord.row][mCoord.col].drawPoint(g, pointLength, offset);

                captureRule(g, b, board[mCoord.row][mCoord.col]);

                // Update the active player's state
                if (stoneType == pB.getStoneType()) {
                    pB.startTimer();
                    pW.pauseTimer();
                    pB.addStones(1);
                } else {
                    pW.startTimer();
                    pB.pauseTimer();
                    pW.addStones(1);
                }

                // Switch to the next player's turn
                stoneType = static_cast<StoneType>((stoneType + 1) % 2);
                setterStone.setType(stoneType);
            }
        }

        g.update();

        // Draw the point being hovered
        if (coordInBounds(hCoord, s.boardSize)) {
            board[hCoord.row][hCoord.col].drawPoint(g, pointLength, offset);
        }

        // Update and render the scoreboard
        scoreboard.update(pB, pW);
        scoreboard.render(0, 0);
    }

    // Clean up allocated memory
    for (int r = 0; r < s.boardSize; r++) {
        delete[] board[r];
    }
    delete[] board;
}
