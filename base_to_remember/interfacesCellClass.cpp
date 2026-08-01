#include <iostream>
#include "../interfaces/IntCell.h"
using namespace std;

// ============================================================================
// THE IntCell:: SAYS THAT THE FUNCTION IS IN THE CLASS IntCell, meaning that we
// are calling a function from the class IntCell and building it therefore
// :: -> scope resolution operator
// ============================================================================

/**
 * Constructs the IntCell with initialValue, which is directly set to stored value
 */
IntCell::IntCell(int initialValue) : storedValue{initialValue} {}

/**
 * Declarating the Return stored value function which is declared in the interface
 */
int IntCell::read() const
{
    return storedValue;
}

/**
 * Declaring the actual setter for the IntCell declaration
 */
void IntCell::write(int x)
{
    storedValue = x;
}

// NOW WE CAAN PERFECTLY RUN THIS CODE INSIDE THE MAIN
int main()
{
    IntCell c;

    cout << "Initial value: " << c.read() << endl;
    c.write(3);
    cout << "Updated value: " << c.read() << endl;

    return 0;
}