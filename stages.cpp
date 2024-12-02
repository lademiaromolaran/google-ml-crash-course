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

void playMatch(SDL_Plotter& g, Settings& s) //WIP
{
    //Game Data Abstraction
    Point** board = new Point*[s.boardSize];
    point offset(0,0);
    int pointLength = (SCREEN_X - offset.x*2) / s.boardSize;
    point mouse, hover, center;
    Coordinate mCoord, hCoord;
    StoneType stoneType = ST_BLACK;
    Stone setterStone;
    color highlight;

    Player pB(ST_BLACK), pW(ST_WHITE);

    //Link setterStone to settings' colors
    setterStone.setPlayerBlackColor(&s.blackStone);
    setterStone.setPlayerWhiteColor(&s.whiteStone);
    setterStone.setType(stoneType);

    //Initialize Board
    for(int r = 0; r < s.boardSize; r++)
    {
        board[r] = new Point[s.boardSize];
    }

    //Map to neighbors
    for(int r = 0; r < s.boardSize; r++)
    {
        for(int c = 0; c < s.boardSize; c++)
        {
            board[r][c].setRow(r);
            board[r][c].setCol(c);

            if(r > 0)
            {
                board[r][c].setLiberty(board[r-1] + c, UP);
            }
            if(r < s.boardSize-1)
            {
                board[r][c].setLiberty(board[r+1] + c, DOWN);
            }
            if(c > 0)
            {
                board[r][c].setLiberty(board[r] + c-1, LEFT);
            }
            if(c < s.boardSize-1)
            {
                board[r][c].setLiberty(board[r] + c+1, RIGHT);
            }
        }
    }

    //Render Board
    drawBoard(g, board, s.boardSize, pointLength, offset);


    //Start Timer
    pB.startTimer();

    while(!g.getQuit())
    {
        //Hover Stone
        g.getMouseLocation(hover.x, hover.y);
        hCoord = pointToCoord(hover, pointLength, offset);

        if(coordInBounds(hCoord, s.boardSize))
        {
            if(isPlaceable(board, hover, pointLength, s.boardSize, offset))
            {
                highlight = s.validHighlight;
            }
            else
            {
                highlight = s.invalidHighlight;
            }
            center.x = offset.x + hCoord.col*pointLength + pointLength/2;
            center.y = offset.y + hCoord.row*pointLength + pointLength/2;

            drawHover(g, center, pointLength,
                      setterStone.getColor(), highlight);
        }

        //Mouse Click
        if(g.mouseClick())
        {
            mouse = g.getMouseClick();
            if(isPlaceable(board, mouse, pointLength, s.boardSize, offset))
            {
                mCoord = pointToCoord(mouse, pointLength, offset);
                board[mCoord.row][mCoord.col].setStone(setterStone);
                stoneType = static_cast<StoneType>((stoneType + 1) % 2);
                setterStone.setType(stoneType);
                board[mCoord.row][mCoord.col].drawPoint(g, pointLength, offset);
				// Capture Rule
            	for(int i = 0; i < 4; i++)
				{
					// if adjacent stone is opposite type
					if(board[mCoord.row][mCoord.col].isOppositeType(board[mCoord.row][mCoord.col].getLiberty(static_cast<Direction>(i))))
					{
						if(isStringSurrounded(board, *board[mCoord.row][mCoord.col].getLiberty(static_cast<Direction>(i))))
						{
							captureStones(board, s.boardSize, g, pointLength, offset, pB, pW);
						}
						else
						{
							unMarkStones(board, s.boardSize);
						}
					}	
				}
				
				
				
                //Player updates
                if(stoneType == pB.getStoneType())
                {
                    pB.startTimer();
                    pW.pauseTimer();

                    pW.addStones(1);
                }
                else
                {
                    pW.startTimer();
                    pB.pauseTimer();

                    pB.addStones(1);
                }
            }

        }
        g.update();

        //Clear Hover
        if(coordInBounds(hCoord, s.boardSize))
        {
            board[hCoord.row][hCoord.col].drawPoint(g, pointLength, offset);
        }
    }

    for(int r = 0; r < s.boardSize; r++)
    {
        delete[] board[r];
    }
    delete[] board;
}
