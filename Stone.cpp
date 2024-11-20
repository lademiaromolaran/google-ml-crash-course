#include "Stone.h"

Stone::Stone(StoneType type)
{
    whitePlayer = nullptr;
    blackPlayer = nullptr;
    setType(type);
}

void Stone::setType(StoneType type)
{
    this->type = type;
    switch(this->type)
    {
        case ST_BLACK: if(blackPlayer != nullptr) _color = *blackPlayer;
                       else _color = C_BLACK;
                    break;
        case ST_WHITE: if(whitePlayer != nullptr) _color = *whitePlayer;
                       else _color = C_WHITE;
                    break;
        default: _color = color(128, 128, 128);
    }
}

void Stone::setWhitePlayerColor(color* wPlayer)
{
    whitePlayer = wPlayer;
}

void Stone::setBlackPlayerColor(color* bPlayer)
{
    blackPlayer = bPlayer;
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
