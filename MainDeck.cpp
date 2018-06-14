/******************************************************************************
Program Name: Main Deck Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Main Deck class implementation file.
*******************************************************************************/
#include <iostream>
#include "MainDeck.h"

MainDeck::MainDeck()
{
    top = nullptr;
    right = nullptr;
    bottom = nullptr;
    left = nullptr;
    spaceName = "Main Deck";
}

/*
void MainDeck::explore(Inventory *items)
{
    int playerChoice;
    int count = 0;

    std::cout << "Sirens are blaring, lights are flickering, and sparks are flying." << std::endl;
    std::cout << "You grab the pack at your feet and look around for anything you might need." << std::endl << std::endl;

    std::cout << "You look around and see the following items:" << std::endl;
    std::cout << "1.Air Canister (50 air)" << std::endl;
    std::cout << "2.Flashlight" << std::endl;
    std::cout << "3.First Aid Kit (25 health)" << std::endl;
    std::cout << "4. Radar (will let you know where the alien currently is)" << std::endl << std::endl;

    std::cout << "Please select 2 items to take." << std::endl;

    do{
        std::cin >> playerChoice;

        switch(playerChoice)
        {
            case 1: items->addItem("air");
            std::cout << "You have selected an air canister." << std::endl;
                break;
            case 2: items->addItem("flashlight");
            std::cout << "You have selected a flashlight." << std::endl;
                break;
            case 3: items->addItem("health");
            std::cout << "You have selected a first aid kit." << std::endl;
                break;
            case 4: items->addItem("radar");
            std::cout << "You have selected the radar." << std::endl;
                break;
        }

        count++;
    }while(count < 2);

    std::cout << "You load up your pack and head to your quarters to check if the key is there." << std::endl;
}
 */