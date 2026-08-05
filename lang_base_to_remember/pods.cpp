#include <cstdio>

/**
 * PODs have some useful low-level features: they're C compatible, you can employ
 * machine instructions that are higjly efficient to copy or move them, and they can
 * be efficiently represented in memory.
 *
 * C++ guarantees that members will be sequential in memory, although some implementations
 * require members to be aligned along word boundaries, wchich depend on CPU register length.
 *
 * As a general rule, you should order members from largest to smallest whitin POD definitions.
 */

struct Point
{
    int x, y;
};

int main()
{
    Point p{1, 2};

    printf("p.x = %d\n", p.x);
    printf("p.y = %d\n", p.y);

    return 0;
}