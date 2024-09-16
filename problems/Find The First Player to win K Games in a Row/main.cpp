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
    int findWinningPlayer(vector<int>& skills, int k) {
        const int n = static_cast<int>(skills.size());
        if (k >= n) {
            auto iter = max_element(skills.begin(), skills.end());
            return static_cast<int>(distance(skills.begin(), iter));
        }
        else {
            deque<pair<int, int>> gameQueue;
            for (int i = 0; i < n; ++i) {
                gameQueue.push_back({ skills[i], i });
            }
            unordered_map<int, int> indexGameWinCount;
            while (1) {
                auto gamer1 = gameQueue.front();
                gameQueue.pop_front();
                auto gamer2 = gameQueue.front();
                gameQueue.pop_front();
                auto winner = gamer1 > gamer2
                    ? helper(gamer1, gamer2, gameQueue, indexGameWinCount)
                    : helper(gamer2, gamer1, gameQueue, indexGameWinCount);
                if (winner.second == k) {
                    return winner.first;
                }
            }
        }
    }

private:
    pair<int, int> helper(
        const pair<int, int>& gamer1,
        const pair<int, int>& gamer2,
        deque<pair<int, int>>& gameQueue,
        unordered_map<int, int>& indexGameWinCount)
    {
        gameQueue.push_front(gamer1);
        gameQueue.push_back(gamer2);
        ++indexGameWinCount[gamer1.second];
        return { gamer1.second, indexGameWinCount[gamer1.second] };
    }
};

int main() {
	return 0;
}
