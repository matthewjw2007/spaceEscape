/******************************************************************************
Program Name: Inventory Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Inventory class implementation file.
*******************************************************************************/

#include "Inventory.h"
#include <iostream>
#include <algorithm>

Inventory::Inventory()
{
    maxItems = 5;
    itemCount = 0;
}

void Inventory::addItem(std::string word)
{
    if(maxCap() == false)
    {
        backpack.push_back(word);

        itemCount++;
    }
    else
    {
        std::cout << "Your backpack is currently full." << std::endl;

        printItems();
    }
}

int Inventory::getTotalItemCount()
{
    return itemCount;
}

void Inventory::printItems()
{
    if(backpack.empty())
    {
        std::cout << "You have no cargo." << std::endl;
    }
    else
    {
        std::cout << "Your backpack contains the following items:" << std::endl;

        for(int a=0; a<itemCount; a++)
        {
            std::cout << a+1 << ". " << backpack.at(a) << std::endl;
        }
    }
}

bool Inventory::maxCap()
{
    bool max = false;

    if(itemCount == maxItems)
    {
        max = true;
        return max;
    }
    else
    {
        return max;
    }
}

std::string Inventory::useItem()
{
    std::string word;

    std::cout << "Please select what item you would like to use." << std::endl;
    printItems();
    std::cout << "Please use the following input to select your item:" << std::endl;
    std::cout << "air" << std::endl;
    std::cout << "health" << std::endl;
    std::cin >> word;

    removeItem(word);

    return word;

}

void Inventory::removeItem(std::string item)
{
    if(item == "air")
    {
        //Code found at https://stackoverflow.com/questions/39912/how-do-i-remove-an-item-from-a-stl-vector-with-a-certain-value
        auto find = std::find(backpack.begin(), backpack.end(), "air");

        if(find != backpack.end())
        {
            backpack.erase(find);

            itemCount--;
        }
        //backpack.erase(std::remove(backpack.begin(), backpack.end(), "air"), backpack.end());
    }
    else if(item == "health")
    {
        //backpack.erase(std::remove(backpack.begin(), backpack.end(), "health"), backpack.end());

        //Code found at https://stackoverflow.com/questions/39912/how-do-i-remove-an-item-from-a-stl-vector-with-a-certain-value
        auto find = std::find(backpack.begin(), backpack.end(), "health");

        if(find != backpack.end())
        {
            backpack.erase(find);

            itemCount--;
        }
    }


}

bool Inventory::haveItem()
{
    bool key = false;

    if(std::find(backpack.begin(), backpack.end(), "key") != backpack.end())
    {
        key = true;

        return key;
    }
    else
    {
        return key;
    }
}

Inventory::~Inventory()
{
}