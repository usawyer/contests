#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int set, to_build;
  std::cin >> set >> to_build;

  std::vector<int> res;

  for (int i = 0; i < to_build; ++i) res.push_back(set / to_build);

  int count = 0;
  while (std::accumulate(res.begin(), res.end(), 0) != set) {
    res[count]++;
    count++;
  }

  int min = 0;
  for (auto& i : res) {
    min += pow(i, 2);
  }

  int max = (1 * (to_build - 1)) + pow(set - (to_build - 1), 2);
  std::cout << min << " " << max;
}
