/********************************************************************* **
 *  * Program name: forest.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Definitions for the Forest class
 ** *********************************************************************/

#include "forest.hpp"

/***********************************************************************
 * set name to Forest
 * ********************************************************************/
Forest::Forest()
{
    roomName = "Forest";
}

/***********************************************************************
 * Define interaction that happens when user enters the Forest area. An integer 
 * is returned that will signal what happens as a result of that interaction.
 * User gets a choice in deciding where the game will go from here. Results
 * of the interaction are in the Game class function run().
 * ********************************************************************/
int Forest::interaction()
{
    cout << "You are now in the Forest! The smells are so diverse here, and the grass is slightly damp underneath your paws." << endl; 
    cout << "There's a fallen tree that crosses the path and a small stream passing on the right side of the trail. " << endl;
    cout << "Maybe what you're looking for is in the tree or near the stream?" << endl;
    cout << "Do you want to check the tree? Or investigate the stream?" << endl;
    cout << "1. Check tree." << endl;
    cout << "2. Investigate stream." << endl;
    int choice = inputValidation();
    while (!(rangeChecker(choice, 1, 2)))
	{
		cout << "Please enter an integer in range between 1 to 2." << endl;
		choice = inputValidation();
	}

    if (choice == 1)
    {
        cout << "You approach the fallen tree carefully. There's a hole on the outside that leads to the hollow inside!" << endl;
        cout << "Sticking your head into the hole, you see something glimmer a foot or two in front of you." << endl;
        int chance = rand()%2; //50-50 chance of getting the ribbon
        if (chance == 1)
        {
            cout << "Upon further inspection, you find a shiny ribbon! You decide to keep it." << endl;
            cout << "                           |\\_/| " << endl;
            cout << "                           |_/\\|" << endl;
            return 4;
        }
        else
        {
            cout << "Upon further inspection, it looks just like a slug trail!" << endl;
            cout << "Good thing you didn't step on it! You find nothing of note." << endl;
        }
    }

    else if (choice == 2)
    {
        cout << "The sound of the stream is calming as you get closer to investigate." << endl;
        cout << "You hear birds chirping, but alas, none are near enough to you!" << endl;
        cout << "The lullaby of the stream and the fresh air has rejuvenated you though!" << endl;
        cout << "You get an extra hour." << endl;
        return 1;
    }
    
}


