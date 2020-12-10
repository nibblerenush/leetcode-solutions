#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    std::queue<std::vector<int>> work_queue;

    for (int num : nums) {
      work_queue.push({ num });
    }

    while (work_queue.size() != 1) {
      auto vec1 = std::move(work_queue.front());
      work_queue.pop();

      auto vec2 = std::move(work_queue.front());
      work_queue.pop();

      std::vector<int> vec3(vec1.size() + vec2.size());
      std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
      work_queue.push(std::move(vec3));
    }

    return std::move(work_queue.front());
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> nums(n, 0);
  for (int& num : nums) {
    std::cin >> num;
  }

  Solution solution;
  for (int num : solution.sortArray(nums)) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;

  return 0;
}
