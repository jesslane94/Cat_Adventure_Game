/********************************************************************* **
 *  * Program name: lake.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Definitions for the Lake class
 ** *********************************************************************/

 #include "lake.hpp"

 /***********************************************************************
 * Set area name
 * ********************************************************************/
 Lake::Lake()
 {
     roomName = "Lake";
 }

/***********************************************************************
 * Define interaction that happens when user enters the Lake area. An integer 
 * is returned that will signal what happens as a result of that interaction.
 * User gets a choice in deciding where the game will go from here. Results
 * of the interaction are in the Game class function run().
 * ********************************************************************/
 int Lake::interaction()
 {
    cout << "You arrive at the Lake! It spans a couple hundred feet across! You feel so small at the lake." << endl; 
    cout << "The lake is super reflective and has tons of flowers and pebbles surrounding it." << endl;
    cout << "Do you want to get closer to the lake? Or check out the flowers?" << endl;
    cout << "1. Approach lake." << endl;
    cout << "2. Smell the flowers!." << endl;
    int choice = inputValidation();
    while (!(rangeChecker(choice, 1, 2)))
	{
		cout << "Please enter an integer in range between 1 to 2." << endl;
		choice = inputValidation();
	}

    if (choice == 1)
    {
        cout << "You walk up to the lake and look down at the water." << endl;
        cout << "Gosh, what a great reflection staring back at you!" << endl;
        cout << "You spend way too long engrossed in your own reflection." << endl;
        cout << "You lose an extra hour!" << endl;
        return 2;
    }

    else if (choice == 2)
    {
        cout << "The flowers brush against your fur as you walk through the fields around the lake." << endl;
        int chance = rand()%2;
        if (chance == 1)
        {
            cout << "A very bright, opalescent pebble catches your eye." << endl;
            cout << "It's so smooth! It's a worthy offering. You decide to keep it." << endl;
            cout << "             /--------------\\" << endl;
            cout << "             (  -      -     ) " << endl;
            cout << "             \\_-_______-___/" << endl;
            return 5;
        }
        else
        {
            cout << "All the flowers are gorgeous, but you find nothing to bring back home!" << endl;
            cout << "You get a sip of water, then keep on your merry way!" << endl;
        }
    }     
 }