#include "Stone.h"

Stone::Stone(StoneType type)
{
    setType(type);
}

void Stone::setType(StoneType type)
{
    this->type = type;
    switch(this->type)
    {
        case ST_BLACK: _color = color(0, 0, 0);
                    break;
        case ST_WHITE: _color = color(255, 255, 255);
                    break;
        default: _color = color(128, 128, 128);
    }
}

StoneType Stone::getType() const
{
    return type;
}

color Stone::getColor() const
{
    return _color;
}

bool Stone::isEmpty()
{
    return type == ST_EMPTY;
}
