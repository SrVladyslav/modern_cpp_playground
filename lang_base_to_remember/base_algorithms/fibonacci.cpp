#include <iostream>

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int fib_num = 10;

    std::cout << "Fibonacci number " << fib_num << " is " << fibonacci(fib_num) << std::endl;
    return 0;
}