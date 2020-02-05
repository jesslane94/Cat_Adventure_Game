/********************************************************************* **
 *  * Program name: main.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: The main for running the Cat game.
 ** *********************************************************************/

 #include <iostream>
 #include <cstdlib>
 #include "menu.hpp"
 #include "inputValidation.hpp"
 #include "rangeChecker.hpp"
 #include "time.h"
 #include "game.hpp"

 using std::cout;
 using std::endl;
 
int main()
{
    srand(time(0)); //set random seed
    int choice = menu();

    while (choice != 2)
    {
        Game game;
        game.run();
        choice = menu();
    }

    if (choice == 2)
    {
        cout << "Thanks for playing!" << endl;
        return 0;
    }
}