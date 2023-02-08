#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int first_set;
  std::cin >> first_set;

  bool first_sym[first_set];
  for (int i = 0; i < first_set; ++i) {
    bool num;
    std::cin >> num;
    first_sym[i] = num;
  }

  std::vector<bool> first;
  for (int i = 0; i < first_set; ++i) {
    int num;
    std::cin >> num;
    while (num != 0) {
      first.push_back(first_sym[i]);
      num--;
    }
  }

  int second_set;
  std::cin >> second_set;

  bool second_sym[second_set];
  for (int i = 0; i < second_set; ++i) {
    bool num;
    std::cin >> num;
    second_sym[i] = num;
  }

  std::vector<int> result;
  int count = 0;

  std::vector<bool> second;
  for (int i = 0; i < second_set; ++i) {
    int num;
    std::cin >> num;
    while (num != 0) {
      second.push_back(second_sym[i]);
      if (second.back() != first[count]) {
        result.push_back(count + 1);
      }
      count++;
      num--;
    }
  }

  std::cout << std::accumulate(result.begin(), result.end(), 0) << std::endl;
}
