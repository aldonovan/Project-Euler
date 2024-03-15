#include <iostream>
#include <vector>

int64_t FindNumWays(const int b, const int w) {
  std::vector<std::vector<int64_t>> num_ways(b + 1,
                                             std::vector<int64_t>(w + 1, 0));
  num_ways[0][0] = 1;
  for (int candidate_b = 0; candidate_b <= b; ++candidate_b) {
    for (int candidate_w = 0; candidate_w <= w; ++candidate_w) {
      if (candidate_b == 0 && candidate_w == 0) continue;
      for (int curr_b = candidate_b; curr_b <= b; ++curr_b) {
        for (int curr_w = candidate_w; curr_w <= w; ++curr_w) {
          num_ways[curr_b][curr_w] +=
              num_ways[curr_b - candidate_b][curr_w - candidate_w];
        }
      }
    }
  }
  return num_ways[b][w];
}

int main() { std::cout << FindNumWays(60, 40) << '\n'; }