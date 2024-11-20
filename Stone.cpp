#include "Stone.h"

Stone::Stone(StoneType type)
{
    playerWhite = nullptr;
    playerBlack = nullptr;
    setType(type);
}

void Stone::setType(StoneType type)
{
    this->type = type;
    switch(this->type)
    {
        case ST_BLACK: if(playerBlack != nullptr) _color = *playerBlack;
                       else _color = C_BLACK;
                    break;
        case ST_WHITE: if(playerWhite != nullptr) _color = *playerWhite;
                       else _color = C_WHITE;
                    break;
        default: _color = color(128, 128, 128);
    }
}

void Stone::setPlayerWhiteColor(color* wPlayer)
{
    playerWhite = wPlayer;
}

void Stone::setPlayerBlackColor(color* bPlayer)
{
    playerBlack = bPlayer;
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
