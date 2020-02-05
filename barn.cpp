/********************************************************************* **
 *  * Program name: barn.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: contains class definitions for Barn
 ** *********************************************************************/

 #include "barn.hpp"
 #include "frontyard.hpp"

/***********************************************************************
 * set area name
 * ********************************************************************/
 Barn::Barn()
 {
    roomName = "Barn";
 }

/***********************************************************************
 * Define interaction that happens when user enters the Barn area. An integer 
 * is returned that will signal what happens as a result of that interaction.
 * User gets a choice in deciding where the game will go from here. Results
 * of the interaction are in the Game class function run().
 * ********************************************************************/
 int Barn::interaction()
 {
    cout << "You are now in the Barn! You catch the scent of hay and horses." << endl; 
    cout << "There's a ladder to the loft where hay is stored and of course, all the stalls where the horses hang." << endl;
    cout << "Do you want to climb the ladder or check out a stall?" << endl;
    cout << "1. Check out the loft." << endl;
    cout << "2. Check out the stalls." << endl;
    int choice = inputValidation();
    while (!(rangeChecker(choice, 1, 2)))
	{
		cout << "Please enter an integer in range between 1 to 2." << endl;
		choice = inputValidation();
	}

    if (choice == 1)
    {
        cout << "You see the prized creature in the corner of your eye! You hide behind a bale of hay to wait for the perfect strike!" << endl;
        int chance = rand()%2; //50/50 chance of getting the bird
        if (chance == 1)
        {
            cout << "It gets closer... and you POUNCE! You have caught a bird!" << endl;
            cout << "                <O) " << endl;
            cout << "                /) )" << endl;
            cout << "              ===#==== " << endl;
            return 3;
        }
        else
        {
            cout << "As you leap out from behind the hay, you crunch on some in the process!" << endl;
            cout << "The bird hears and flies away quickly. Disappointment!!" << endl;
        }

    }
    else if (choice == 2)
    {
        cout << "You jump up on top of a door stall and end up hanging out with the horses!" << endl;
        cout << "Due to your distraction, you lose an extra hour!" << endl;
        return 2;
    }
}
