/********************************************************************* **
 *  * Program name: cat.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Definitions for the Cat class
 ** *********************************************************************/

#include "cat.hpp"

Cat::Cat()
{

}

/***********************************************************************
 * Adds item (string) passed in to the items vector. If user already has that
 * item, the program will proceed. If the user already has an item, they can
 * choose to drop their other item, or pass on the new item. Otherwise, the
 * item is automatically added into their inventory.
 * ********************************************************************/
void Cat::addItem(string i)
{
    for (int index = 0; index < items.size(); index++)
    {
        if (i == items.at(index))
        {
            cout << "You already have that item!" << endl;
            return;
        }
    }

    if (items.size() >= 1)
    {
        cout << "Dangit, you don't have the capability to carry more items!" << endl;
        cout << "Do you want to drop an item and add this one?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice = inputValidation();
        while (!(rangeChecker(choice, 1, 2)))
	    {
            cout << "Please enter an integer in range between 1 to 2." << endl;
            choice = inputValidation();
	    }

        if (choice == 1)
        {
            removeItem();            
            items.push_back(i);
            cout << "You have obtained " << i << "!" << endl;
        }
        else
        {
            return;
        }
        
    }
    else
    {
        items.push_back(i);
        cout << "You have obtained " << i << "!" << endl;
    }
    
}

/***********************************************************************
 * Removes item from the inventory. If there are none, nothing happens but
 * a message is shown. Otherwise, an item is removed from the vector.
 * ********************************************************************/
void Cat::removeItem()
{
    if (items.size() == 0)
    {
        cout << "You have no items to remove!" << endl;
    }
    else
    {
        cout << "...removing your last item!" << endl;
        items.pop_back();
    }
}

/***********************************************************************
 * Displays items in vector. Message shown if there are no items.
 * ********************************************************************/
void Cat::showItems()
{
    if (items.size() == 0)
    {
        cout << "No items to show!" << endl;
    }
    else
    {
        for (int i =0; i < items.size(); i++)
        {
            cout << items.at(i) << " ";
            cout << endl;
        }
    }
    
}

/***********************************************************************
 * Searches for string passed in to the function. If it is present, a message
 * is displayed. If the item is not present, nothing happens. 
 * ********************************************************************/
bool Cat::searchItems(string s)
{
    if (std::find(items.begin(), items.end(), s) != items.end())
    {
        cout << "You have " << s << "!" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

