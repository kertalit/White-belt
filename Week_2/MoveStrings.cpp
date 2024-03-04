#include <iostream>
#include <vector>
#include <string>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination);

int main()
{
    std::vector<std::string> source = { "a", "b", "c" };
    std::vector<std::string> destination = { "z" };

    MoveStrings(source, destination);

    for (auto& word : destination)
    {
        std::cout << word << std::endl;
    }
}

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination)
{
    for (auto& word : source)
    {
        destination.push_back(std::move(word));
    }

    source.clear();
}
