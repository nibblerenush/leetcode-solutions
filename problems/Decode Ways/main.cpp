#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int numDecodings(string s)
  {
    // index of vector "dynamic" is length of input string
    // value of vector "dynamic" is result of function numDecodings
    vector<int> dynamic(s.length() + 1, 0);
    dynamic[0] = 1;
    dynamic[1] = check_number(s.substr(0, 1)) ? 1 : 0;

    for (int i = 2; i < (int)dynamic.size(); ++i)
    {
      dynamic[i] += check_number(s.substr(i - 1, 1)) ? dynamic[i - 1] : 0;
      dynamic[i] += check_number(s.substr(i - 2, 2)) ? dynamic[i - 2] : 0;
    }

    return dynamic.back();
  }

private:
  bool check_number(const string& str_num)
  {
    if (str_num[0] == '0') {
      return false;
    }
    
    int int_num = stoi(str_num);
    return int_num >= 1 && int_num <= 26;
  }
};

int main() {
  return 0;
}
