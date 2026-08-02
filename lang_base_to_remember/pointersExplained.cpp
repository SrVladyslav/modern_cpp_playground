#include <iostream>

/**
 * Pass by value: receives a copy of the actual argument
 * Changes do not affext the original variable.
 */
void passByValue(int value)
{
    value = 100;
}

/**
 * Pass by reference: receives an memory address of the actual argument.
 * Changes do affect the original variable.
 *
 * original ─┐
 *           ├──> 200
 * value    ─┘
 */
void passByReference(int &value)
{
    value = 200; // Reference is used as if it were a normal variable
}

/**
 * Pass by const reference: no copy and no modification allowed.
 * Used as readonly basically
 */
void printByConstReference(const int &value)
{
    std::cout << value << std::endl;
}

/**
 * Pass by pointer: receives an address of the actual argument.
 * Dereferencing the pointer modifies the original variable.
 */
void passByPointer(int *pointer)
{
    if (pointer != nullptr)
    {
        *pointer = 300; // '*' is used to access the value stored at the address pointer
    }
}

int main()
{
    int a = 10;

    // --------------------------------------------------------------------------------
    // Value and memory address
    // --------------------------------------------------------------------------------
    std::cout << "Value of a: " << a << "\n";
    std::cout << "Address of a: " << &a << "\n\n";

    // a  -> value stored in a
    // &a -> memory address where a is stored

    // Here, & is the address-of operator.

    // --------------------------------------------------------------------------------
    // Pointer
    // --------------------------------------------------------------------------------
    int *pointer = &a;
    // pointer  -> address of a
    // *pointer -> value stored at the address pointer
    std::cout << "Address stored in pointer: " << pointer << '\n';
    std::cout << "Value accessed through pointer: " << *pointer << "\n\n";

    *pointer = 20;
    std::cout << "After *pointer = 20, a is: " << a << "\n\n";

    // --------------------------------------------------------------------------------
    // Reference
    // --------------------------------------------------------------------------------
    int &reference = a;

    // A reference is an alias: another name for the same object.
    // It is used like a normal variable.
    //         a ─┐
    //            ├──> 30
    // reference ─┘

    reference = 30; // Modifies a since is the same memory address

    std::cout << "After reference = 30, a is: " << a << "\n\n";

    // --------------------------------------------------------------------------------
    // Pass by value
    // --------------------------------------------------------------------------------
    passByValue(a);

    std::cout << "After passByValue(a), a is: " << a << "\n";
    // Still 30 because the function modified only a copoy inside the function.

    // --------------------------------------------------------------------------------
    // Pass by reference
    // --------------------------------------------------------------------------------
    passByReference(reference);

    std::cout << "After passByReference(reference), a is: " << a << "\n";
    // Now 200 because the function received an alias to a.

    // --------------------------------------------------------------------------------
    // Pass by pointer
    // --------------------------------------------------------------------------------
    passByPointer(&a);

    std::cout << "After passByPointer(&a), a is: " << a << "\n\n";
    // Now 300 because the function received the address of a.

    // --------------------------------------------------------------------------------
    // Pass by const reference
    // --------------------------------------------------------------------------------
    printByConstReference(a);

    // --------------------------------------------------------------------------------
    // Quick summary
    // --------------------------------------------------------------------------------
    //
    // int value = 10;        // Normal independent value
    // int& ref = value;      // Reference: alias for value
    // int* ptr = &value;     // Pointer: stores the address of value
    //
    // value   -> value itself
    // &value  -> address of value
    // ptr     -> address stored in the pointer
    // *ptr    -> object located at that address
    //
    // Reference:
    //     ref = 50;
    //
    // Pointer:
    //     *ptr = 50;
    //
    // Object:
    //     object.member
    //
    // Pointer to object:
    //     pointer->member
    //
    // Equivalent:
    //     pointer->member
    //     (*pointer).member

    return 0;
}