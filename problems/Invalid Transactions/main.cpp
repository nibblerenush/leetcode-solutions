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
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    const int n = static_cast<int>(transactions.size());

    vector<Transaction> trans;
    for (int i = 0; i < n; ++i) {
      istringstream oss(transactions[i]);
      string part;
      vector<string> parts;
      while (getline(oss, part, ',')) {
        parts.push_back(move(part));
      }
      Transaction tran;
      tran.name = move(parts[0]);
      tran.time = stoi(parts[1]);
      tran.amount = stoi(parts[2]);
      tran.city = move(parts[3]);
      trans.push_back(move(tran));
    }
    
    unordered_set<int> invalidIndexes;
    for (int i = 0; i < n; ++i) {
      if (trans[i].amount > 1000) {
        invalidIndexes.insert(i);
      }
      
      for (int j = i + 1; j < n; ++j) {
        if (trans[i].name == trans[j].name &&
            abs(trans[i].time - trans[j].time) <= 60 &&
            trans[i].city != trans[j].city)
        {
          invalidIndexes.insert(i);
          invalidIndexes.insert(j);
        }
      }
    }

    vector<string> invalidTrans;
    for (int index : invalidIndexes) {
      invalidTrans.push_back(transactions[index]);
    }

    return invalidTrans;
  }

private:
  struct Transaction {
    string name;
    int time = 0;
    int amount = 0;
    string city;
  };
};

int main() {
  return 0;
}
