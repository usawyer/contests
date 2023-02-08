#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int TotalSum(std::vector<int>& v) {
  int decrease = 0;
  int sum = 0;
  for (int i = 0; i < v.size(); ++i) {
    int add = v[i] - decrease;
    sum += add;
    decrease++;
  }
  return sum;
}

std::pair<int, int> TryNext(std::vector<int>& m, std::vector<int>& tmp,
                            int& downer) {
  std::pair<int, int> sum;
  int next = *(m.begin()) - downer;
  sum.first = std::accumulate(m.begin(), m.end(), 0) - downer;
  sum.second = std::accumulate(tmp.begin(), tmp.end(), 0) + next;
  downer++;
  return sum;
}

int main() {
  int quotes, boards;
  std::cin >> quotes >> boards;

  std::vector<int> motivation;

  for (int i = 0; i < quotes; ++i) {
    int num;
    std::cin >> num;
    motivation.push_back(num);
  }
  int result = 1;

  std::sort(motivation.begin(), motivation.end(), std::greater<int>());
  int sum = std::accumulate(motivation.begin(), motivation.end(), 0);

  if (sum < boards)
    result = -1;
  else {
    int sum_with_decrease = TotalSum(motivation);
    if (sum_with_decrease >= boards)
      result = 1;
    else {
      int remain_boards = boards;

      while (sum_with_decrease < remain_boards) {
        std::vector<int> tmp;
        int num = motivation.front();
        tmp.push_back(num);
        remain_boards -= motivation.front();
        motivation.erase(motivation.begin());

        if (motivation.front() - motivation.back() > 1) {
          int downer = 1;
          std::pair<int, int> sum_pair = TryNext(motivation, tmp, downer);

          while (sum_pair.second < sum_pair.first) {
            tmp.push_back(num);
            motivation.erase(motivation.begin());
            remain_boards -= num;

            num = *(motivation.begin()) - downer;

            sum_pair = TryNext(motivation, tmp, downer);
          }
        }

        sum_with_decrease = TotalSum(motivation);
        result++;
      }
    }
  }

  std::cout << result << std::endl;
}
