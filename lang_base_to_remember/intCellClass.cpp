#include <iostream>
using namespace std;

/**
 * A class for simulating an integer memory cell
 **/
class IntCell
{
public:
    int fast_assign;
    /**
     * Constructor for the IntCEll. Initial value is set to 0
     */
    IntCell()
    {
        storedValue = 0;
        fast_assign = 0;
    }

    /**
     * Overloaded contructor with a specific value.
     * Constructs the IntCell with initial value of initialValue
     *
     * Also we assign directly th evalue to the fast_assign, but if the value is not correct, then it will fail
     *
     * YOU SHOULD MAKE ALL THE ONE-PARAMETER CONSTRUCTORS EXPLICIT TO AVOID BTS TYPE CONVERSIONS:
     * It means that 1-param constructr cannot be used to generate an implicit temporary.
     */
    explicit IntCell(int initialValue) : fast_assign{initialValue}
    {
        storedValue = initialValue;
    }

    /**
     * Just a pointer setter
     */
    explicit IntCell(int &initValRef) : fast_assign{initValRef} {}

    /**
     * Getter of type int for the storeValue since is private
     */
    int read() const
    {
        return storedValue;
    }

    /**
     * Return the storedValue byt reference without copying
     *
     * The first const says it will return a const reference without copyying it
     * while the second const says it is a return function
     */
    const int &readReference() const
    {
        return storedValue;
    }

    /**
     * Setter got the stored value to newValue
     */
    void write(int newValue)
    {
        storedValue = newValue;
    }

private:
    int storedValue;
};

int main()
{
    IntCell cell = IntCell(3);

    std::cout << "Initial value: " << cell.read() << std::endl;
    std::cout << "Initial value 1: " << cell.fast_assign << std::endl;

    // Lets print a new hadcded value to the cell
    cell.write(6);
    cell.fast_assign = 6;
    std::cout << "New value: " << cell.read() << std::endl;
    std::cout << "New value 2: " << cell.fast_assign << std::endl;

    return 0;
}