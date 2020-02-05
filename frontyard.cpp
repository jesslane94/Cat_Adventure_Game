/********************************************************************* **
 *  * Program name: frontyard.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: definitions for the FrontYard class
 ** *********************************************************************/

#include "frontyard.hpp"
#include "barn.hpp"

/***********************************************************************
 * set name of area
 * ********************************************************************/
FrontYard::FrontYard()
{
    roomName = "Front Yard";
}

/***********************************************************************
 * Define interaction that happens when user enters the Front Yard area. An integer 
 * is returned that will signal what happens as a result of that interaction.
 * User gets a choice in deciding where the game will go from here. Results
 * of the interaction are in the Game class function run().
 * ********************************************************************/
int FrontYard::interaction()
{
    cout << "You are now in the Front Yard! You roll around in the freshly cut grass for a bit!" << endl; 
    cout << "There's a rocky road that the metal beasts rest on and some landmarks like bushes and mini trees. " << endl;
    cout << "Looks like there's food hanging from a tree to attract birds!" << endl;
    cout << "Do you want to check it out? Or check under a metal beast?" << endl;
    cout << "1. Check out bird feeder." << endl;
    cout << "2. Check under metal beast." << endl;
    int choice = inputValidation();
    while (!(rangeChecker(choice, 1, 2)))
	{
		cout << "Please enter an integer in range between 1 to 2." << endl;
		choice = inputValidation();
	}

    if (choice == 1)
    {
        cout << "It looks like the bird feeder is empty. The birds aren't interested, so there are none." << endl;
        cout << "Huffing in exasperation, you just roll around some more in the grass." << endl;
        cout << "Basically, nothing gets done and you just wasted an hour." << endl;
    }
    else if (choice == 2)
    {
        cout << "There's something hiding underneath the metal beast... It's a mouse! You pounce and eat it." << endl;
        cout << "You've gained some energy! You will earn an extra hour!" << endl;
        return 1;
    }
    
}
