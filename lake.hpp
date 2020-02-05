/********************************************************************* **
 *  * Program name: lake.hpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Header file for the Lake class. Derived from Space.
 ** *********************************************************************/

#ifndef LAKE_H
#define LAKE_H

#include "space.hpp"

class Lake : public Space
{
    private:

    public:
        Lake();
        int interaction();
};

#endif