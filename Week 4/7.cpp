#include <iostream>
#include <ostream>
#include <vector>
#include <string>

struct Day
{
    explicit Day(uint16_t day)
    {
        if (day <= 31)
        {
            value = day;
        }
    }

    uint16_t value = 0;
};

std::ostream& operator<<(std::ostream& os, const Day& day)
{
    os << day.value;
    return os;
}

std::istream& operator>>(std::istream& in, Day& day)
{
    in >> day.value;
    return in;
}

struct Month
{
    explicit Month(uint16_t month)
    {
        if (month <= 12)
        {
            value = month;
        }
    }

    uint16_t value = 0;
};

std::ostream& operator<<(std::ostream& os, const Month& month)
{
    os << month.value;
    return os;
}

std::istream& operator>>(std::istream& in, Month& month)
{
    in >> month.value;
    return in;
}

struct Year
{
    explicit Year(uint32_t year)
    {
         value = year;
    }

    uint32_t value;
};

std::ostream& operator<<(std::ostream& os, const Year& year)
{
    os << year.value;
    return os;
}

std::istream& operator>>(std::istream& in, Year& year)
{
    in >> year.value;
    return in;
}

struct Student
{
    std::string firstName = "";
    std::string lastName = "";
    Day day = Day(0);
    Month month = Month(0);
    Year year = Year(0);

    void PrintName() const
    {
        std::cout << firstName << ' ' << lastName;
    }

    void PrintDate() const
    {
        std::cout << day << '.' << month << '.' << year;
    } 
};

std::istream& operator>>(std::istream& in, Student& student)
{
    in >> student.firstName >> student.lastName >> student.day >> student.month >> student.year;

    return in;
}

//int main()
//{
//    int studentsNumber;
//    std::cin >> studentsNumber;
//    std::vector<Student> students(studentsNumber);
//
//    for (auto& student : students)
//    {
//        std::cin >> student;
//    }
//
//    int commandsNumber;
//    std::cin >> commandsNumber;
//
//    for (int i = 0; i < commandsNumber; ++i)
//    {
//        std::string query;
//        int requestStudent;
//
//        std::cin >> query >> requestStudent;
//
//        auto index = requestStudent - 1;
//        if (index >= 0 && index < students.size())
//        {
//            if (query == "name")
//            {
//                students[index].PrintName();
//                std::cout << "\n";
//            }
//            else if (query == "date")
//            {
//                students[index].PrintDate();
//                std::cout << "\n";
//            }
//            else
//            {
//                std::cout << "bad request" << "\n";
//            }
//        }
//        else
//        {
//            std::cout << "bad request" << "\n";
//        }
//    }
//
//    return 0;
//}