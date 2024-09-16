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
private:
    struct Gondola {
        int pos;
        int board;

        void free() {
            board = 0;
        }
        
        void move() {
            if (pos == 3) {
                pos = 0;
                free();
            }
            else {
                pos += 1;
            }
        }

        bool operator<(const Gondola& other) {
            return pos < other.pos;
        }
    };
    
    vector<Gondola> gondolas;

    void moveWheel() {
        for (auto& gondola : gondolas) {
            gondola.move();
        }
        sort(gondolas.begin(), gondolas.end());
    }

public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        for (int pos = 0; pos < 4; ++pos) {
            gondolas.push_back(Gondola{ pos, 0 });
        }

        int count = 0;
        int profit = 0;
        int min_count = 0;
        int max_profit = 0;
        int people = 0;
        size_t i = 0;
        
        do {
            if (i < customers.size()) {
                people += customers[i++];
            }
            
            Gondola& bottom = gondolas.front();
            if (people < 4) {
                bottom.board += people;
                people = 0;
            }
            else {
                bottom.board = 4;
                people -= 4;
            }
            
            ++count;
            profit += (bottom.board * boardingCost - runningCost);
            if (profit > max_profit) {
                max_profit = profit;
                min_count = count;
            }
            
            moveWheel();
        } while (people != 0 || i < customers.size());

        return max_profit == 0 ? -1 : min_count;
    }
};

int main() {
	return 0;
}
