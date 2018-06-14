/******************************************************************************
Program Name: Game Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Game class implementation file.
*******************************************************************************/
#include <iostream>
#include <string>
#include "Game.h"

Game::Game()
{
    mainDeck = new MainDeck;
    captQuarters = new CaptQuarters;
    kitchen = new Kitchen;
    cargoHold = new CargoHold;
    engineRoom = new EngineRoom;
    dockingBay = new DockingBay;
    player = new Player;
    alien = new Alien;
    backpack = new Inventory;
}

Game::~Game()
{
    delete mainDeck;
    delete captQuarters;
    delete kitchen;
    delete cargoHold;
    delete engineRoom;
    delete dockingBay;
    delete player;
    delete alien;
    delete backpack;
}

void Game::createEnv()
{
    mainDeck->setRightSpace(captQuarters);
    captQuarters->setRightSpace(kitchen);
    kitchen->setRightSpace(cargoHold);
    cargoHold->setRightSpace(engineRoom);
    engineRoom->setRightSpace(dockingBay);
}

void Game::setAlienLocation()
{
    int space;

    space = (rand() % (6 - 2 + 1)) + 2;

    std::cout << space << std::endl << std::endl;

    switch(space)
    {
        case 2: alien->setLocation(captQuarters);
            break;
        case 3: alien->setLocation(kitchen);
            break;
        case 4: alien->setLocation(cargoHold);
            break;
        case 5: alien->setLocation(engineRoom);
            break;
        case 6: alien->setLocation(dockingBay);
            break;
    }
}

void Game::setLocation(Space *location)
{
    player->setLocation(location);
}

void Game::printPlayerStats()
{
    std::cout << "Player's current stats are." << std::endl;
    std::cout << "Health: " << player->getHealth() << std::endl;
    std::cout << "Air: " << player->getAir() << std::endl;
}

std::string Game::getLocationInfo()
{
    return player->getLocationName();
}

void Game::moveRooms()
{
    Space *tempLocation;

    tempLocation = player->getRightSpace();

    setLocation(tempLocation);
}

