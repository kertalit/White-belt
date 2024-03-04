#include <iostream>

int Factorial(int number);

int main()
{
    int n = 5;

    std::cout << Factorial(n);
}


int Factorial(int number)
{
    if (number == 1 || number <= 0)
    {
        return 1;
    }

    int result = 1;

    for (int i = 2; i <= number; ++i)
    {
        result *= i
    }

    return result;
}
