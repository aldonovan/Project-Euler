#include <iostream>
#include <utility>
#include <vector>

int64_t Combination(int n, int k) {
  int64_t result = n;
  for (int i = 1; i < k; ++i) {
    result *= n - i;
  }
  for (int i = k; i >= 2; --i) {
    result /= i;
  }
  return result;
}

int64_t NumWays(const std::vector<int>& counts, int num_digits) {
  std::vector<int64_t> ways(num_digits + 1, 0);
  ways[0] = 1;
  for (int index = 0; index < counts.size(); ++index) {
    std::vector<int64_t> new_ways = ways;
    for (int count = 1; count <= counts[index]; ++count) {
      for (int total = count; total <= num_digits; ++total) {
        new_ways[total] += Combination(total, count) * ways[total - count];
      }
    }
    ways = std::move(new_ways);
  }
  return ways[num_digits];
}

int64_t Solve(int num_digits) {
  std::vector<int> counts(10, 3);
  counts[1] = 2;
  return 9 * NumWays(counts, num_digits - 1);
}

int main() { std::cout << Solve(18) << '\n'; }
