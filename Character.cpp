/******************************************************************************
Program Name: Character Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Character class implementation file.
*******************************************************************************/
#include <iostream>
#include "Character.h"

Character::Character()
{
    air = 0;
    health = 0;
    strength = 0;
    ammo = 0;
}

Character::~Character()
{
    //empty
}

void Character::setHealth(int h)
{
    health = health - h;
}

void Character::setLocation(Space *loc)
{
    location = loc;
}

Space *Character::getLocation()
{
    return location;
}

Space *Character::getRightSpace()
{
    return location->getRightSpace();
}

std::string Character::getLocationName()
{
    return location->getSpaceName();
}

int Character::attack()
{
    strength = rand() % 15 + 1;

    return strength;
}

int Character::getHealth()
{
    return health;
}

void Character::addAir(int a)
{
    air = air + a;
}

void Character::decreaseAir()
{
    air = air - 5;

    std::cout << "Remaining air: " << air << std::endl << std::endl;
}

int Character::getAir()
{
    return air;
}

void Character::addAmmo(int a)
{
    ammo = ammo + a;
}

int Character::getAmmoCount()
{
    return ammo;
}

void Character::exploreSpace(Inventory *pack, Character *player, Character *alien)
{
    if(location->getSpaceName() == "Main Deck")
    {
        int playerChoice;
        int count = 0;

        std::cout << "Sirens are blaring, lights are flickering, and sparks are flying." << std::endl;
        std::cout << "You grab the pack at your feet and look around for anything you might need. You can only carry 5 items total." << std::endl << std::endl;

        std::cout << "You look around and see the following items:" << std::endl;
        std::cout << "1.Air Canister (50 air)" << std::endl;
        std::cout << "2.Flashlight" << std::endl;
        std::cout << "3.First Aid Kit (25 health)" << std::endl;
        std::cout << "4.Radar (will let you know where the alien is, but forever takes up one slot)" << std::endl << std::endl;

        std::cout << "Please select 2 items to take." << std::endl;

        do{
            std::cin >> playerChoice;

            while(!std::cin || playerChoice > 4 || playerChoice < 1)
            {
                std::cout << "Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> playerChoice;
            }

            switch(playerChoice)
            {
                case 1: pack->addItem("air");
                    std::cout << "You have selected an air canister." << std::endl;
                    break;
                case 2: pack->addItem("flashlight");
                    std::cout << "You have selected a flashlight." << std::endl;
                    break;
                case 3: pack->addItem("health");
                    std::cout << "You have selected a first aid kit." << std::endl;
                    break;
                case 4: pack->addItem("radar");
                    std::cout << "You have selected the radar." << std::endl;
                    std::cout << "Alien Location: " << alien->getLocationName() << std::endl;
                    break;
            }

            count++;
        }while(count < 2);

        std::cout << "You load up your pack and head to your quarters to check if the key is there." << std::endl;

        player->decreaseAir();
    }
    else if(location->getSpaceName() == "Captain Quarters")
    {
        int playerChoice;
        int secondChoice;
        int damage;
        int alienAttack;

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

        if(playerChoice == 1)
        {
            damage = rand() % 2 + 1;

            if(damage == 1)
            {
                std::cout << "You do not get shocked." << std::endl;
            }
            else if(damage == 2)
            {
                std::cout << "Oh no the switch shocked you and you lost 5 health." << std::endl;

                player->setHealth(5);

                std::cout << "Your health now is: " << player->getHealth() << std::endl;
            }
        }

        //If the alien is in this room then start fight
        if(alien->getLocationName() == "Captain Quarters")
        {
            std::cout << "OH NO!! A giant foul beast stands in front of you. It snarls and you see it's razor sharp teeth." << std::endl;
            std::cout << "You draw out your weapon." << std::endl;

            do{
                std::cout << "1.Fire" << std::endl;
                std::cout << "2.Dodge" << std::endl;
                std::cin >> playerChoice;

                if(playerChoice == 1)
                {
                    std::cout << "You fire your weapon." << std::endl;
                    damage = player->attack();
                    std::cout << "Damage: " << damage << std::endl;
                    alien->setHealth(damage);
                    std::cout << "Alien's Health: " << alien->getHealth() << std::endl;

                    std::cout << "The alien attacks back." << std::endl;
                    alienAttack = alien->attack();
                    std::cout << "Damage: " << alienAttack << std::endl;
                    player->setHealth(alienAttack);
                    std::cout << "Player's Health: " << player->getHealth() << std::endl;
                }
                else if(playerChoice == 2)
                {
                    std::cout << "The alien swipes at you." << std::endl;
                    std::cout << "It misses." << std::endl;
                }

            }while(player->getHealth() > 0 && alien->getHealth() >0);
        }

        //If the player lives then continue
        if(player->getHealth() > 0 && player->getAir() > 0)
        {
            do{
                std::cout << "You look around the room. Please choose a following action: " << std::endl;
                std::cout << "1. Open bunker" << std::endl;
                std::cout << "2. Open closet" << std::endl;
                std::cout << "3. Open drawers" << std::endl;
                std::cout << "4. Leave" << std::endl;
                std::cin >> playerChoice;

                while(!std::cin || playerChoice < 1 || playerChoice > 4)
                {
                    std::cout << "You look around the room. Please choose a following action: " << std::endl;
                    std::cout << "1. Open bunker" << std::endl;
                    std::cout << "2. Open closet" << std::endl;
                    std::cout << "3. Open drawers" << std::endl;
                    std::cout << "4. Leave" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> playerChoice;
                }

                if(playerChoice == 1)
                {
                    std::cout << "You open your bunker and see it has the following items (choose one):" << std::endl;
                    std::cout << "1. Ammo (+10)" << std::endl;
                    std::cout << "2. Air Canister (50 air)" << std::endl;
                    std::cin >> secondChoice;

                    switch(secondChoice)
                    {
                        case 1: std::cout << "You have added ammo to your total ammo." << std::endl;
                            player->addAmmo(10);
                            std::cout << "You now have " << player->getAmmoCount() << std::endl;
                            break;
                        case 2: std::cout << "You have added an air canister to your backpack." << std::endl;
                            pack->addItem("air");
                            break;
                    }
                }
                else if(playerChoice == 2)
                {
                    std::cout << "The closet is empty." << std::endl;
                }
                else if(playerChoice == 3)
                {
                    std::cout << "You only see clothes." << std::endl;
                }

                player->decreaseAir();

            }while(playerChoice != 4);
        }

    }
    else if(location->getSpaceName() == "Kitchen")
    {
        int playerChoice;
        int secondChoice;
        int damage;
        int alienAttack;

        std::cout << "You enter the kitchen and see fires raging. The longer you stay here the longer you get burned and lose 1 health." << std::endl;
        std::cout << "You quickly look around for the key and see nothing." << std::endl;

        //If the alien is in this room then start fight
        if(alien->getLocationName() == "Kitchen")
        {
            std::cout
                    << "OH NO!! A giant foul beast stands in front of you. It snarls and you see it's razor sharp teeth." << std::endl;
            std::cout << "You draw out your weapon." << std::endl;

            do {
                std::cout << "1.Fire" << std::endl;
                std::cout << "2.Dodge" << std::endl;
                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    std::cout << "You fire your weapon." << std::endl;
                    damage = player->attack();
                    std::cout << "Damage: " << damage << std::endl;
                    alien->setHealth(damage);
                    std::cout << "Alien's Health: " << alien->getHealth() << std::endl;

                    std::cout << "The alien attacks back." << std::endl;
                    alienAttack = alien->attack();
                    std::cout << "Damage: " << alienAttack << std::endl;
                    player->setHealth(alienAttack);
                    std::cout << "Player's Health: " << player->getHealth() << std::endl;
                } else if (playerChoice == 2) {
                    std::cout << "The alien swipes at you." << std::endl;
                    std::cout << "It misses." << std::endl;
                }

            } while (player->getHealth() > 0 && alien->getHealth() > 0);
        }

        if(player->getHealth() > 0 && player->getAir() > 0)
        {
            std::cout << "What do you do next?" << std::endl;

            do{
                std::cout << "1.Open Cabinets" << std::endl;
                std::cout << "2.Take a knife" << std::endl;
                std::cout << "3.Leave" << std::endl;
                std::cin >> playerChoice;

                while(!std::cin || playerChoice > 3 || playerChoice < 1)
                {
                    std::cout << "Try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> playerChoice;
                }

                if(playerChoice == 1)
                {
                    std::cout << "The cabinets contain the following:" << std::endl;
                    std::cout << "1.Kitchenware" << std::endl;
                    std::cout << "2.Food" << std::endl;
                    std::cout << "3.A weird looking device" << std::endl;
                    std::cout << "Choose one item." << std::endl;
                    std::cin >> secondChoice;

                    while(!std::cin || secondChoice > 3 || secondChoice < 1)
                    {
                        std::cout << "Try again." << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                        std::cin >> secondChoice;
                    }

                    switch(secondChoice)
                    {
                        case 1: std::cout << "Don't know why, but you chose kitchenware." << std::endl;
                            pack->addItem("kitchenware");
                            break;
                        case 2: std::cout << "You chose food." << std::endl;
                            pack->addItem("food");
                            break;
                        case 3: std::cout << "You grabbed the weird looking device." << std::endl;
                            pack->addItem("device");
                            break;
                    }
                }
                else if(playerChoice == 2)
                {
                    pack->addItem("knife");
                }

                player->decreaseAir();

                player->setHealth(1);

            }while(playerChoice != 3);

            std::cout << "You run out of the burning kitchen and into the Cargo Hold." << std::endl;
        }
    }
    else if(location->getSpaceName() == "Cargo Hold")
    {
        int playerChoice;
        int damage;
        int alienAttack;

        std::cout << "You enter the Cargo Hold and there is stuff everywhere. You don't even know where to begin looking." << std::endl;

        //If the alien is in this room then start fight
        if(alien->getLocationName() == "Cargo Hold")
        {
            std::cout
                    << "OH NO!! A giant foul beast stands in front of you. It snarls and you see it's razor sharp teeth." << std::endl;
            std::cout << "You draw out your weapon." << std::endl;

            do {
                std::cout << "1.Fire" << std::endl;
                std::cout << "2.Dodge" << std::endl;
                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    std::cout << "You fire your weapon." << std::endl;
                    damage = player->attack();
                    std::cout << "Damage: " << damage << std::endl;
                    alien->setHealth(damage);
                    std::cout << "Alien's Health: " << alien->getHealth() << std::endl;

                    std::cout << "The alien attacks back." << std::endl;
                    alienAttack = alien->attack();
                    std::cout << "Damage: " << alienAttack << std::endl;
                    player->setHealth(alienAttack);
                    std::cout << "Player's Health: " << player->getHealth() << std::endl;
                } else if (playerChoice == 2) {
                    std::cout << "The alien swipes at you." << std::endl;
                    std::cout << "It misses." << std::endl;
                }

            } while (player->getHealth() > 0 && alien->getHealth() > 0);
        }

        if(player->getHealth() > 0 && player->getAir() > 0)
        {
            std::cout << "You know you are running out of time, but you still need to find the key." << std::endl;

            do{
                std::cout << "Where do you search?" << std::endl;
                std::cout << "1.Lockers" << std::endl;
                std::cout << "2.Ammo Boxes" << std::endl;
                std::cout << "3.Leave" << std::endl;
                std::cin >> playerChoice;

                while(!std::cin || playerChoice > 3 || playerChoice < 1)
                {
                    std::cout << "Try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> playerChoice;
                }

                if(playerChoice == 1)
                {
                    std::cout << "The locker just has shoes." << std::endl;
                }
                else if(playerChoice == 2)
                {
                    std::cout << "The boxes are empty." << std::endl;
                }

                player->decreaseAir();

            }while(playerChoice != 3);
        }
    }
    else if(location->getSpaceName() == "Engine Room")
    {
        int playerChoice;
        int secondChoice;
        int damage;
        int alienAttack;

        std::cout << "You run into the engine room and you are in complete darkness." << std::endl;
        std::cout << "You hit the light switch, and the room lights up." << std::endl;

        //If the alien is in this room then start fight
        if(alien->getLocationName() == "Engine Room")
        {
            std::cout
                    << "OH NO!! A giant foul beast stands in front of you. It snarls and you see it's razor sharp teeth." << std::endl;
            std::cout << "You draw out your weapon." << std::endl;

            do {
                std::cout << "1.Fire" << std::endl;
                std::cout << "2.Dodge" << std::endl;
                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    std::cout << "You fire your weapon." << std::endl;
                    damage = player->attack();
                    std::cout << "Damage: " << damage << std::endl;
                    alien->setHealth(damage);
                    std::cout << "Alien's Health: " << alien->getHealth() << std::endl;

                    std::cout << "The alien attacks back." << std::endl;
                    alienAttack = alien->attack();
                    std::cout << "Damage: " << alienAttack << std::endl;
                    player->setHealth(alienAttack);
                    std::cout << "Player's Health: " << player->getHealth() << std::endl;
                } else if (playerChoice == 2) {
                    std::cout << "The alien swipes at you." << std::endl;
                    std::cout << "It misses." << std::endl;
                }

            } while (player->getHealth() > 0 && alien->getHealth() > 0);
        }

        if(player->getHealth() > 0 && player->getAir() > 0)
        {
            std::cout << "You see a box in the room." << std::endl;
            std::cout << "Open?" << std::endl;
            std::cout << "1.Yes" << std::endl;
            std::cout << "2.No" << std::endl;
            std::cin >> playerChoice;

            while(!std::cin || playerChoice > 2 || playerChoice < 1)
            {
                std::cout << "Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> playerChoice;
            }

            if(playerChoice == 1)
            {
                std::cout << "The box contains the following items:" << std::endl;
                std::cout << "1.Ammo(+10)" << std::endl;
                std::cout << "2.Key" << std::endl;
                std::cout << "3.Air Canister(25 air)" << std::endl;
                std::cout << "Choose one." << std::endl;
                std::cin >> secondChoice;

                while(!std::cin || secondChoice > 3 || secondChoice < 1)
                {
                    std::cout << "Try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> secondChoice;
                }

                switch(secondChoice)
                {
                    case 1: std::cout << "You add 10 ammo to your total." << std::endl;
                        addAmmo(10);
                        std::cout << "You have " << getAmmoCount() << " ammo." << std::endl;
                        break;
                    case 2: std::cout << "You grab the key." << std::endl;
                        pack->addItem("key");
                        break;
                    case 3: std::cout << "You grab the air canister" << std::endl;
                        pack->addItem("air");
                        break;
                }
            }

            if(pack->haveItem() == true)
            {
                std::cout << "Do you want to try the key?" << std::endl;
                std::cout << "1.Yes" << std::endl;
                std::cout << "2.No" << std::endl;
                std::cin >> playerChoice;

                while(!std::cin || playerChoice > 2 || playerChoice < 1)
                {
                    std::cout << "Try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> playerChoice;
                }
            }
            while(pack->haveItem() == false)
            {
                std::cout << "You don't have the key to open the door. You open the box." << std::endl;
                std::cout << "1.Ammo(+10)" << std::endl;
                std::cout << "2.Key" << std::endl;
                std::cout << "3.Air Canister(25 air)" << std::endl;
                std::cout << "Choose one." << std::endl;
                std::cin >> secondChoice;

                while(!std::cin || secondChoice > 3 || secondChoice < 1)
                {
                    std::cout << "Try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> secondChoice;
                }

                switch(secondChoice)
                {
                    case 1: std::cout << "You add 10 ammo to your total." << std::endl;
                        addAmmo(10);
                        std::cout << "You have " << getAmmoCount() << " ammo." << std::endl;
                        break;
                    case 2: std::cout << "You grab the key." << std::endl;
                        pack->addItem("key");
                        break;
                    case 3: std::cout << "You grab the air canister" << std::endl;
                        pack->addItem("air");
                        break;
                }
            }

            player->decreaseAir();
        }
    }
    else if(location->getSpaceName() == "Docking Bay")
    {
        int playerChoice;
        int damage;
        int alienAttack;

        std::cout << "You enter the docking bay practically out of breath. You see the ship there perfectly unharmed." << std::endl;

        //If the alien is in this room then start fight
        if(alien->getLocationName() == "Kitchen")
        {
            std::cout
                    << "OH NO!! A giant foul beast stands in front of you. It snarls and you see it's razor sharp teeth." << std::endl;
            std::cout << "You draw out your weapon." << std::endl;

            do {
                std::cout << "1.Fire" << std::endl;
                std::cout << "2.Dodge" << std::endl;
                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    std::cout << "You fire your weapon." << std::endl;
                    damage = player->attack();
                    std::cout << "Damage: " << damage << std::endl;
                    alien->setHealth(damage);
                    std::cout << "Alien's Health: " << alien->getHealth() << std::endl;

                    std::cout << "The alien attacks back." << std::endl;
                    alienAttack = alien->attack();
                    std::cout << "Damage: " << alienAttack << std::endl;
                    player->setHealth(alienAttack);
                    std::cout << "Player's Health: " << player->getHealth() << std::endl;
                } else if (playerChoice == 2) {
                    std::cout << "The alien swipes at you." << std::endl;
                    std::cout << "It misses." << std::endl;
                }

            } while (player->getHealth() > 0 && alien->getHealth() > 0);
        }

        if(player->getHealth() > 0)
        {
            std::cout << "You have reached your goal. Congratulations." << std::endl;
        }
    }
}