#include <iostream>
#include <vector>

class BigFive
{
private:
    int someData;

public:
    // Constructor
    BigFive()
    {
        someData = 0;
    }

    /**
     * Destructor: is called whenever an object goes out of scope or subjected to a delete.
     * Typically, the only responsibility of the destructor is to free up any resources that were
     * acquired during the use of the object. This includes delete for any corresponding news,
     * closing any files that were opened and so on. The default simply applies the destructor
     * on each data member
     */
    ~BigFive()
    {
        std::cout << "BigFive destructor called" << std::endl;
    }

    /**
     * Copy constructor: is when existing object is an lvalue, meaning that it has a name and is not will be destroyed automatically.
     *
     * A copy constructor or move constructor is called if:
     * [1] BigFive A = B;   BigFive A {C};
     * [2] An object passed using call-by-value (instead of by & or const &), which should rarely be done anyway.
     * [3] An object returned by value (instead of by & or const &). Again, a copy constructor is invoked
     * if the object being returned is an lvalue, and a move constructor is invoked if the object being returned is an rvalue.
     *
     * By default the copy constructor is implemented by applying copy constructors to each data member in turn. Fo data primitive
     * types (int double or pointers), simple asignment is done.
     *
     * FURTHERMORE, THE COPY CONSTRUCTOR AND THE COPY ASSIGNMENT (=) OPERATOR BOTH COPY THE VALUE OF THE POINTER RATHER THAN THE OBJECTS BEING POINTED AT.
     * THUS, WE WILL HAVE TWO CLASS INSTANCES THAT CONTAIN POINTERS THAT POINT TO THE SAME OBJECT. THIS IS SO-CALLED SHALLOW COPY.
     * TYPICALLY, WE WOULD EXPECT A DEEP COPY, IN WHICH A CLONE OF THE ENTIRE OBJECT IS MADE, BUT IS NOT THE CASE.
     */
    BigFive(const BigFive &other)
    {
        someData = other.someData;
    }

    /**
     * Move constructor: is when he existing object is an rvalue (i.e., a temporary that is about to be destroyed anuywas)
     */
    BigFive(BigFive &&other)
    {
        someData = other.someData;
    }

    /**
     * DEfault assignments don't work when a data member is a pointer type, and the pointer is allocated
     * by some object member function (such as the constructor). All these copies are shallow-copies, meaning that we
     * only pass the pointer (Like the typical pointer shit in Python). The second is a memory leak problem: the value allocater initially
     * by a's constructor remains allocated and needs to be reclaimed, the value allocated by b's constructor is no longer referenced by
     * any pointer variable, is needs to be reclaimed but we no longer have a pointer on it. The C++11 has deprecated the prior behavior
     * that allowed fdefault copy operations even if a destructor was written.
     */

    /**
     * Copy assignment (BigFive a = b;) using copy-anmd-swap technique
     *
     * this -> Pointer to the actual object
     * *this -> Pointer to the object being assigned to
     *
     * =================================================================================
     * Remember:
     * int a = 10;
     *
     * a  // value: 10
     * &a // memory address where a is stored: 0x100 -> & is a direction operator
     *
     * --------------------------------------------------------------------------------
     * The pointer stores the address
     * --------------------------------------------------------------------------------
     * int a = 10;
     * int *ptr = &a; // ptr is a pointer to int and stores the address of a
     * int* ptr = &a; // same thing
     *
     * --------------------------------------------------------------------------------
     * '*' before a pointer access the value stored at the address
     * --------------------------------------------------------------------------------
     * int a = 10;
     * int* ptr = &a;
     *
     * Then if we print the *p
     * cout << *ptr << endl; // prints 10
     *
     * Therefore, p is the address of a, while *p is the value stored in a
     *
     * --------------------------------------------------------------------------------
     * Referense is an alias for the object it points to
     * --------------------------------------------------------------------------------
     * int a = 10;
     * int& ref = a; // Is a reference to a
     *
     * ref = 30; // modifies a
     * cout << a << endl; // prints 30
     *
     * !! Reference is used as normal variable: ref = 30, while the pointer needs * to access the value *p = 30
     * int& ref = a; // & Is part of a type
     * int* p = &a;  // & gets the address of a
     *
     * =================================================================================
     */
    BigFive &operator=(const BigFive &otherRValue)
    {
        BigFive copy = otherRValue; // Uses a copy constructor
        std::swap(*this, copy);
        return *this;
    }

    /**
     * Move assignment (BigFive a = b;) using move-anmd-swap technique
     */
    BigFive &operator=(BigFive &&rValue)
    {
        std::swap(this->someData, rValue.someData);
        return *this;
    }
};
