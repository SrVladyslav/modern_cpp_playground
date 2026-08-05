#include <iostream>

void some_function()
{
    throw std::exception();
}

int main()
{
    try
    {
        std::cout << "Exceuting the function" << std::endl;
        some_function();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "End of the program" << std::endl;
    return 0;
}