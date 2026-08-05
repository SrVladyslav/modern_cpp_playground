#include <variant>
#include <cstdio>

using Value = std::variant<int, double, float>;

int main()
{
    // Declared as float
    Value v = 3.14f;
    printf("v is %f\n", std::get<float>(v));

    // Declared as double
    v = 3.14;
    printf("v is %f\n", std::get<double>(v));

    // Re-declared as int
    v = 2;

    printf("v is %d\n", std::get<int>(v));

    return 0;
}