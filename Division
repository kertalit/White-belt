#include <iostream>
#include <stack>


int main()
{
    int input = 0;

    std::cin >> input;

    std::stack<int> result;
    
    while (input > 0)
    {
        result.push(input % 2);
        input /= 2;
    }

    auto size = result.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << result.top();
        result.pop();
    }
}
