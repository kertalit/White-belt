#include <iostream>
#include <string>
#include <vector>

class  ReversibleString
{
public:

    ReversibleString(const std::string& word) :
        word_{ word }
    {
       
    }

    ReversibleString()
    {

    }

    void Reverse()
    {
        word_ = { word_.rbegin(), word_.rend() };
    }

    std::string ToString() const
    {
        return word_;
    }

private:

    std::string word_;
};

//int main()
//{
//    ReversibleString s("live");
//    s.Reverse();
//    std::cout << s.ToString() << std::endl;
//
//    s.Reverse();
//    const ReversibleString& s_ref = s;
//    std::string tmp = s_ref.ToString();
//    std::cout << tmp << std::endl;
//    ReversibleString empty;
//    std::cout << '"' << empty.ToString() << '"' << std::endl;
//
//    return 0;
//}
