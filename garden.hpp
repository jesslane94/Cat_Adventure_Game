/********************************************************************* **
 *  * Program name: garden.hpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Header file for the Garden class
 ** *********************************************************************/

#ifndef GARDEN_H
#define GARDEN_H

#include "space.hpp"

class Garden : public Space
{
    private:

    public:
        Garden();
        int interaction();
};

#endif