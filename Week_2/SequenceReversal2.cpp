#include <iostream>
#include <vector>

std::vector<int> SequenceReversal(const std::vector<int>& v);

int main()
{
  std::vector<int> numbers = { 1, 5, 3, 4, 2 };
  auto reverse = SequenceReversal(numbers);

  for (auto n : reverse)
  {
    std::cout << n << std::endl;
  }
}


std::vector<int> SequenceReversal(const std::vector<int>& v)
{
  std::vector<int> reverse;
  auto index = v.size() - 1;

  for (int i = index; i >= 0; --i)
  {
    reverse.push_back(v[i]);
  }

  return reverse;
}
