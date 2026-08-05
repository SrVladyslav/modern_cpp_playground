#include <iostream>
#include <algorithm>
#include <vector>

// By default structs are public, so we can access them directly
struct Point
{
    int x, y;

private:
    int z; // This is private, so we can't access it directly
};

// Classes are the same as structs, but by default they are private
class Rectangle
{
public:
    Rectangle(int w, int h) : width{w}, height{h} {}
    void set_values(int w, int h)
    {
        width = w;
        height = h;
    }
    std::string name;

private:
    int width, height;
};

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
