/******************************************************************************
Program Name: Character Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Character class specification file.
*******************************************************************************/

#ifndef FINAL_CHARACTER_H
#define FINAL_CHARACTER_H

#include "Space.h"
#include <string>

class Character {
protected:
    int air;
    int health;
    int strength;
    int ammo;
    Space *location;
    Inventory *backpack;

public:
    Character();    //Default constructor
    virtual ~Character();   //Destructor
    virtual void setHealth(int);   //Sets or adjusts health
    virtual void setLocation(Space *);  //Sets the location of the character
    virtual Space *getLocation();   //Returns what location the character is in
    virtual Space *getRightSpace(); //Returns what space is to the right of the character
    virtual std::string getLocationName();  //Gets the name of the location the player is in
    virtual int attack();   //Attack function
    virtual int getHealth();    //Returns the health value
    virtual void addAir(int);   //Adds air if the player has air canisters to use
    virtual void decreaseAir(); //Decrease air for player
    virtual int getAir();   //Returns the air value
    virtual void addAmmo(int);  //Adds ammo to the players total ammo
    virtual int getAmmoCount(); //Get the amount of ammo you have
    virtual void exploreSpace(Inventory*, Character*, Character*);    //Explore the space the player is in
};


#endif //FINAL_CHARACTER_H
