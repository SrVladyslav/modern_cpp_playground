#include <iostream>
#include <vector>
using namespace std;

#define NOT_FOUND -1;

/**
 * Perforsm the standard binary search using two comparinsons per level.
 * Returns index where items is found or -1 if not found.
 */
template <typename Comparable>
int binary_search(const vector<Comparable> &arr, const Comparable &item)
{
    int low = 0, hight = arr.size() - 1;

    while (low <= hight)
    {
        int mid = (low + hight) / 2;

        if (arr[mid] < item)
        {
            low = mid + 1;
        }
        else if (arr[mid] > item)
        {
            hight = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return NOT_FOUND;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int index = 4;
    cout << "Index of " << index << " is " << binary_search(arr, index) << endl;

    index = 10;
    cout << "Index of " << index << " is " << binary_search(arr, index) << endl;

    index = 15;
    cout << "Index of " << index << " is " << binary_search(arr, index) << endl;

    return 0;
}