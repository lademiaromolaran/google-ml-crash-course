#include "match_helpers.h"

void drawBoard(SDL_Plotter& g, Point** board, int boardSize,
               int pointLength, point offset)
{
    for(int r = 0; r < boardSize; r++)
    {
        for(int c = 0; c < boardSize; c++)
        {
            board[r][c].drawPoint(g, pointLength, offset);
        }
    }
}

bool isPlaceable(Point** board, int** territory, StoneType stoneType, point p, int pointLength,
                 int boardSize, Player pB, Player pW, point offset)
{
    Coordinate c = pointToCoord(p, pointLength, offset);
    bool result = false;

    if(coordInBounds(c, boardSize) 
		&& board[c.row][c.col].getStoneType() == ST_EMPTY)
    {
    	if(stoneType == ST_BLACK)
    	{
    		if(territory[c.row][c.col] != 1 && &board[c.row][c.col] != pB.bannedCapturePoint())
    		{
    			result = true;
    		}
		}
		if(stoneType == ST_WHITE)
		{
			if(territory[c.row][c.col] != 0 && &board[c.row][c.col] != pW.bannedCapturePoint())
			{
				result = true;	
			}
		}
    }


    return result;
}

Coordinate pointToCoord(point p, int pointLength, point offset)
{
    Coordinate coord;
    coord.row = (p.y - offset.y) / pointLength;
    coord.col = (p.x - offset.x) / pointLength;

    return coord;
}

bool coordInBounds(Coordinate c, int boardSize)
{
    bool result = true;

    if(c.row < 0 || c.col < 0 || c.row >= boardSize || c.col >= boardSize)
    {
        result = false;
    }

    return result;
}

void drawHover(SDL_Plotter& g, point center, int pointLength, color stone, color highlight)
{
    int radius = pointLength / 2.2;
    double thickness = 1.5;

    drawCircle(g, center, radius, stone);
    drawRing(g, center, radius, highlight, thickness);
}


bool isStringSurrounded(Point** &board, Point &p)
{	
	// Base Case 1: Empty Space Adjacent	
	bool check = true;
	int i = 0;
	for(i; i < 4; i++)
	{ 
		if(p.getLiberty(static_cast<Direction>(i)) != nullptr 
			&& p.getLiberty(static_cast<Direction>(i))->getStone().isEmpty())
		{
			return false;
		}
	}
	
	p.setMarked(true);
	
	// Base Case 2: Stone is surrounded by opposite color or marked		
	i = 0;
	check = true;
	while(check && i < 4)
	{
		// if stone at Direction i is the same type and unmarked
		if(p.getLiberty(static_cast<Direction>(i)) != nullptr 
			&& !p.isOppositeType(p.getLiberty(static_cast<Direction>(i))) 
			&& !p.getLiberty(static_cast<Direction>(i))->isMarked())
		{
			check = false;
		}
		i++;
	}
	// if check remains true
	if(check)
	{
		return true;
	}
	
	// Recursive Calls
	i = 0;
	check = true;
	while(check && i < 4)
	{
		// if stone at Direction i is the same type and unmarked
		if(p.getLiberty(static_cast<Direction>(i)) != nullptr 
			&& !p.isOppositeType(p.getLiberty(static_cast<Direction>(i))) 
			&& !p.getLiberty(static_cast<Direction>(i))->isMarked())
		{
			// recursive call
			check = isStringSurrounded(board, *p.getLiberty(static_cast<Direction>(i)));
		}
		i++;
	}
	if(check)
	{
		return true;
	}

	return false;
}


void captureStones(Point** &board, int size, SDL_Plotter& g, int pointLength, 
	point offset, Player& pB, Player& pW, int** &territory)
{
	
	for(int r = 0; r < size; r++)
	{
		for(int c = 0; c < size; c++)
		{
			if(board[r][c].isMarked())
			{
				if(board[r][c].getStoneType() == pB.getStoneType())
				{
					pB.removeStones(1);
				}
				else
				{
					pW.removeStones(1);
				}
				
				/* -Territory Check Interferes w/ Ko Rule currently-
				bool check = true;
				int i = 0;
				while(check && i < 4)
				{
					if(board[r][c].getLiberty(static_cast<Direction>(i)) != nullptr 
						&& !board[r][c].isOppositeType(board[r][c].getLiberty(static_cast<Direction>(i))))
					{
						check = false;
					}
					i++;
				}
				if(check)
				{
					if(board[r][c].getStoneType() == ST_BLACK)
					{
						territory[r][c] = 1;
					}
					else
					{
						territory[r][c] = 0;
					}
				}
				*/
				
				
				board[r][c].setMarked(false);
				board[r][c].setStone(Stone(ST_EMPTY));
				board[r][c].drawPoint(g, pointLength, offset);
			}
		}
	}
}


void unMarkStones(Point** &board, int size)
{
	for(int r = 0; r < size; r++)
	{
		for(int c = 0; c < size; c++)
		{
			if(board[r][c].isMarked())
			{
				board[r][c].setMarked(false);
			}
		}
	}
}
