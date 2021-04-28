#include <algorithm>
#include <cmath>
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
  int maxPoints(vector<vector<int>>& points) {
    const int points_size = points.size();
    unordered_map<string, unordered_set<string>> coefficients_count;
    int max_count = 1;
    
    for (int i = 0; i < points_size - 1; ++i) {
      for (int j = i + 1; j < points_size; ++j) {
        // Line formula: y = a * x + b
        string a = get_a(points[i][0], points[i][1], points[j][0], points[j][1]);
        string b = get_b(points[i][0], points[i][1], points[j][0], points[j][1]);
        string coefficients = a + ',' + b;
        
        unordered_set<string>& line = coefficients_count[coefficients];
        line.insert(get_frac(points[i]));
        line.insert(get_frac(points[j]));
        
        max_count = max(max_count, (int)line.size());
      }
    }
    
    return max_count;
  }

private:
  int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    else if (a == 0) {
      return b;
    }
    
    if (a >= b) {
      return gcd(b, a % b);
    }
    else {
      return gcd(a, b % a);
    }
  }
  
  pair<int, int> get_rational(int numerator, int denominator) {
    int p = numerator;
    int q = denominator;

    if (p == 0) {
      q = 1;
      return { p, q };
    }

    if (q < 0) {
      p = -p;
      q = -q;
    }

    int pq_gcd = gcd(abs(p), q);
    p /= pq_gcd;
    q /= pq_gcd;

    return { p, q };
  }
  
  string get_str(int numerator, int denominator, int x1) {
    // Vertical line
    if (denominator == 0) {
      return to_string(x1) + '/' + '$';
    }

    // Not vertical line
    auto nom_denom = get_rational(numerator, denominator);
    return to_string(nom_denom.first) + '/' + to_string(nom_denom.second);
  }
  
  string get_a(int x1, int y1, int x2, int y2) {
    int numerator = y2 - y1;
    int denominator = x2 - x1;
    return get_str(numerator, denominator, x1);
  }

  string get_b(int x1, int y1, int x2, int y2) {
    int numerator = (x2 - x1) * y1 - (y2 - y1) * x1;
    int denominator = x2 - x1;
    return get_str(numerator, denominator, x1);
  }
  
  string get_frac(const vector<int>& point) {
    return to_string(point[0]) + '/' + to_string(point[1]);
  }
};

int main() {
  return 0;
}
