/******************************************************************************
Program Name: Space Escape Game
Author: Matthew Esqueda
Date: June 12, 2018
Description: Game where the player has to get to the docking bay of the ship
             and have to find a key on their way.
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "menu.h"

int main() {

    unsigned seed = time(0);
    srand(seed);
    //Put title card here
    std::cout << "SPACE ESCAPE" << std::endl;

    std::cout << "Your ship has just been attacked. You check the ship's systems and" << std::endl;
    std::cout << "see that you are dead in the water. You announce over the intercom" << std::endl;
    std::cout << "for all crew to abandon ship. You hear screams come back through  " << std::endl;
    std::cout << "the speaker system. You hear someone say ""ALIEN!!!"" You look at a   " << std::endl;
    std::cout << "camera and see some creature. The camera turns to static. You see " << std::endl;
    std::cout << "a lone ship in the docking bay. You need to get to that ship. You " << std::endl;
    std::cout << "then notice the door to the docking bay is locked. You will need  " << std::endl;
    std::cout << "to find the key in one of the rooms. You also see that air is     " << std::endl;
    std::cout << " leaking out of the ship. You take a deep breath and..." << std::endl << std::endl;

    menu();

    return 0;
}