/********************************************************************* **
 *  * Program name: space.hpp
 ** ** Author: Jessica Lane
 ** ** Date: June 11th, 2019
 ** ** Description: Space class header file. It is an abstract base class, 
 with the interaction() function being pure virtual.
 ** *********************************************************************/

 #ifndef SPACE_H
 #define SPACE_H

 #include <iostream>
 #include <string>
 #include <cstdlib>
 #include "inputValidation.hpp"
 #include "rangeChecker.hpp"
 #include "cat.hpp"
 using std::cout;
 using std::endl;

 class Space
 {
     protected:
        Space *up;
        Space *right;
        Space *down;
        Space *left;
        std::string roomName;

     public:
        Space();
        ~Space();
        void setUp(Space*);
        void setDown(Space*);
        void setRight(Space*);
        void setLeft(Space*);
        Space* getUp();
        Space* getDown();
        Space* getRight();
        Space* getLeft();
        virtual int interaction() = 0;
        std::string getName();
        
 };

 #endif

 