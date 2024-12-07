#include "match_helpers.h"

void drawBoard(SDL_Plotter& g, Board& b)
{
    for(int r = 0; r < *b.boardSize; r++)
    {
        for(int c = 0; c < *b.boardSize; c++)
        {
            b.board[r][c].drawPoint(g, *b.pointLength, *b.offset);
        }
    }
}

bool isPlaceable(Board& b, StoneType stoneType, point p)
{
    Coordinate c = pointToCoord(p, *b.pointLength, *b.offset);
    bool result = false;

    if(coordInBounds(c, *b.boardSize)
		&& b.board[c.row][c.col].getStoneType() == ST_EMPTY
        && !isSelfCapture(b, b.board[c.row][c.col]))
    {
    	if(stoneType == ST_BLACK
           && &b.board[c.row][c.col] != b.pB->getBannedCapturePoint())
    	{
    		result = true;
		}

		if(stoneType == ST_WHITE
           && &b.board[c.row][c.col] != b.pW->getBannedCapturePoint())
		{
		    result = true;
		}
    }

    unmarkStones(b.board, *b.boardSize);

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

void drawHover(SDL_Plotter& g, point center, int pointLength,
               color stone, color highlight)
{
    int radius = pointLength / 2.2;
    double thickness = 1.5;

    drawCircle(g, center, radius, stone);
    drawRing(g, center, radius, highlight, thickness);
}


bool isStringSurrounded(Point** &board, Point &p)
{
	// Base Case 1: Empty Space Adjacent
	if(!p.isSurrounded())
    {
        return false;
    }

	p.setMarked(true);

	// Recursive Calls
    Direction direction;
	bool check = true;
	for(int i = 0; check && i < 4; i++)
	{
	    direction = static_cast<Direction>(i);

		// if stone at Direction i is the same type and unmarked
		if(p.getLiberty(direction) != nullptr
			&& !p.isOppositeType(p.getLiberty(direction))
			&& !p.getLiberty(direction)->isMarked())
		{
			// recursive call
			check = isStringSurrounded(board, *p.getLiberty(direction));
		}
	}

	if(check)
	{
		return true;
	}

	return false;
}


void captureStones(SDL_Plotter& g, Board& b)
{

	for(int r = 0; r < *b.boardSize; r++)
	{
		for(int c = 0; c < *b.boardSize; c++)
		{
			if(b.board[r][c].isMarked())
			{
				if(b.board[r][c].getStoneType() == b.pB->getStoneType())
				{
					b.pB->removeStones(1);
				}
				else
				{
					b.pW->removeStones(1);
				}

				b.board[r][c].setMarked(false);
				b.board[r][c].removeStone();
				b.board[r][c].drawPoint(g, *b.pointLength, *b.offset);
			}
		}
	}
}

void unmarkStones(Point** &board, int size)
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

void koRule(Board& b, Point* p)
{
    if(p->isSurrounded())
    {
        switch(p->surroundedType())
        {
            case ST_BLACK:
                b.pW->setBannedCapturePoint(p);
                break;
            case ST_WHITE:
                b.pB->setBannedCapturePoint(p);
                break;
            default: break;
        }
    }
}

void captureRule(SDL_Plotter& g, Board& b, Point& p)
{
    Direction direction;

    for(int i = 0; i < 4; i++)
    {
        direction = static_cast<Direction>(i);

        // if adjacent stone is opposite type
        if(p.getLiberty(direction) != nullptr
            && p.isOppositeType(p.getLiberty(direction)))
        {
            if(isStringSurrounded(b.board, *p.getLiberty(direction)))
            {
                captureStones(g, b);

                koRule(b, p.getLiberty(direction));
            }
            else
            {
                unmarkStones(b.board, *b.boardSize);
            }
        }
    }
}

bool isSelfCapture(Board& b, Point& p)
{
    bool result = true;
    Direction direction;
    Stone tmp = p.getStone();
    p.setStone(*b.setterStone);

    //Check if any liberties are surrounded by stones of player's type
    for(int i = 0; result && i < 4; i++)
    {
        direction = static_cast<Direction>(i);

        if(p.getLiberty(direction) != nullptr
            && p.isOppositeType(p.getLiberty(direction)))
        {
            if(isStringSurrounded(b.board, *p.getLiberty(direction)))
            {
                result = false;
            }
            unmarkStones(b.board, *b.boardSize);
        }
    }

    // Check if the player would be completely surrounded by opponent stones
    if(result)
    {
       if(!isStringSurrounded(b.board, p))
       {
           result = false;
       }
       unmarkStones(b.board, *b.boardSize);
    }

    p.setStone(tmp);

    return result;
}

