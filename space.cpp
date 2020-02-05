/********************************************************************* **
 *  * Program name: space.cpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Definitions for the Shed class
 ** *********************************************************************/

#include "space.hpp"

/***********************************************************************
 * Initializes direction pointers to null
 * ********************************************************************/
Space::Space()
{
    up = nullptr;
    right = nullptr;
    down = nullptr;
    left = nullptr;
}

Space::~Space()
{

}

/***********************************************************************
 * get area name
 * ********************************************************************/
std::string Space::getName()
{
    return roomName;
}

/***********************************************************************
 * Next four functions set whatever each direction will be do a Space pointer
 * ********************************************************************/
void Space::setUp(Space* u)
{
    this->up = u;
}

void Space::setDown(Space* d)
{
    this->down = d;
}

void Space::setRight(Space* r)
{
    this->right = r;
}

void Space::setLeft(Space* l)
{
    this->left = l;
}

/***********************************************************************
 * Next four functions return the Space* in that direction
 * ********************************************************************/
Space* Space::getUp()
{
    return up;
}

Space* Space::getDown()
{
    return down;
}

Space* Space::getRight()
{
    return right;
}

Space* Space::getLeft()
{
    return left;
}










