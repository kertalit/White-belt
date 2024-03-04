#include <iostream>

void UpdateIfGreater(int first, int& second);

int main()
{
    int a = 5;
    int b = 2;

    UpdateIfGreater(a, b);

    std::cout << b;
}

void UpdateIfGreater(int first, int& second)
{
    if (first > second)
    {
        second = first;
    }
}
