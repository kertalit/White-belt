#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class SortedStrings
{
public:

    void AddString(const std::string& s)
    {
        words_.push_back(s);
    }

    std::vector<std::string> GetSortedStrings() noexcept
    {
        sort(words_.begin(), words_.end());

        return words_;
    }

private:

    std::vector<std::string> words_;
};

void PrintSortedStrings(SortedStrings& strings)
{
    for (const std::string& s : strings.GetSortedStrings())
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

//int main()
//{
//    SortedStrings strings;
//
//    strings.AddString("first");
//    strings.AddString("third");
//    strings.AddString("second");
//    PrintSortedStrings(strings);
//
//    strings.AddString("second");
//    PrintSortedStrings(strings);
//
//    return 0;
//}
