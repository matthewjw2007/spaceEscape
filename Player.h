/******************************************************************************
Program Name: Player Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Player class specification file.
*******************************************************************************/

#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H

#include "Character.h"

class Player: public Character {
public:
    Player();
    virtual std::string getLocationName();  //Gets the name of the location the player is in
    virtual int attack();
};


#endif //FINAL_PLAYER_H
