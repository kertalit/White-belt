#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>


class Person
{
public:

    void ChangeFirstName(int year, const std::string& first_name)
    {
        notes_[year].first = first_name;
    }

    void ChangeLastName(int year, const std::string& last_name)
    {
        notes_[year].second = last_name;
    }

    std::string GetFullNameWithHistory(int year)
    {
        std::string first_name = "";
        std::string last_name = "";

        std::vector<std::string> historyNamefirst;
        std::vector<std::string> historyNamelast;

        for (const auto& entry : notes_)
        {
            if (entry.first > year)
            {
                break;
            }

            if (entry.second.first.empty() == false)
            {
                first_name = entry.second.first;

                if (historyNamefirst.empty())
                {
                    historyNamefirst.push_back(first_name);
                }
                else if (first_name != historyNamefirst.back())
                {
                    historyNamefirst.push_back(first_name);
                }
            }

            if (entry.second.second.empty() == false)
            {
                last_name = entry.second.second;

                if (historyNamelast.empty())
                {
                    historyNamelast.push_back(last_name);
                }
                else if (last_name != historyNamelast.back())
                {
                    historyNamelast.push_back(last_name);
                }
            }
        }

        if (historyNamefirst.empty() == false)
        {
            historyNamefirst.pop_back();
        }
        if (historyNamelast.empty() == false)
        {
            historyNamelast.pop_back();
        }

        historyNamefirst = { historyNamefirst.rbegin(), historyNamefirst.rend() };
        historyNamelast = { historyNamelast.rbegin(), historyNamelast.rend() };

        if (first_name.empty() && last_name.empty())
        {
            return "Incognito";
        }
        else if (first_name.empty())
        {
            return last_name + Print(historyNamelast) + " with unknown first name";
        }
        else if (last_name.empty())
        {
            return first_name + Print(historyNamefirst) + " with unknown last name";
        }
        else
        {
            return first_name + Print(historyNamefirst) + " " + last_name + Print(historyNamelast);
        }
    }

private:
    
    std::string Print(std::vector<std::string> history)
    {
        std::string list;
        for (const auto& str : history)
        {
            list.append(str + " ");
        }

        if (list.empty())
        {
            return "";
        }

        return " (" + list + ")";
    }

    std::map<int, std::pair<std::string, std::string>> notes_;
};

//int main() {
//    Person person;
//
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//    for (int year : {1900, 1965, 1990}) {
//        std::cout << person.GetFullNameWithHistory(year) << std::endl;
//    }
//
//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//        std::cout << person.GetFullNameWithHistory(year) << std::endl;
//    }
//
//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1969, 1970}) {
//        std::cout << person.GetFullNameWithHistory(year) << std::endl;
//    }
//
//    person.ChangeFirstName(1990, "Polina");
//    person.ChangeLastName(1990, "Volkova-Sergeeva");
//    std::cout << person.GetFullNameWithHistory(1990) << std::endl;
//
//    person.ChangeFirstName(1966, "Pauline");
//    std::cout << person.GetFullNameWithHistory(1966) << std::endl;
//
//    person.ChangeLastName(1960, "Sergeeva");
//    for (int year : {1960, 1967}) {
//        std::cout << person.GetFullNameWithHistory(year) << std::endl;
//    }
//
//    person.ChangeLastName(1961, "Ivanova");
//    std::cout << person.GetFullNameWithHistory(1967) << std::endl;
//
//    return 0;
//}
