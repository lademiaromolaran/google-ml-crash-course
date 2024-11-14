#include "stages.h"


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


void options(SDL_Plotter& g) //WIP
{
    bool exitOptions = false;

    //Settings Data Abstraction
    int boardSize          = BOARD_SIZE;
    bool isPvAI            = IS_PvAI;
    bool isPlayerWhite     = IS_PLAYER_WHITE;
    double komi            = KOMI;
    color validHighlight   = VALID_HIGHLIGHT;
    color invalidHighlight = INVALID_HIGHLIGHT;

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

    //Update settings file after options selection
    createSettingsFile(boardSize,
                       isPvAI,
                       isPlayerWhite,
                       komi,
                       validHighlight,
                       invalidHighlight);
}

void playMatch(SDL_Plotter& g) //WIP
{
    //Settings Data Abstraction
    int boardSize;
    bool isPvAI;
    bool isPlayerWhite;
    double komi;
    color validHighlight;
    color invalidHighlight;

    extractSettings(boardSize,
                    isPvAI,
                    isPlayerWhite,
                    komi,
                    validHighlight,
                    invalidHighlight);

    //Game Data Abstraction
    Point** board = new Point*[boardSize];
    point offset(0,0);
    int pointLength = (SCREEN_X - offset.x*2) / boardSize;
    point mouse, hover, center;
    Coordinate mCoord, hCoord;
    StoneType stone = ST_BLACK;
    color highlight;

    //Initialize Board
    for(int r = 0; r < boardSize; r++)
    {
        board[r] = new Point[boardSize];
    }

    //Map to neighbors
    for(int r = 0; r < boardSize; r++)
    {
        for(int c = 0; c < boardSize; c++)
        {
            board[r][c].setRow(r);
            board[r][c].setCol(c);

            if(r > 0)
            {
                board[r][c].setLiberty(board[r-1] + c, UP);
            }
            if(r < boardSize-1)
            {
                board[r][c].setLiberty(board[r+1] + c, DOWN);
            }
            if(c > 0)
            {
                board[r][c].setLiberty(board[r] + c-1, LEFT);
            }
            if(c < boardSize-1)
            {
                board[r][c].setLiberty(board[r] + c+1, RIGHT);
            }
        }
    }

    //Render Board
    drawBoard(g, board, boardSize, pointLength, offset);


    while(!g.getQuit())
    {
        //Hover Stone
        g.getMouseLocation(hover.x, hover.y);
        hCoord = pointToCoord(hover, pointLength, offset);

        if(coordInBounds(hCoord, boardSize))
        {
            if(isPlaceable(board, hover, pointLength, boardSize, offset))
            {
                highlight = validHighlight;
            }
            else
            {
                highlight = invalidHighlight;
            }
            center.x = offset.x + hCoord.col*pointLength + pointLength/2;
            center.y = offset.y + hCoord.row*pointLength + pointLength/2;

            drawHover(g, center, pointLength,
                      Stone(stone).getColor(), highlight);
        }


        if(g.mouseClick())
        {
            mouse = g.getMouseClick();
            if(isPlaceable(board, mouse, pointLength, boardSize, offset))
            {
                mCoord = pointToCoord(mouse, pointLength, offset);
                board[mCoord.row][mCoord.col].setStone(Stone(stone));
                stone = static_cast<StoneType>((stone + 1) % 2);
                board[mCoord.row][mCoord.col].drawPoint(g, pointLength, offset);
            }

        }
        g.update();

        //Clear Hover
        if(coordInBounds(hCoord, boardSize))
        {
            board[hCoord.row][hCoord.col].drawPoint(g, pointLength, offset);
        }
    }

    for(int r = 0; r < boardSize; r++)
    {
        delete[] board[r];
    }
    delete[] board;
}
