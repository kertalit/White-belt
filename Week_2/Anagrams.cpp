#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


std::unordered_map<char, int> BuildCharCounters(const std::string& word)
{
    std::unordered_map<char, int> counter;
    for (char ch : word)
    {
        counter[ch]++;
    }
    return counter;
}

bool IsAnagrams(const std::string& word1, const std::string& word2)
{
  if (word1.size() != word2.size())
  {
      return false;
  }

  return BuildCharCounters(word1) == BuildCharCounters(word2);
}

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::string word1, word2;
        std::cin >> word1 >> word2;

        if (IsAnagrams(word1, word2))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
