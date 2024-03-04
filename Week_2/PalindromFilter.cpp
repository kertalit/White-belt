#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> PalindromFilter(const std::vector<std::string>& words, int minLength);
bool IsPalindrom(const std::string& word);

int main()
{
    std::vector<std::string> s = { "abacaba", "aba" };

    auto filter = PalindromFilter(s, 5);
    for (const auto& word : filter)
    {
        std::cout << word << std::endl;
    }
}


std::vector<std::string> PalindromFilter(const std::vector<std::string>& words, int minLength)
{
    std::vector<std::string> result;

    for (const auto& word : words)
    {
        if (word.size() >= minLength)
        {
            if (IsPalindrom(word))
            {
                result.push_back(word);
            }
        }
    }

    return result;
}

bool IsPalindrom(const std::string& word)
{
    auto size = word.size();

    for (int i = 0; i < size / 2; ++i)
    {
        auto last = size - i - 1;

        if (word[i] != word[last])
        {
            return false;
        }
    }

    return true;
}