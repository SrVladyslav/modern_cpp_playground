#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const vector<int> &v)
{
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> v{1, 3, 4, 5, 12, 5, 5, 6, -1};

    sort(v.begin(), v.end());
    print(v);

    v.push_back(10);
    print(v);

    return 0;
}