/********************************************************************* **
 *  * Program name: cat.hpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: header file for the Cat class
 ** *********************************************************************/

#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "space.hpp"
#include "inputValidation.hpp"
#include "rangeChecker.hpp"

using std::vector;
using std::string;

class Cat
{
    protected:
        vector<string> items;

    public:
        Cat();
        void addItem(string);
        void removeItem();
        void showItems();
        bool searchItems(string);
};

#endif