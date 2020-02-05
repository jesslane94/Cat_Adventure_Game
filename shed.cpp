/********************************************************************* **
 *  * Program name: shed.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Definitions for the Shed class
 ** *********************************************************************/

 #include "shed.hpp"

/***********************************************************************
 * Set area name
 * ********************************************************************/
 Shed::Shed()
 {
     roomName = "Shed";
 }

/***********************************************************************
 * Define interaction that happens when user enters the Shed area. An integer 
 * is returned that will signal what happens as a result of that interaction.
 * User gets a choice in deciding where the game will go from here. Results
 * of the interaction are in the Game class function run().
 * ********************************************************************/
 int Shed::interaction()
 {
    cout << "Here you are at the Shed! It's gritty looking. Everything seems to have a layer of dirt on it." << endl; 
    cout << "There are a bunch of tools leaning against the side of the shed and an opening to the inside." << endl;
    cout << "Examine tools or go inside the shed?" << endl;
    cout << "1. Examine tools." << endl;
    cout << "2. Go inside the shed!" << endl;
    int choice = inputValidation();
    while (!(rangeChecker(choice, 1, 2)))
	{
		cout << "Please enter an integer in range between 1 to 2." << endl;
		choice = inputValidation();
	}

    if (choice == 1)
    {
        cout << "You carefully traverse the tools leaning against the shed." << endl;
        cout << "Some of the tools look kind of scary, with all the sharp points and weird shapes." << endl;
        cout << "A mouse is hiding within the tools! You pounce! ...But miss." << endl;
        cout << "You drop one of your items in the process!" << endl;
        return 6;
    }

    else if (choice == 2)
    {
        cout << "Entering the shed, all you see is a dusty old metal beast with random items around it." << endl;
        cout << "There's some boxes and a bunch of forgotten stuff." << endl;
        cout << "It makes you kind of sad and you lose a little motivation. An extra hour is gone!" << endl;
        return 2;
    }  
 }