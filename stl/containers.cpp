#include <iostream>
#include <algorithm>
#include <vector>

// STL: Standard Template Library
int main()
{

    std::vector<int> vec{1, 4, 2, 3};
    for (auto x : vec)
        std::cout << x << " ";

    sort(vec.begin(), vec.end());
    std::cout << std::endl;
    for (auto x : vec)
        std::cout << x << " ";

    return 0;
}
