#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> squares(100);

    for (int i = 0; i < squares.size(); i++)
        squares[i] = i * i;

    for (int i = 0; i < squares.size(); i++)
        std::cout << i << " " << squares[i] << std::endl;

    // The vectors can be copied and compared with = and == respectfully.
    std::vector<int> copy;
    copy = squares;

    if (squares == copy)
        std::cout << "The vectors are equal" << std::endl;

    // ============================================================================
    // Thevectors are still functioning as the arrays, but they have more functions
    // ============================================================================
    std::vector<int> daysInMonth2(12); // Vector of size 12 with default value 0

    // Vectors can be initialized with a list of values: No {} before C++11
    std::vector<int> daysInMonth1{12};                                            // Vector of size 1 with value 12 in the first position
    std::vector<int> daysInMonth{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // directly initialize all the vector with values
    // We can initialize the vector with the old way too
    daysInMonth[0] = 31;
    daysInMonth[1] = 28;
    daysInMonth[2] = 31;
    daysInMonth[3] = 30;
    daysInMonth[4] = 31;
    daysInMonth[5] = 30;
    daysInMonth[6] = 31;
    daysInMonth[7] = 31;
    daysInMonth[8] = 30;
    daysInMonth[9] = 31;
    daysInMonth[10] = 30;
    daysInMonth[11] = 31;

    // ============================================================================
    // C++11 adds the range for, the Pyton's way of for item in item_list
    // ============================================================================
    std::cout << "Range for daysInMonth values: " << std::endl;
    for (int day : daysInMonth)
        std::cout << day << " ";

    // ============================================================================
    // We can also use the auto keyword to get the type transformed automatically
    // ============================================================================
    std::cout << std::endl
              << "Range for str values: " << std::endl;
    std::vector<char> strings{'a', 'b', 'c', 'd', 'e'};
    for (auto s : strings)
        std::cout << s << " ";

    std::string bye = "Goodbye!";
    std::cout << bye << std::endl;

    return 0;
}