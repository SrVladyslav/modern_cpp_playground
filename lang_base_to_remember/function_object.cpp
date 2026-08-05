#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

/**
 * Generic findMax with a function object, Version 1. The idea is of using a function object as a second parameter.
 * Precondition: a.size() > 0
 */
template <typename Object, typename Comparator>
const Object &findMax(const vector<Object> &arr, Comparator cmp)
{
    int maxIndex = 0;

    for (int i = 1; i < arr.size(); i++)
        if (cmp.isLessThan(arr[maxIndex], arr[i]))
            maxIndex = i;

    return arr[maxIndex];
}

class CaseInsensitiveCompare
{
public:
    bool isLessThan(const string &lhs, const string &rhs) const
    {
        return _stricmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

void test()
{
    vector<string> arr{"ZEBRA", "alligator", "crocodile"};
    cout << findMax(arr, CaseInsensitiveCompare{}) << endl; // Should be ZEBRA
}

/**
 * Generic findMax, with a function object, C++ style.
 *
 * Precondition: a.size() > 0.
 */

template <typename Object, typename Comparator>
const Object &findMax2(const vector<Object> &arr, Comparator isLessThan)
{
    int maxIndex = 0;

    for (int i = 1; i < arr.size(); ++i)
        if (isLessThan(arr[maxIndex], arr[i]))
            maxIndex = i;

    return arr[maxIndex];
}

// Generic findMax2, using default ordeting.
#include <functional>
template <typename Object>
const Object &findMax2(const vector<Object> &arr)
{
    return findMax2(arr, less<Object>{});
}

class CaseInsensitiveCompare2
{
public:
    bool operator()(const string &lhs, const string &rhs) const
    {
        return _stricmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

void test2()
{
    vector<string> arr{"ZEBRA", "alligator", "crocodile"};
    cout << findMax2(arr, CaseInsensitiveCompare2{}) << endl; // Should be ZEBRA
    cout << findMax2(arr) << endl;                            // Should be crocodile
}

int main()
{
    test();
    test2();
    return 0;
}