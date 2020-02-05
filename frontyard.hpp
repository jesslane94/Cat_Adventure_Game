/********************************************************************* **
 *  * Program name: frontyard.hpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Header file for the FrontYard.
 ** *********************************************************************/

#ifndef FRONTYARD_H
#define FRONTYARD_H

#include "space.hpp"

class FrontYard : public Space
{
    private:

    public:
        FrontYard();
        int interaction();

};

#endif