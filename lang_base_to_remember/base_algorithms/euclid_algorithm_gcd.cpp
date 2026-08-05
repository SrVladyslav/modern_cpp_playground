#include <iostream>
using namespace std;

/**
 * Euclid's algorithm for finding the greatest common divisor of two numbers.
 * Returns the greatest common divisor of a and b.
 */
long long euclid_gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long res = a % b;
        a = b;
        b = res;
    }
    return a;
}

int main()
{
    long long a = 100, b = 20;
    cout << "GCD of " << a << " and " << b << " is " << euclid_gcd(a, b) << endl;

    a = 1989, b = 1590;
    cout << "GCD of " << a << " and " << b << " is " << euclid_gcd(a, b) << endl;

    a = 50, b = 15;
    cout << "GCD of " << a << " and " << b << " is " << euclid_gcd(a, b) << endl;

    a = 11, b = 2;
    cout << "GCD of " << a << " and " << b << " is " << euclid_gcd(a, b) << endl;

    return 0;
}
