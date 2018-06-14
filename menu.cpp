/******************************************************************************
Program Name: Menu Function
Author: Matthew Esqueda
Date: June 12, 2018
Description: Menu implementation file.
*******************************************************************************/
#include <iostream>
#include "Game.h"

void menu()
{
    int usersChoice;
    Game start;

    std::cout << "1. Play" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cin >> usersChoice;

    while(!std::cin || usersChoice > 2 || usersChoice < 1)
    {
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> usersChoice;
    }

    if(usersChoice == 1)
    {
        start.playGame();
    }
}