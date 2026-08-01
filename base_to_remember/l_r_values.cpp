#include <iostream>
#include <vector>

using namespace std;

// ========================================================================================================================================================
// An lvalue is an expression that identifies a non-temporary object. An rvalue is an
// expression that identifies a temporaty object or is a value (such as a literal constant)
// not associated with any objects.
//
// As a general rule, if you have a name for a variable, it is an lvaluie,
// regardless of wether it is modifiable.
// ========================================================================================================================================================

void example1()
{
    /**
     * With there declarations:
     * LVALUES: arr, str, arr[x], &x, y, z, ptr, *ptr, (*ptr)[x]
     * RVALUES: 2, "foo", x+y, str.substr(0,1)
     */
    vector<string> arr(3);
    const int x = 2;
    int y;

    int z = x + y;
    string str = "Hello World!";
    vector<string> *ptr = &arr;
}

// ========================================================================================================================================================
// In C++11, an lvalue reference is declared by placing an & after some type. An lvalue
// reference then becomes a synonym (i.e., another name) for the object it references.
// ========================================================================================================================================================
string str = "hello";
string &rstr = str; // rstr is another name for str

// ========================================================================================================================================================
// In C++11, an rvalue reference is declared by placing an && after some type. An rvalue reference
// has the same characteristics as an lvalue reference except that, unlike an lvalue reference,
// an rvalue reference can also reference an rvalue (i.e. a temporatruy object)
// ========================================================================================================================================================
string str = "hello";
string &&bad1 = "hello";
string &&bad2 = str + "world!";

// ========================================================================================================================================================
// LVALUE REFERENSE USE 1: Aliasing complicated names:
// The simplest use, is to use a local reference variable solely for the purpose of renaming an object
// that is known by a complicated expression.
//
// LVALUE REFERENCES USE 2: Range for loops: A second use is in the range for statement. Suppose we wanna add 1 to another value,
// then we can use a reference to it inside the for loop, which is not possible to use in raw form since it will do a copy of the value:
//
// [1] Reference variables are often used to avoid copying objects acrtoss function-call
// boundaries (either in the function call or the function return)
//
// [2] Syntax is needed in function declarations and returns to enable the passing and returning using references
// instead of copies
// ========================================================================================================================================================
int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    for (auto &x : arr)
        ++x;
}