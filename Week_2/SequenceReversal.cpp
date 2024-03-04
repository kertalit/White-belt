#include <iostream>
#include <vector>

void SequenceReversal(std::vector<int>& v);

int main()
{
    std::vector<int> numbers = { 1, 5, 3, 4, 2 };
    SequenceReversal(numbers);

    for (auto n : numbers)
    {
        std::cout << n << std::endl;
    }
}


void SequenceReversal(std::vector<int>& v)
{
    auto halfSize = v.size() / 2;
    auto last = v.size() - 1;
    for (int i = 0; i < halfSize; ++i)
    {
        std::swap(v[i], v[last -i]);
    }
}
