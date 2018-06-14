/******************************************************************************
Program Name: Space Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Space class specification file.
*******************************************************************************/

#ifndef FINAL_SPACE_H
#define FINAL_SPACE_H

#include <string>
#include "Inventory.h"

class Space {
protected:
    Space *top;
    Space *right;
    Space *bottom;
    Space *left;
    std::string spaceName;
    Inventory *pack;

public:
    Space();    //Default constructor
    virtual ~Space();   //Destructor
    virtual std::string getSpaceName(); //returns the name of the space
    virtual void setRightSpace(Space*); //Sets the space to the right of the current space
    virtual Space *getRightSpace(); //Returns the space to the right of the current space
    virtual void explore(Inventory*); //Explore the space
};


#endif //FINAL_SPACE_H
