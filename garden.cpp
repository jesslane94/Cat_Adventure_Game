/********************************************************************* **
 *  * Program name: garden.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Definitions of the Garden class
 ** *********************************************************************/

 #include "garden.hpp"

/***********************************************************************
 * set area name
 * ********************************************************************/
 Garden::Garden()
 {
     roomName = "Garden";
 }

/***********************************************************************
 * Define interaction that happens when user enters the Garden area. An integer 
 * is returned that will signal what happens as a result of that interaction.
 * User gets a choice in deciding where the game will go from here. Results
 * of the interaction are in the Game class function run().
 * ********************************************************************/
 int Garden::interaction()
 {
    cout << "You see the Garden! It is filled with cascading vines, towering plants, and earthy soil." << endl; 
    cout << "There are rows of trellises and a small greenhouse." << endl;
    cout << "Check out the trellises or the greenhouse?" << endl;
    cout << "1. Look at trellises." << endl;
    cout << "2. Wander the greenhouse." << endl;
    int choice = inputValidation();
    while (!(rangeChecker(choice, 1, 2)))
	{
		cout << "Please enter an integer in range between 1 to 2." << endl;
		choice = inputValidation();
	}

    if (choice == 1)
    {
        cout << "The trellises provide a lot of shade as you weave through them." << endl;
        cout << "Some have purple fruits and others have tomatoes. You are getting hungry!" << endl;
        cout << "A large tomato falls off the vine and you quickly dodge it! But you lose an item in the process!" << endl;
        return 6;
    }

    else if (choice == 2)
    {
        cout << "As you wander the greenhouse, you see so many different plants!" << endl;
        cout << "You get lost observing all the different colors, shapes, and smells!" << endl;
        cout << "Basically, nothing happens and you waste an hour!" << endl;
    }   
 }