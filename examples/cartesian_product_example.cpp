#include <mystd/numeric.h> // For mystd::cartesian_product

#include <iostream> // For std::cout
#include <iterator> // For std::back_inserter, std::ostream_iterator
#include <utility> // For std::pair
#include <vector> // For std::vector

int main()
{
  const int digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::vector<std::pair<int, int>> numbers;

  // Generate every number from 00 to 99.
  mystd::cartesian_product(std::begin(digits), std::end(digits)
                         , std::begin(digits), std::end(digits)
                         , std::back_inserter(numbers));

  for (auto number : numbers)
  {
    std::cout << number.first << number.second << " ";
  }

  std::cout << "\n\n";

  // Let's do it with a custom combinator now!
  mystd::cartesian_product(std::begin(digits), std::end(digits)
                         , std::begin(digits), std::end(digits)
                         , std::ostream_iterator<int>(std::cout, " ")
                         , [](int a, int b) { return a * 10 + b; });

  std::cout << "\n\n";

  return 0;
}