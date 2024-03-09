#include <iostream>
#include <vector>

std::vector<int> SequenceReversal(const std::vector<int>& v);

int main()
{
    std::vector<int> numbers = { 1, 5, 3, 4, 2 };

    std::vector<int> reverse(numbers.rbegin(), numbers.rend());

    for (auto n : reverse)
    {
        std::cout << n << std::endl;
    }
}


std::vector<int> SequenceReversal(const std::vector<int>& v)
{
    std::vector<int> reverse(v.size());

    std::copy(v.rbegin(), v.rend(), reverse.begin());

    return reverse;
}
