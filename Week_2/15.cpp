#include <iostream>
#include <string>
#include <set>

int main()
{
    int countMessage;
    std::cin >> countMessage;

    std::set<std::string> unique;
    
    for (int i = 0; i < countMessage; ++i)
    {
        std::string temp;
        std::cin >> temp;
        unique.insert(temp);
    }

    std::cout << unique.size();

    return 0;
}