void Game::printMap()
{
    if(getLocationInfo() == "Main Deck")
    {
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl;
        std::cout << "|               |               |               |               |               |               |" << std::endl;
        std::cout << "|    Main       |     Capt      |               |    Cargo      |   Engine      |    Docking    |" << std::endl;
        std::cout << "|    Deck           Quarters        Kitchen          Hold            Room              Bay      |" << std::endl;
        std::cout << "|     | |       |               |               |               |               |               |" << std::endl;
        std::cout << "|     ____      |               |               |               |               |               |" << std::endl;
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl << std::endl << std::endl;
    }
    else if(getLocationInfo() == "Captain Quarters")
    {
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl;
        std::cout << "|               |               |               |               |               |               |" << std::endl;
        std::cout << "|    Main       |     Capt      |               |    Cargo      |   Engine      |    Docking    |" << std::endl;
        std::cout << "|    Deck           Quarters        Kitchen          Hold            Room              Bay      |" << std::endl;
        std::cout << "|               |     | |       |               |               |               |               |" << std::endl;
        std::cout << "|               |    _____      |               |               |               |               |" << std::endl;
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl << std::endl << std::endl;
    }
    else if(getLocationInfo() == "Kitchen")
    {
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl;
        std::cout << "|               |               |               |               |               |               |" << std::endl;
        std::cout << "|    Main       |     Capt      |               |    Cargo      |   Engine      |    Docking    |" << std::endl;
        std::cout << "|    Deck           Quarters        Kitchen          Hold            Room              Bay      |" << std::endl;
        std::cout << "|               |               |     | |       |               |               |               |" << std::endl;
        std::cout << "|               |               |     ___       |               |               |               |" << std::endl;
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl << std::endl << std::endl;
    }
    else if(getLocationInfo() == "Cargo Hold")
    {
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl;
        std::cout << "|               |               |               |               |               |               |" << std::endl;
        std::cout << "|    Main       |     Capt      |               |    Cargo      |   Engine      |    Docking    |" << std::endl;
        std::cout << "|    Deck           Quarters        Kitchen          Hold            Room              Bay      |" << std::endl;
        std::cout << "|               |               |               |     | |       |               |               |" << std::endl;
        std::cout << "|               |               |               |     ___       |               |               |" << std::endl;
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl << std::endl << std::endl;
    }
    else if(getLocationInfo() == "Engine Room")
    {
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl;
        std::cout << "|               |               |               |               |               |               |" << std::endl;
        std::cout << "|    Main       |     Capt      |               |    Cargo      |   Engine      |    Docking    |" << std::endl;
        std::cout << "|    Deck           Quarters        Kitchen          Hold            Room              Bay      |" << std::endl;
        std::cout << "|               |               |               |               |     | |       |               |" << std::endl;
        std::cout << "|               |               |               |               |     ___       |               |" << std::endl;
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl << std::endl << std::endl;
    }
    else if(getLocationInfo() == "Docking Bay")
    {
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl;
        std::cout << "|               |               |               |               |               |               |" << std::endl;
        std::cout << "|    Main       |     Capt      |               |    Cargo      |   Engine      |    Docking    |" << std::endl;
        std::cout << "|    Deck           Quarters        Kitchen          Hold            Room              Bay      |" << std::endl;
        std::cout << "|               |               |               |               |               |     | |       |" << std::endl;
        std::cout << "|               |               |               |               |               |    _____      |" << std::endl;
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl << std::endl << std::endl;
    }
    else
    {
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl;
        std::cout << "|               |               |               |               |               |               |" << std::endl;
        std::cout << "|    Main       |     Capt      |               |    Cargo      |   Engine      |    Docking    |" << std::endl;
        std::cout << "|    Deck           Quarters        Kitchen          Hold            Room              Bay      |" << std::endl;
        std::cout << "|               |               |               |               |               |               |" << std::endl;
        std::cout << "|               |               |               |               |               |               |" << std::endl;
        std::cout << "|---------------|---------------|---------------|---------------|---------------|---------------|" << std::endl << std::endl << std::endl;
    }
}

void Game::useItems(Inventory *pack)
{
    int choice;
    std::string item;

    std::cout << "Would you like to use an item before going into the next room?" << std::endl;
    std::cout << "1.Yes" << std::endl;
    std::cout << "2.No" << std::endl;
    std::cin >> choice;

    if(choice == 1)
    {
        //Store the users choice into variable item
        item = pack->useItem();

        if(item == "air")
        {
            player->addAir(50);
        }
        else if(item == "health")
        {
            player->setHealth(-25);
        }
    }
    else
    {
        std::cout << "Ok." << std::endl;
    }
}

void Game::playGame()
{
    int playerAction;
    int playerAttack;
    int enemyAttack;

    //Create the environment at the start of the game
    createEnv();

    //Randomly set the location of the alien
    setAlienLocation();

    //Set the player's starting location
    setLocation(mainDeck);

    do{
        //Print the map
        printMap();

        std::cout << "Location: " << getLocationInfo() << std::endl;

        //Print the player's stats
        printPlayerStats();

        //Explore the space the player is in
        player->exploreSpace(backpack, player, alien);

        if(player->getHealth() > 0 && player->getAir() > 0)
        {
            //Print out what the backpack currently contains
            backpack->printItems();

            useItems(backpack);
            if(getLocationInfo() != "Docking Bay")
            {
                //Move the player to the next location
                moveRooms();
            }
        }

    }while(player->getHealth() > 0 && player->getAir() > 0 && getLocationInfo() != "Docking Bay");

    if(player->getHealth() > 0 && player->getAir() > 0)
    {
        player->exploreSpace(backpack, player, alien);
    }

    if(player->getHealth() <= 0 && player->getAir() <= 0)
    {
        std::cout << "GAME OVER" << std::endl;
    }
}