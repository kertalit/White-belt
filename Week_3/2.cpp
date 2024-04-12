#include <iostream>
#include <string>
#include <string_view>
#include <set>
#include <algorithm>
#include <vector>

//int main()
//{
//    auto comparator = [](std::string left, std::string right) {
//
//        std::transform(left.cbegin(), left.cend(), left.begin(), std::tolower);
//        std::transform(right.cbegin(), right.cend(), right.begin(), std::tolower);
//
//        return left < right;
//        };
//
//    int count;
//    std::cin >> count;
//
//    std::vector<std::string> words;
//
//    for (int i = 0; i < count; ++i)
//    {
//        std::string word;
//        std::cin >> word;
//
//        words.push_back(std::move(word));
//    }
//
//    std::sort(words.begin(), words.end(), comparator);
//
//    for (const auto& word : words)
//    {
//        std::cout << word << ' ';
//    }
//
//    return 0;
//}
