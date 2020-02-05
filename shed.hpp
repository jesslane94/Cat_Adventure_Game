/********************************************************************* **
 *  * Program name: shed.hpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Shed header file
 ** *********************************************************************/

#ifndef SHED_H
#define SHED_H

#include "space.hpp"

class Shed : public Space
{
    private:

    public:
        Shed();
        int interaction();
};

#endif