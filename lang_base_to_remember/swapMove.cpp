#include <iostream>
#include <vector>

using namespace std;

/**
 * Swapping by three copies by using the in-memory pointers
 */
void swap(double &x, double &y)
{
    double temp = x;
    x = y;
    y = temp;
}

void swap(vector<string> &x, vector<string> &y)
{
    vector<string> temp = x;
    x = y;
    y = temp;
}

/**
 * Swapping by three moves, first with a type cast, second using std::move:
 * std::move converts any lvalue or rvalue into an rvalue.
 *
 * The method below has a O(1) complexity since it just copies the pointers nothing more.
 * The implementation below is also the move implementation of the standard library.
 *
 * EXCHANGES THE CONTENTS OF TWO VECTORS BY TRANSFERRING THEIR INTERNAL RESOURCES FROM ONE TO THE OTHER:
 * FISRT TEMP OBTAINS THE X'S INTERNAL RESOURCE WHILE THIS LOSES IT, THEN X OBTAINS THE Y'S AND FINALLY Y OBTAINS THE TEMP'S RESOURCES
 */
void move_under_the_hood(vector<string> &x, vector<string> &y)
{
    vector<string> temp = static_cast<vector<string> &&>(x);
    x = static_cast<vector<string> &&>(y);
    y = static_cast<vector<string> &&>(temp);
}

/**
 * The std::move function does the same thing as the function above.
 */
void prod_swap(vector<string> &x, vector<string> &y)
{
    vector<string> temp = std::move(x);
    x = std::move(y);
    y = std::move(temp);
}