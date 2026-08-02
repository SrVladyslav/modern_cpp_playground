#include <iostream>
#include <vector>
#include <string>

using namespace std;
// ========================================================================================================================================================
// Many languages, C and Java included, pass all parameters using CALL-BY-VALUE: the actual argument is copied into the formal parameter.
// However, arameters in C++ could be large complex object for which copying would be expensive, so C++ has 4 ways on passing values:
// ========================================================================================================================================================

/*
 * [ CALL-BY-VALUE ]
 */
double average(double a, double b);

/*
 * [ CALL-BY-REFERENCE ], in C++ is technically more CALL-BY-LVALUE-REFERENCE called
 */
// If we call it swap(x,y), then the x and y will remain unchanged
void swap(double a, double b);
// So we shoudl implement it like this:
void swap(double &a, double &b); // swaps a and b; correct parameter types

/**
 * [ CALL-BY-CONSTANT-REFERENCE ]: Call by value will force to copy the array, which is very expensive, instead
 * If we wanna just view a random item without copy, we can do that declare the array as a constant reference,
 * so it cannot be modified.
 */
std::string randomItem(std::vector<std::string> arr);
// This essentially provides the same viewable behavior as call-by-value
std::string randomItem(const std::vector<std::string> &arr); // returns a random item in arr

/**
 * What we can get is:
 * [1] If the formal parameter should be able to change the value of the actual argument, then you must use call-by-rference
 * [2] Otherwise, the value of the actual argument cannot be changed by the formal parameter. If the type is a primitive type,
 * use call-by-value. Otherwise, the type is a class type and is generally passed using call-by-constant-reference, unless
 * it is an unusually small and easily copyable type (e.g. a type that stores two or fewer primitive types)
 */

/**
 * [ CALL-BY-RVALUE-RELEVANCE]: Often moving an object's state is much easier than copying it,
 * as it may involve just a simple pointer change. This gives a primary use case of overloading
 * a function based on whether a parameter is an lvalue or rvalue
 */

std::string randomItem2(const std::vector<std::string> &arr)
{
    return arr[rand() % arr.size()];
}; // returns random item in lvalue arr
std::string randomItem2(std::vector<std::string> &&arr)
{
    return arr[rand() % arr.size()];
}; // returns random item in rvalue arr

void invokeTrst1()
{
    // example of call-by-rvalue-reference
    std::vector<std::string> v{"hello", "world"};

    std::cout << randomItem2(v) << std::endl;                  // invokes lvalue method
    std::cout << randomItem2({"hello", "world"}) << std::endl; // invokes rvalue method
}