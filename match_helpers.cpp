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

bool isPlaceable(Point** board, point p, int pointLength,
                 int boardSize, point offset)
{
    Coordinate c = pointToCoord(p, pointLength, offset);
    bool result = false;

    if(coordInBounds(c, boardSize) &&
       board[c.row][c.col].getStoneType() == ST_EMPTY)
    {
        result = true;
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
