/******************************************************************************
Program Name: Game Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Game class specification file.
*******************************************************************************/

#ifndef FINAL_GAME_H
#define FINAL_GAME_H

#include "Space.h"
#include "MainDeck.h"
#include "CaptQuarters.h"
#include "EngineRoom.h"
#include "DockingBay.h"
#include "Kitchen.h"
#include "CargoHold.h"
#include "Character.h"
#include "Player.h"
#include "Alien.h"
#include "Inventory.h"

class Game {
private:
    Space *mainDeck;
    Space *captQuarters;
    Space *cargoHold;
    Space *dockingBay;
    Space *engineRoom;
    Space *kitchen;
    Character *player;
    Character *alien;
    Inventory *backpack;

public:
    Game();     //Default constructor
    ~Game();    //Destructor
    void createEnv();   //Creates the environment
    void setAlienLocation();    //Randomly sets the location of the alien
    void setLocation(Space *);  //Sets the location of the player
    void printPlayerStats();    //Prints the stats of the player
    std::string getLocationInfo();  //Gets the info about the current space the player is in
    void moveRooms();   //Moves player to the next room
    void printMap();    //Prints the current map
    void useItems(Inventory*);
    void playGame();    //Plays the game

};


#endif //FINAL_GAME_H
