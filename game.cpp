/********************************************************************* **
 *  * Program name: game.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Game class definitions
 ** *********************************************************************/

#include "game.hpp"

/***********************************************************************
 * Creates map area. A pointer is designated for each spot and initialized using new. 
 * Using set functions from the Space class, each area's surroundings is set, 
 * linking the areas together. If the area in a certain direction is empty, it is 
 * set to nullptr. 
 * ********************************************************************/
void Game::createArea()
{
    frontYard = new FrontYard();
    barn = new Barn();
    forest = new Forest();
    lake = new Lake();
    garden = new Garden();
    shed = new Shed();

    frontYard->setUp(barn);
    frontYard->setDown(nullptr);
    frontYard->setRight(shed);
    frontYard->setLeft(garden);

    barn->setDown(frontYard);
    barn->setUp(nullptr);
    barn->setRight(lake);
    barn->setLeft(forest);

    forest->setDown(garden);
    forest->setUp(nullptr);
    forest->setRight(barn);
    forest->setLeft(nullptr);

    lake->setDown(shed);
    lake->setUp(nullptr);
    lake->setRight(nullptr);
    lake->setLeft(barn);

    garden->setDown(nullptr);
    garden->setUp(forest);
    garden->setRight(frontYard);
    garden->setLeft(nullptr);

    shed->setDown(nullptr);
    shed->setUp(lake);
    shed->setRight(nullptr);
    shed->setLeft(frontYard);
}

/***********************************************************************
 * Displays intro to the game at the start. The player must find a special 
 * object at the end of the allotted number of steps, or else they lose. 
 * The user is asked in what area they would like to start.
 * ********************************************************************/
void Game::intro()
{
    cout << endl;
    cout << "Welcome to the World of Cat! Where you are the most dedicated to being a purrfect cat." << endl;
    cout << "You are the best cat in the world, so all you really wanna do is please your parents!" << endl << endl;
    cout << "                        /\\---/\\ " << endl;
    cout << "                       / >o - o<\\" << endl;
    cout << "                      /          |" << endl;
    cout << "                 \\___|_(..)__(..)| " << endl << endl;
    cout << "You decide to go on a mission to bring them the best offering you find." << endl;
    cout << "It could be a bird, special pebble, or something shiny!" << endl;
    cout << "To bring the best gift, you either have to find a bird or other unique item to offer your parents!" << endl;
    cout << "But paws for a sec... you only have so much energy (being a cat and all) so you only have 9 hours!" << endl;
    cout << "You lose one hour at each location." << endl;
    cout << "There are items around (of which you can only have 1) and events that can help or hurt you." << endl << endl;
    cout << "You wake up from your nap in and go outside. You're ready for your mission right meow!" << endl;
    cout << "Where do you want to start?" << endl;
    cout << "Here's the map:" << endl;
    printArea();
    cout << endl;
}

/***********************************************************************
 * This is the starting point of the user. They input their choice of where
 * they would like to start, and their current location is set to that area.
 * ********************************************************************/
void Game::startingPoint()
{
    cout << "Enter the number of your choice!" << endl;
    cout << "1. Front Yard" << endl;
    cout << "2. Lake" << endl;
    cout << "3. Shed Area" << endl;
    cout << "4. Barn" << endl;
    cout << "5. Forest" << endl;
    cout << "6. Garden" << endl;
    int choice = inputValidation();
    while (!(rangeChecker(choice, 1, 6)))
	{
		cout << "Please enter an integer in range between 1 to 6." << endl;
		choice = inputValidation();
	}

    hours--;
    if (choice == 1)
    {
        currentLocation = frontYard;
    }
    else if (choice == 2)
    {
        currentLocation = lake;
    }
    else if (choice == 3)
    {
        currentLocation = shed;
    }
    else if (choice == 4)
    {
        currentLocation = barn;
    }
    else if (choice == 5)
    {
        currentLocation = forest;
    }
    else
    {
        currentLocation = garden;
    }

}

/***********************************************************************
 * Displays visual map of the area.
 * ********************************************************************/
void Game::printArea()
{
	std::cout << "__________________________________________________________\n"; 
	std::cout << "|               *                     *                   |\n";
	std::cout << "|  Forest       *     Barn            |     Lake          |\n";
	std::cout << "|               *                     *                   |\n";
	std::cout << "|****************_____________________|___________________|\n";
	std::cout << "|               *                     |                   |\n";
	std::cout << "|  Garden       *     Front Yard      |     Shed Area     |\n";
	std::cout << "|               *                     |                   |\n";
	std::cout << "|_______________*_____________________|___________________|\n";

}

/***********************************************************************
 * The in-game menu allows the user to move locations, see their inventory, 
 * or view the number of hours they have left. 
 * ********************************************************************/
