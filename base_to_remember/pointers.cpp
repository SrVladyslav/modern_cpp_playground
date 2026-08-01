#include <iostream>
#include "../interfaces/FullIntCell.h"

// ========================================================================================================================================================
// Pointer is a variable that stores the address where another object resides. It is
// a fundamental mechanism used in many data structures.
//
// Rather than store the collection in an array, it is common to store each item in a separate,
// noncontiguous iece of memory, which is allocated as the program runs. Along with each object
// is a link to the next object.
//
// ATTENTION
// POINTERS SHOULD BE ALWAYS DELETED WHEN THOSE ARE CREATED WITH NEW, ONLY IF THEY ARE AUTOMATIC VARIABLES (no tpointer, e.g. int number = 5),
// NORMALLY THEY ARE STORED IN THESTACK, SO THE WILL DESTROY THEMSELVES WHEN THEY GO OUT OF SCOPE.
//
// IF 'new T' IS USED THEN 'delete T' MUST BE USED TO DESTROY THE OBJECT AGAINST MEMORY LEAKS.
// ========================================================================================================================================================

void dynamicObjectCreation()
{
    IntCell *m = new IntCell();
    IntCell *m2 = new IntCell{};
    IntCell *m3 = new IntCell; // we should generally use this form
}

int main()
{
    /**
     * '*' indicates that m is a pointer variable, meaning that the value of m
     * is the address of the object that it points at.
     *
     * '&' indicates that m is anaddress-of operator, meaning that the operator returns the
     * memory location where an object reside, and is useful fo r implementing an alias
     */
    IntCell *m;

    // Now we are pointing to the memory of the newly created object
    m = new IntCell{6};

    std::cout << "Initial value: " << m->read() << std::endl;

    // Here we access the object's m member function write
    m->write(3);
    std::cout << "Updated value: " << m->read() << std::endl;

    /**
     * Delete the pointer object and frees the memory since C++ does not have garbage collection.
     *
     * When an object that is allocated by NEW is no longer referenced, the delete operation
     * MUST be applied to the object (through a pointer), otherwise, the memory will be leaked until the program terminates.
     */
    delete m;
    return 0;
}