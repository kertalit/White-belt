#include <iostream>
#include <vector>
#include <string>
#include <map>


int main()
{
    std::map<std::vector<std::string>, int> routes;

    int countMessage;
    std::cin >> countMessage;

    for (int i = 0; i < countMessage; ++i)
    {
        int numberRoutes;
        std::cin >> numberRoutes;

        std::vector<std::string> stops;
        stops.reserve(numberRoutes);

        for (int i = 0; i < numberRoutes; ++i)
        {
            std::string temp;
            std::cin >> temp;
            stops.push_back(move(temp));
        }

#if USE_OPTIMIZED
        size_t currentSize = routes.size();
        auto [it, inserted] = routes.insert({ std::move(stops), currentSize + 1 });
        if (inserted == false) 
        {
            std::cout << "Already exists for " << it->second << '\n';
        } 
        else 
        {
            std::cout << "New bus " << it->second << '\n';
        }
#else   
        if (routes.count(stops))
        {
            std::cout << "Already exists for " << routes[stops] << '\n';
        }
        else
        {
            int size = routes.size();
            routes[stops] = ++size;
            std::cout << "New bus " << size << '\n';
        }
#endif
    }

    return 0;
}
