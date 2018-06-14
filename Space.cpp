/******************************************************************************
Program Name: Space Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Space class implementation file.
*******************************************************************************/

#include "Space.h"

Space::Space()
{
    top = nullptr;
    right = nullptr;
    bottom = nullptr;
    left = nullptr;
}

std::string Space::getSpaceName()
{
    return spaceName;
}

void Space::setRightSpace(Space *r)
{
    right = r;
}

Space *Space::getRightSpace()
{
    return right;
}

void Space::explore(Inventory* items)
{
    //empty
}

Space::~Space()
{
    //delete top;
    //delete right;
    //delete bottom;
    //delete left;
}