int Game::gameMenu()
{
    cout << "What do you want to do next?" << endl;
    cout << "1. Move locations!" << endl;
    cout << "2. See my inventory." << endl;
    cout << "3. View number of hours left." << endl;

    int choice = inputValidation();
    while (!(rangeChecker(choice, 1, 3)))
	{
		cout << "Please enter an integer in range between 1 to 3." << endl;
		choice = inputValidation();
	}

    if (choice == 1)
    {
        moveCat();
    }
    else if (choice == 2)
    {
        player.showItems();
        gameMenu();
    }
    else if (choice == 3)
    {
        cout << "You have " << hours << " hours left!" << endl;
        gameMenu();
    }

}

/***********************************************************************
 * User is asked in which direction they would like to go. The choice is 
 * returned.
 * ********************************************************************/
int Game::moveMenu()
{
    cout << "Where do you want to move next?" << endl;
    printArea();
    cout << endl;
    cout << "1. Up" << endl;
    cout << "2. Right" << endl;
    cout << "3. Down" << endl;
    cout << "4. Left" << endl;
    int choice = inputValidation();
    while (!(rangeChecker(choice, 1, 4)))
	{
		cout << "Please enter an integer in range between 1 to 4." << endl;
		choice = inputValidation();
	}
    return choice;
}

/***********************************************************************
 * Choice from the moveMenu() function is obtained and if the space is 
 * available to move to, the currentlocation is set to the new area. If 
 * the user cannot move to their chosen direction, they are asked to pick 
 * a new direction until they choose one that is viable.
 * ********************************************************************/
void Game::moveCat()
{
    bool exit = false; //menu continues looping until exit returns true
    while (exit == false)
    {
        int choice = moveMenu();
        if (choice == 1)
        {
            if (currentLocation->getUp() == nullptr)
            {
                cout << "Can't move up! Choose another direction." << endl;
            }
            else
            {
                currentLocation = currentLocation->getUp();
                //currentLocation = temp;
                cout << "You have moved up!" << endl;
                cout << "You have moved to " << currentLocation->getName() << "." << endl;
                //temp = nullptr;
                exit = true;
            }
        }
        else if (choice == 2)
        {
            if (currentLocation->getRight() == nullptr)
            {
                cout << "Can't move right! Choose another direction." << endl;
            }
            else
            {
                currentLocation = currentLocation->getRight();
                cout << "You have moved right!" << endl;
                cout << "You have moved to " << currentLocation->getName() << "." << endl;
                exit = true;
            }
            
        }
        else if (choice == 3)
        {
            if (currentLocation->getDown() == nullptr)
            {
                cout << "Can't move down! Choose another direction." << endl;
            }
            else
            {
                currentLocation = currentLocation->getDown();
                cout << "You have moved down!" << endl;
                cout << "You have moved to " << currentLocation->getName() << "." << endl;
                exit = true;
            }
            
        }
        else if (choice == 4)
        {
            if (currentLocation->getLeft() == nullptr)
            {
                cout << "Can't move left! Choose another direction." << endl;
            }
            else
            {
                currentLocation = currentLocation->getLeft();
                cout << "You have moved left!" << endl;
                cout << "You have moved to " << currentLocation->getName() << "." << endl;
                exit = true;
            }
        }
    }
    hours--;
}

/***********************************************************************
 * Game flow is defined here. The intro runs, area is created, starting point
 * determined, interaction happens, then the game menu procts. If the hours 
 * reach 0 or below, the game ends and the win condition is checked. If the
 * user has the win condition item, they win! If not, a lose message is
 * displayed. The player is then asked if they want to play again through a
 * function in the main. Depending on the integer returned from the interaction()
 * function, the user will lose/gain hours, lose/gain items, or nothing can 
 * also happen.
 * ********************************************************************/
int Game::run()
{
    intro();
    createArea();
    startingPoint();
    while (hours > 0)
    {
        int signal = currentLocation->interaction();
        if (signal == 1)
        {
            hours++;
        }
        else if (signal == 2)
        {
            hours--;
        }
        else if (signal == 3)
        {
            player.addItem("Very Feathery Bird");
        }
        else if (signal == 4)
        {
            player.addItem("Shiny Ribbon");
        }
        else if (signal == 5)
        {
            player.addItem("Opal Pebble");
        }
        else if (signal == 6)
        {
            player.removeItem();
        } 

        gameMenu();

    } 

    if (hours <= 0)
    { 
        cout << "Ohnoes! You have run out of hours!" << endl;
        cout << "Did you manage to find a special item? Let's see..." << endl;
        if (player.searchItems("Very Feathery Bird") == true || player.searchItems("Opal Pebble") == true || player.searchItems("Shiny Ribbon") == true)
        {
            cout << "You are the bestest cat! Your parents were super pleased!" << endl;
            cout << "You end your day feline good!" << endl;
        }
        else
        {
            cout << "Looks like you didn't find the a special object!" << endl;
            cout << "You're very disappointed in yourself, but stay pawsitive! Maybe another day..." << endl;
        }
    }

    deleteArea();

}

/***********************************************************************
 * Deletes pointers used to free space.
 * ********************************************************************/
void Game::deleteArea()
{
    delete frontYard;
    delete barn;
    delete garden;
    delete forest;
    delete shed;
    delete lake;
}

