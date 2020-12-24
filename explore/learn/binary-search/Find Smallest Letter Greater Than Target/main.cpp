#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    size = letters.size();

    int left = 0;
    int right = size - 1;

    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      if (check_is_greatest_letter(letters, mid, target)) {
        return letters[mid];
      }
      else if (letters[mid] <= target) {
        left = mid;
      }
      else {
        right = mid;
      }
    }

    if (check_is_greatest_letter(letters, left, target)) {
      return letters[left];
    }

    if (check_is_greatest_letter(letters, right, target)) {
      return letters[right];
    }

    return letters[0];
  }

private:
  bool check_is_greatest_letter(const vector<char>& letters, int index, char target) {
    int left_index = index - 1;
    int right_index = index + 1;
    
    bool is_mid_bigger = letters[index] > target;
    bool is_left_smaller_equal = left_index >= 0 ? letters[left_index] <= target : true;
    bool is_right_bigger = right_index < size ? letters[right_index] > target : true;
    return is_mid_bigger && is_left_smaller_equal && is_right_bigger;
  }

private:
  int size = 0;
};

int main() {
  char target;
  int n;
  cin >> target >> n;

  vector<char> letters(n);
  for (auto& c : letters) {
    cin >> c;
  }

  Solution solution;
  cout << solution.nextGreatestLetter(letters, target) << endl;
  return 0;
}
