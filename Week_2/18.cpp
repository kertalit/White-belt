#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>


int main()
{
    std::map<std::set<std::string>, int> routes;

    int countMessage;
    std::cin >> countMessage;

    for (int i = 0; i < countMessage; ++i)
    {
        int numberRoutes;
        std::cin >> numberRoutes;

        std::set<std::string> stops;

        for (int i = 0; i < numberRoutes; ++i)
        {
            std::string temp;
            std::cin >> temp;

            stops.insert(std::move(temp));
        }

        auto currentSize = routes.size();
        auto [it, inserted] = routes.insert({ std::move(stops), currentSize + 1 });

        if (inserted == false)
        {
            std::cout << "Already exists for " << it->second << '\n';
        }
        else
        {
            std::cout << "New bus " << it->second << '\n';
        }
    }

    return 0;
}
