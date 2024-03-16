#include <iostream>
#include <utility>
#include <vector>

int Remainder(int64_t n) {
  if (n % 250 == 0) return 0;
  // Find n^n mod 250
  // We use binary to make the calculation fast enough.
  // Note that we can't use Euler's or Fermat's since
  // there is no guarantee of the relatively prime condition.
  int power = n;
  int result = 1;
  int curr_result = n % 250;
  while (power > 0) {
    if (power % 2 != 0) {
      result = (result * curr_result) % 250;
    }
    curr_result = (curr_result * curr_result) % 250;
    power /= 2;
  }
  return result;
}

void Solve() {
  std::vector<int64_t> num_ways(250, 0);
  num_ways[0] = 1;
  for (int i = 1; i <= 250250; ++i) {
    int remainder = Remainder(i);
    std::vector<int64_t> new_ways = num_ways;
    for (int j = 0; j < 250; ++j) {
      int next_index = (j + remainder) % 250;
      new_ways[next_index] =
          (new_ways[next_index] + num_ways[j]) % 10'000'000'000'000'000;
    }
    num_ways = std::move(new_ways);
  }
  std::cout << num_ways[0] - 1 << '\n';
}

int main() { Solve(); }
