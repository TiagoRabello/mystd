#include <mystd/iterator.h> // For mystd::make_reverse_iterator

#include <algorithm> // For std::for_each
#include <iostream> // For std::cout
#include <iterator> // For std::ostream_iterator

int main()
{
  int numbers[] = { 0, 1, 2, 3, 4, 5 };

  // Print elements to standard output in order.
  auto first = std::begin(numbers);
  auto last = std::end(numbers);
  std::copy(first, last, std::ostream_iterator<int>(std::cout, " "));

  std::cout << std::endl;

  // Print elements to standard output in reverse order.
  auto r_first = mystd::make_reverse_iterator(std::end(numbers));
  auto r_last = mystd::make_reverse_iterator(std::begin(numbers));
  std::copy(r_first, r_last, std::ostream_iterator<int>(std::cout, " "));

  std::cout << std::endl;

  return 0;
}