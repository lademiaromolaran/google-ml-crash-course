#include "Player.h"

Player::Player(StoneType stoneType)
:stoneType(stoneType), placedStones(0), territoryCount(0),
 capturedStones(0), timerStart(0), timerSeconds(0), isPaused(true){}

void Player::startTimer()
{
    time(&timerStart);
    isPaused = false;
}

void Player::pauseTimer()
{
    if(!isPaused)
    {
        time_t endTime = 0;
        time(&endTime);

        timerSeconds += difftime(endTime, timerStart);
    }

    isPaused = true;
}

unsigned int Player::getTimerSeconds() const
{
    unsigned int seconds = timerSeconds;

    if(!isPaused)
    {
        time_t endTime = 0;
        time(&endTime);

        seconds += difftime(endTime, timerStart);
    }

    return seconds;
}

int Player::getScore() const
{
    return placedStones + territoryCount + capturedStones;
}

StoneType Player::getStoneType() const
{
    return stoneType;
}

int Player::getPlacedStones() const
{
    return placedStones;
}

void Player::addStones(int stones)
{
    placedStones += stones;
}

void Player::removeStones(int stones)
{
    if(placedStones - stones < 0)
    {
        throw GoGameException("Player::removeStones | Negative placed stones");
    }
    placedStones -= stones;
}

void Player::setTerritoryCount(int territory)
{
    territoryCount = territory;
}

void Player::addCapturedStones(int stones)
{
    capturedStones += stones;
}
