/********************************************************************* **
 *  * Program name: barn.hpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Header file for the Barn class. Derived from the Space class.
 ** *********************************************************************/

#ifndef BARN_H
#define BARN_H

#include "space.hpp"

class Barn : public Space
{
    private:

    public:
        Barn();
        int interaction();
};

#endif