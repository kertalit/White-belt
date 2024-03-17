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

        for (int i = 0; i < numberRoutes; ++i)
        {
            std::string temp;
            std::cin >> temp;
            stops.push_back(temp);
        }
        auto route = find_if(routes.cbegin(), routes.cend(), [stops](const decltype(routes)::value_type& bus) {
            return bus.first == stops; });

        if ( route != routes.cend())
        {
            std::cout << "Already exists for " << route->second << '\n';
        }
        else
        {
            int size = routes.size();
            routes[stops] = ++size;

            std::cout << "New bus " << size << '\n';
        }
    }

    return 0;
}
