/******************************************************************************
Program Name: Captain Quarters Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Captain Quarters class implementation file.
*******************************************************************************/
#include <iostream>
#include "CaptQuarters.h"

CaptQuarters::CaptQuarters()
{
    top = nullptr;
    right = nullptr;
    bottom = nullptr;
    left = nullptr;
    spaceName = "Captain Quarters";
}

/*
void CaptQuarters::explore(Inventory *items)
{
    int playerChoice;
    int damage;

    std::cout << "The doors to your quarters open and you see the lights are out." << std::endl;
    std::cout << "You look at the light switch and see it sparking. There is a chance it can electrocute you." << std::endl;
    std::cout << "Do you try the light switch?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    std::cin >> playerChoice;

    while(!std::cin || playerChoice > 2 || playerChoice < 1)
    {
        std::cout << "ERROR! Please try again." << std::endl;
        std::cout << "Do you try the light switch?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> playerChoice;
    }
}
 */