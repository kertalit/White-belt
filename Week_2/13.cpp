#include <iostream>
#include <vector>
#include <string>
#include <map>


int main()
{
    std::map<std::string, std::vector<std::string>> baseBus;
    std::map<std::string, std::vector<std::string>> baseStops;

    int countMessage;
    std::cin >> countMessage;

    for (int i = 0; i < countMessage; ++i)
    {
        std::string command;
        std::cin >> command;

        if (command == "NEW_BUS")
        {
            std::string bus;
            std::vector<std::string> stops;
            int countStops;

            std::cin >> bus >> countStops;
            for (int i = 0; i < countStops; ++i)
            {
                std::string stop;
                std::cin >> stop;

                baseBus[bus].push_back(stop);
                baseStops[stop].push_back(bus);
            }
        }
        else if (command == "BUSES_FOR_STOP")
        {

            std::string targetStop;
            std::cin >> targetStop;

            const auto& buses = baseStops[targetStop];

            if (buses.empty())
            {
                std::cout << "No stop";
            }
            else
            {
                auto size = buses.size();
                for (int i = 0; i < size; ++i)
                {
                    std::cout << buses[i] << ' ';
                }
            }
            std::cout << '\n';
        }
        else if (command == "STOPS_FOR_BUS")
        {
            std::string targetBus;
            std::cin >> targetBus;

            const auto& route = baseBus[targetBus];

            for (const auto& stop : route)
            {
                std::vector<std::string> buses;

                for (const auto& [bus, stops] : baseBus)
                {
                    if (bus == targetBus)
                    {
                        continue;
                    }

                    if (find(stops.cbegin(), stops.cend(), stop) != stops.cend())
                    {
                        buses.push_back(bus);
                    }
                }

                std::cout << "Stop " << stop << ": ";
                if (buses.empty())
                {
                    std::cout << "no interchange";
                }
                else
                {
                    for (const auto& bus : buses)
                    {
                        std::cout << bus << ' ';
                    }
                }
                std::cout << '\n';
                
                buses.clear();
            }
        }
        else if (command == "ALL_BUSES")
        {
            for (const auto& [bus, stops] : baseBus)
            {
                std::cout << "Bus " << bus << ": ";
                
                for (const auto& stop : stops)
                {
                    std::cout << stop << ' ';
                }

                std::cout << '\n';
            }
        }
    }

    return 0;
}
