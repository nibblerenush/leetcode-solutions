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

class Solution
{
public:
  // Implementation of Sieve of Eratosthenes
  int countPrimes(int n)
  {
    int count_primes = 0;
    vector<bool> is_prime(n, true);
    
    for (long long i = 2; i < n; ++i)
    {
      if (is_prime[i])
      {
        ++count_primes;
        for (long long j = i * i; j < n; j += i)
        {
          is_prime[j] = false;
        }
      }
    }

    return count_primes;
  }
};

int main() {
  return 0;
}
