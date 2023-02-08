#include <iostream>
#include <map>
#include <vector>

void Func(std::map<int, std::vector<int>>& tree, std::vector<int>& result,
          int index, int counter, int value) {
  result[index] += value;
  if (counter) {
    for (auto& it : tree[index]) {
      int temp_counter = counter;
      Func(tree, result, it, --temp_counter, value);
    }
  }
}

int main() {
  int towns;
  std::cin >> towns;

  std::map<int, std::vector<int>> tree;

  for (auto i = 0; i < towns - 1; ++i) {
    int num, num2;
    std::cin >> num >> num2;
    tree[num].push_back(num2);
  }

  int set;
  std::cin >> set;

  std::vector<int> result(towns + 1);

  for (auto i = 0; i < set; ++i) {
    int massive[3]{0};
    for (int j = 0; j < 3; ++j) std::cin >> massive[j];
    Func(tree, result, massive[0], massive[1], massive[2]);
  }

  for (int i = 1; i < result.size(); ++i) {
    std::cout << result[i];
    if (i != result.size() - 1) std::cout << " ";
  }
}
