//#include <iostream>
//#include <sstream>
//
//class rational
//{
//public:
//    rational() :
//        numerator_(0),
//        denominator_(1)
//    {
//    }
//
//    rational(int numerator, int denominator)
//    {
//        if (numerator == 0)
//        {
//            numerator_ = 0;
//            denominator_ = 1;
//            return;
//        }
//
//        if (numerator == denominator)
//        {
//            numerator_ = 1;
//            denominator_ = 1;
//
//            return;
//        }
//
//        int nod = calculatenod(numerator, denominator);
//
//        numerator_ = numerator / nod;
//        denominator_ = denominator / nod;
//    }
//
//    int numerator() const
//    {
//        return numerator_;
//    }
//
//    int denominator() const
//    {
//        return denominator_;
//    }
//
//    bool operator==(const rational& other)
//    {
//        return numerator_ == other.numerator_ && denominator_ == other.denominator_;
//    }
//
//    rational operator+(const rational& other)
//    {
//        if (denominator_ == other.denominator_)
//        {
//            return { numerator_ + other.numerator_, denominator_ };
//        }
//
//        auto nok = calculatenok(denominator_, other.denominator_);
//        auto newnumerator = numerator_ * nok / denominator_ + other.numerator_ * nok / other.denominator_;
//
//        return { newnumerator, nok };
//    }
//
//    rational operator-(const rational& other)
//    {
//        if (denominator_ == other.denominator_)
//        {
//            return { numerator_ + other.numerator_, denominator_ };
//        }
//
//        auto nok = calculatenok(denominator_, other.denominator_);
//        auto newnumerator = numerator_ * nok / denominator_ - other.numerator_ * nok / other.denominator_;
//
//        return { newnumerator, nok };
//    }
//
//    rational operator/(const rational& other)
//    {
//        return { numerator_ * other.denominator_, denominator_ * other.numerator_};
//    }
//
//    rational operator*(const rational& other)
//    {
//        return { numerator_ * other.numerator_, denominator_ * other.denominator_ };
//    }
//
//private:
//
//    int calculatenod(int first, int second)
//    {
//        auto greater = std::max(first, second);
//        auto smallest = std::min(first, second);
//
//        int nod;
//        int remainder;
//
//        do
//        {
//            remainder = greater % smallest;
//
//            nod = smallest;
//            greater = smallest;
//            smallest = remainder;
//
//        } while (remainder != 0);
//
//        return nod;
//    }
//
//    int calculatenok(int first, int second)
//    {
//        auto nod = calculatenod(first, second);
//
//        return first * second / nod;
//    }
//
//    int numerator_;
//    int denominator_;
//};
//
//std::ostream& operator<<(std::ostream& ss, const rational& other)
//{
//    ss << other.numerator() << '/' << other.denominator();
//
//    return ss;
//}
//
//std::istream& operator>>(std::istream& ss, rational& other)
//{
//    if (ss.eof() == false)
//    {
//        int numerator;
//        int denominator;
//
//        ss >> numerator;
//        ss.ignore(1);
//        ss >> denominator;
//
//        other = { numerator, denominator };
//    }
//    
//    return ss;
//}
//
//
//int main()
//{
//    {
//        std::ostringstream output;
//        output << rational(-6, 8);
//        if (output.str() != "-3/4")
//        {
//            std::cout << "rational(-6, 8) should be written as \"-3/4\"" << std::endl;
//            return 1;
//        }
//    }
//
//    {
//        std::istringstream input("5/7");
//        rational r;
//        input >> r;
//        bool equal = r == rational(5, 7);
//        if (!equal)
//        {
//            std::cout << "5/7 is incorrectly read as " << r << std::endl;
//            return 2;
//        }
//    }
//
//    {
//        std::istringstream input("5/7 10/8");
//        rational r1, r2;
//        input >> r1 >> r2;
//        bool correct = r1 == rational(5, 7) && r2 == rational(5, 4);
//        if (!correct)
//        {
//            std::cout << "multiple values are read incorrectly: " << r1 << " " << r2 << std::endl;
//            return 3;
//        }
//
//        input >> r1;
//        input >> r2;
//        correct = r1 == rational(5, 7) && r2 == rational(5, 4);
//        if (!correct)
//        {
//            std::cout << "read from empty stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
//            return 4;
//        }
//    }
//    std::cout << "ok" << std::endl;
//    return 0;
//}