/******************************************************************************
Program Name: Inventory Class
Author: Matthew Esqueda
Date: June 12, 2018
Description: Inventory class specification file.
*******************************************************************************/

#ifndef FINAL_INVENTORY_H
#define FINAL_INVENTORY_H

#include <string>
#include <vector>

class Inventory {
private:
    int maxItems;
    int itemCount;
    std::string itemName;
    std::vector <std::string> backpack;

public:
    Inventory();
    ~Inventory();
    void addItem(std::string);  //Function that adds an item to the backpack
    int getTotalItemCount();    //Returns the total amount of items you have
    void printItems();  //Prints out what items you have
    bool maxCap();      //Checks to see if the backpack is full
    std::string useItem();  //Lets the player select an item to use
    void removeItem(std::string);
    bool haveItem();
};


#endif //FINAL_INVENTORY_H
