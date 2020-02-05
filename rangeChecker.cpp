/********************************************************************* ** 
 * Program name: rangeChecker.cpp
 * ** Author: Jessica Lane
 * ** Description: bool function for checking the range of an input. if the bool
 * returns true, then the input is in range. if it returns false, the user has
 * entered an input out of range.
 * *********************************************************************/

#include <iostream>
//adapted from this video: https://www.youtube.com/watch?v=4qw6OYbWXlw

bool rangeChecker(int input, int min, int max)
{
    if (input < min)
    {
        return false;
    }
    if (input > max)
    {
        return false;
    }

    return true;
}
