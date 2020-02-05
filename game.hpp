/********************************************************************* **
 *  * Program name: game.hpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Header file for the Game class.
 ** *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "space.hpp"
#include "inputValidation.hpp"
#include "rangeChecker.hpp"
#include "menu.hpp"
#include "cat.hpp"
#include "frontyard.hpp"
#include "barn.hpp"
#include "forest.hpp"
#include "garden.hpp"
#include "lake.hpp"
#include "shed.hpp"

using std::cout;
using std::endl;

class Game
{
    private:
        Cat player;
        Space *currentLocation;
        Space *frontYard;
        Space *barn;
        Space *forest;
        Space *garden;
        Space *shed;
        Space *lake;
        int hours = 9;

    public:
        void createArea();
        void intro();
        void startingPoint();
        void printArea();
        int gameMenu();
        int moveMenu();
        void moveCat();
        int run();
        void deleteArea();
};

#endif