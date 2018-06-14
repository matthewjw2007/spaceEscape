/******************************************************************************
Program Name: Player Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Player class implementation file.
*******************************************************************************/

#include "Player.h"

Player::Player()
{
    location = nullptr;
    air = 100;
    health = 100;
    strength = 0;
    ammo = 16;
}

std::string Player::getLocationName()
{
    return location->getSpaceName();
}

int Player::attack()
{
    strength = rand() % 25 + 1;

    return strength;
}