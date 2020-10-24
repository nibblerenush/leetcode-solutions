#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int bagOfTokensScore(std::vector<int>& tokens, int P) {
    std::sort(tokens.begin(), tokens.end());
    
    int cur_score = 0;
    int result_score = cur_score;
    int left = 0;
    int right = static_cast<int>(tokens.size()) - 1;
    
    while (left <= right) {
      if (P >= tokens[left]) {
        result_score = std::max(result_score, ++cur_score);
        P -= tokens[left++];
      }
      else if (cur_score > 0) {
        P += tokens[right--];
        cur_score--;
      }
      else {
        break;
      }
    }
    return result_score;
  }
};

int main() {
  std::vector<int> tokens = { 100 };
  int P = 50;

  Solution solution;
  std::cout << solution.bagOfTokensScore(tokens, P) << std::endl;
  return 0;
}
