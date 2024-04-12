#include <iostream>
#include <sstream>
#include <exception>

class Rational
{
public:
    Rational() :
        numerator_(0),
        denominator_(1)
    {
    }

    Rational(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("The denominator cannot be equal to 0");
        }

        if (numerator == 0)
        {
            numerator_ = 0;
            denominator_ = 1;
            return;
        }

        if (numerator == denominator)
        {
            numerator_ = 1;
            denominator_ = 1;

            return;
        }

        int nod = CalculateNOD(numerator, denominator);

        numerator_ = numerator / nod;
        denominator_ = denominator / nod;
    }

    int Numerator() const
    {
        return numerator_;
    }

    int Denominator() const
    {
        return denominator_;
    }

    bool operator==(const Rational& other)
    {
        return numerator_ == other.numerator_ && denominator_ == other.denominator_;
    }

    Rational operator+(const Rational& other)
    {
        if (denominator_ == other.denominator_)
        {
            return { numerator_ + other.numerator_, denominator_ };
        }

        auto nok = CalculateNOK(denominator_, other.denominator_);
        auto newNumerator = numerator_ * nok / denominator_ + other.numerator_ * nok / other.denominator_;

        return { newNumerator, nok };
    }

    Rational operator-(const Rational& other)
    {
        if (denominator_ == other.denominator_)
        {
            return { numerator_ + other.numerator_, denominator_ };
        }

        auto nok = CalculateNOK(denominator_, other.denominator_);
        auto newNumerator = numerator_ * nok / denominator_ - other.numerator_ * nok / other.denominator_;

        return { newNumerator, nok };
    }

    Rational operator/(const Rational& other)
    {
        auto numerator = numerator_ * other.denominator_;
        auto denominator = denominator_ * other.numerator_;
        
        if (denominator == 0)
        {
            throw std::domain_error("The denominator cannot be equal to 0");
        }
        else
        {
            return { numerator, denominator };
        }
    }

    Rational operator*(const Rational& other)
    {
        return { numerator_ * other.numerator_, denominator_ * other.denominator_ };
    }

private:

    int CalculateNOD(int first, int second)
    {
        auto greater = std::max(first, second);
        auto smallest = std::min(first, second);

        int nod;
        int remainder;

        do
        {
            remainder = greater % smallest;

            nod = smallest;
            greater = smallest;
            smallest = remainder;

        } while (remainder != 0);

        return nod;
    }

    int CalculateNOK(int first, int second)
    {
        auto nod = CalculateNOD(first, second);

        return first * second / nod;
    }

    int numerator_;
    int denominator_;
};

std::ostream& operator<<(std::ostream& ss, const Rational& other)
{
    ss << other.Numerator() << '/' << other.Denominator();

    return ss;
}

std::istream& operator>>(std::istream& ss, Rational& other)
{
    if (ss.eof() == false)
    {
        int numerator;
        int denominator;

        ss >> numerator;
        ss.ignore(1);
        ss >> denominator;

        other = { numerator, denominator };
    }

    return ss;
}


int main()
{
    try
    {
        Rational r(1, 0);
        std::cout << "Doesn't throw in case of zero denominator" << std::endl;
        return 1;
    }
    catch (std::invalid_argument&)
    {

    }

    try
    {
        auto x = Rational(1, 2) / Rational(0, 1);
        std::cout << "Doesn't throw in case of division by zero" << std::endl;
        return 2;
    }
    catch (std::domain_error&)
    {

    }

    std::cout << "OK" << std::endl;
    return 0;
}