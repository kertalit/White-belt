#include <iostream>
#include <string>

bool Palindrome(std::string s);

int main()
{
    std::string s = "gentleman";

    std::cout << Palindrome(s);
}


bool Palindrome(std::string s)
{
    auto size = s.size();
    for (int i = 0; i < size / 2; ++i)
    {
        auto last = size - i - 1;

        if (s[i] != s[last])
        {
            return false;
        }
    }

    return true;
}
