#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void ChangeCapital(unordered_map<string, string>& countries, const string& country, const string& new_capital)
{
    if (countries.count(country) == 0)
    {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    }
    else if (countries[country] == new_capital)
    {
       cout << "Country " << country << " hasn't changed its capital" << endl;
    }
    else
    {
        string old_capital = countries[country];
        cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
    }
    countries[country] = new_capital;
}

void RenameCountry(unordered_map<string, string>& countries, const string& old_country_name, const string& new_country_name)
{
    if (old_country_name == new_country_name || countries.count(old_country_name) == 0 || countries.count(new_country_name) > 0)
    {
        cout << "Incorrect rename, skip" << endl;
    }
    else
    {
        string capital = countries[old_country_name];
        cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
        countries[new_country_name] = capital;
        countries.erase(old_country_name);
    }
}

void AboutCountry(const unordered_map<string, string>& countries, const string& country)
{
    if (countries.count(country) == 0)
    {
        cout << "Country " << country << " doesn't exist" << endl;
    }
    else
    {
        cout << "Country " << country << " has capital " << countries.at(country) << endl;
    }
}

void Dump(const unordered_map<string, string>& countries)
{
    if (countries.empty())
    {
        cout << "There are no countries in the world" << endl;
    }
    else
    {
        for (const auto& pair : countries)
        {
           cout << pair.first << "/" << pair.second << " ";
        }
        cout << endl;
    }
}

int main()
{
    int Q;
    cin >> Q;

    unordered_map<string, string> countries;

    for (int i = 0; i < Q; ++i)
    {
        string command;
        cin >> command;

        if (command == "CHANGE_CAPITAL")
        {
            string country, new_capital;
            cin >> country >> new_capital;
            ChangeCapital(countries, country, new_capital);
        }
        else if (command == "RENAME")
        {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            RenameCountry(countries, old_country_name, new_country_name);
        }
        else if (command == "ABOUT")
        {
            string country;
            cin >> country;
            AboutCountry(countries, country);
        }
        else if (command == "DUMP")
        {
           Dump(countries);
        }
    }

    return 0;
}
