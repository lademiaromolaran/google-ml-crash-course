#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int row, int col, Stone stone): row(row), col(col), stone(stone), 
	liberties(new Point*[4]), marked(false), territory(false)
{
    for(int i = 0; i < 4; i++)
    {
        liberties[i] = nullptr;
    }
}

Point::~Point()
{
    delete[] liberties;
}


void Point::setLiberty(Point* neighbor, Direction direction)
{
    liberties[direction] = neighbor;
}


void Point::setRow(int row)
{
    this->row = row;
}

void Point::setCol(int col)
{
    this->col = col;
}

void Point::setStone(Stone stone)
{
    this->stone = stone;
}


int Point::getRow() const
{
    return row;
}


int Point::getCol() const
{
    return col;
}


Stone Point::getStone() const
{
    return stone;
}


StoneType Point::getStoneType() const
{
    return stone.getType();
}


Point* Point::getLiberty(Direction d) const
{
	return liberties[d];
}


void Point::drawPoint(SDL_Plotter& g, int pointLength, point offset)
{
    point center(offset.x + col*pointLength + pointLength/2,
                 offset.y + row*pointLength + pointLength/2);
    color line(0,0,0);

    for(int x = 0; x < pointLength; x++)
    {
        for(int y = 0; y < pointLength; y++)
        {
            g.plotPixel(offset.x + col*pointLength + x,
                        offset.y + row*pointLength + y, BOARD);
        }
    }

    if(liberties[UP] != nullptr)
    {
        drawLine(g, center,
                 point(center.x, center.y - pointLength/2), line);
    }

    if(liberties[DOWN] != nullptr)
    {
        drawLine(g, center,
                 point(center.x, center.y + pointLength/2), line);
    }

    if(liberties[LEFT] != nullptr)
    {
        drawLine(g, center,
                 point(center.x - pointLength/2, center.y), line);
    }

    if(liberties[RIGHT] != nullptr)
    {
        drawLine(g, center,
                 point(center.x + pointLength/2, center.y), line);
    }

    drawStone(g, center, pointLength/2.5);
}


void Point::erasePoint(SDL_Plotter& g, int pointLength, point offset)
{
	point center(offset.x + col*pointLength + pointLength/2,
                 offset.y + row*pointLength + pointLength/2);
    color line(0,0,0);
    
    for(int x = 0; x < pointLength; x++)
    {
        for(int y = 0; y < pointLength; y++)
        {
            g.plotPixel(offset.x + col*pointLength + x,
                        offset.y + row*pointLength + y, BOARD);
        }
    }
    
    drawCircle(g, center, pointLength/2.5, BOARD);
    
    if(liberties[UP] != nullptr)
    {
        drawLine(g, center,
                 point(center.x, center.y - pointLength/2), line);
    }

    if(liberties[DOWN] != nullptr)
    {
        drawLine(g, center,
                 point(center.x, center.y + pointLength/2), line);
    }

    if(liberties[LEFT] != nullptr)
    {
        drawLine(g, center,
                 point(center.x - pointLength/2, center.y), line);
    }

    if(liberties[RIGHT] != nullptr)
    {
        drawLine(g, center,
                 point(center.x + pointLength/2, center.y), line);
    }
    
}


bool Point::isMarked() const
{
	return marked;
}


void Point::setMarked(bool b)
{
	this->marked = b;
}


bool Point::isOppositeType(Point p) const
{
	return this->getStoneType() != p.getStoneType() && !p.getStone().isEmpty();
}

bool Point::isOppositeType(Point* p) const
{
	return this->getStoneType() != p->getStoneType() && !p->getStone().isEmpty();
}

bool Point::isTerritory() const
{
	return territory;
}

void Point::setTerritory(bool b)
{
	territory = b;
}


//___________________________Private______________________________

void Point::drawStone(SDL_Plotter& g, point center, int radius)
{

    if(getStoneType() != ST_EMPTY)
    {
        drawCircle(g, center, radius, stone.getColor());
    }
}
