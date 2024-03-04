#include <iostream>
#include <vector>

std::vector<unsigned int> Average(const std::vector<unsigned int>& temperatures);

int main()
{
    std::vector<unsigned int> input { 7, 6, 3, 0, 9 };

    auto filter = Average(input);

    std::cout << filter.size() << std::endl;
    for (auto n : filter)
    {
        std::cout << n << ", ";
    }
}

std::vector<unsigned int> Average(const std::vector<unsigned int>& temperatures)
{
    int sum = 0;

    for (auto temp : temperatures)
    {
        sum += temp;
    }

    int average = sum / temperatures.size();

    std::vector<unsigned int> result;
    for (int i = 0; i < temperatures.size(); ++i)
    {
        if (temperatures[i] > average)
        {
            result.push_back(i);
        }
    }

    return result;
}
