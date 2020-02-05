/********************************************************************* **
 *  * Program name: forest.hpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: header file for the Forest class
 ** *********************************************************************/

#ifndef FOREST_H
#define FOREST_H

#include "space.hpp"

class Forest : public Space
{
    private:

    public:
        Forest();
        int interaction();
};

#endif