#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // [capture] (arguments) {body}
    auto n_evens = std::count_if(x.begin(), x.end(), [](auto number)
                                 { return number % 2 == 0; });

    auto square = [](int &v)
    { return v * v; };

    vector<int> y;

    for (auto i : x)
        y.push_back(square(i));

    cout << y.size() << endl;

    for (auto k : y)
        cout << k << " ";

    int g = 2;
    cout << "\n2 squared: " << square(g) << endl;

    return 0;
}