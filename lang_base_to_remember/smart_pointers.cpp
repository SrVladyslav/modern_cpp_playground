#include <iostream>
#include <memory>

/**
 * Smart pointers differ from regular raw pointer, because a raw pointer
 * is simply a memory address. You must orchstrare all the memory management
 * that's involved with the address manually. On the other hand,
 * smart pointers handle all these messy details. By wrapping a dynamic object with
 * a smart pointer, you can rtest assured that memory will be cleaned up
 * appropriately as soon as the object is no longer needed. The compiler knows that
 * the object is no longer needed because the smart pointer's destructor is
 * called when it falls outof scope.
 */

struct Foundation
{
    const char *founder;
};

struct Mutant
{
    // Constructor sets foundation appropriately
    Mutant(std::unique_ptr<Foundation> foundation) : foundation(std::move(foundation))
    {
    }
    std::unique_ptr<Foundation> foundation;
};

int main()
{
    std::unique_ptr<Foundation> second_foundation{new Foundation{}};

    // Access founder member variable just like a pointer:
    second_foundation->founder = "Steve Jobs";
    std::cout << second_foundation->founder << std::endl;
    std::cout << &second_foundation->founder << std::endl;

    Mutant mutant{std::move(second_foundation)};
    // Now the pointer is moved from second foundation to the mutant without deleting.
    // It has some minimal delay, but overall it works fine.
    std::cout << mutant.foundation->founder << std::endl;
    std::cout << &mutant.foundation->founder << std::endl;

    // Check that the memory is the same
    return 0;
}