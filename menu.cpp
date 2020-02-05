/********************************************************************* ** 
 * Program name: menu.cpp
 * ** Author: Jessica Lane
 * ** Description: This contains the menu function definition. It will prompt 
 * the user to choose an option. It will also make sure the user doesn't enter 
 * invalid input such as a letter or whole word. 
 * *********************************************************************/

#include <iostream>
#include <cstdlib>
#include "inputValidation.hpp"
#include "rangeChecker.hpp"
using std::cout;
using std::cin;
using std::endl;

int menu() 
{
	int userChoice;

	cout << "What would you like to do?" << endl;
	cout << "1. Let's Play the Game!" << endl;
	cout << "2. Exit Game." << endl;

	userChoice = inputValidation();
	while (!(rangeChecker(userChoice, 1, 2)))
	{
		cout << "Please enter an integer in range between 1 to 2." << endl;
		userChoice = inputValidation();
	}

	if (userChoice == 1 || userChoice == 2 )	
	{
		return userChoice;
	}
	else
	{ 
		cout << "Please choose a valid option between 1 and 2." << endl;
		userChoice = inputValidation();
	}

}
