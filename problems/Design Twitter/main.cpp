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

class Twitter {
public:
  Twitter()
  {}

  void postTweet(int userId, int tweetId) {
    ++counter;
    tweet_t tweet(counter, tweetId);
    userTweets[userId].insert(tweet);
    userFeed[userId].insert(tweet);

    const unordered_set<int>& followers = userFollowers[userId];
    for (int followerId : followers) {
      userFeed[followerId].insert(tweet);
    }
  }
  
  vector<int> getNewsFeed(int userId) {
    vector<int> tweets;
    
    auto iter = userFeed[userId].begin();
    for (int i = 0; i < 10 && iter != userFeed[userId].end(); ++i) {
      tweets.push_back(iter->second);
      ++iter;
    }

    return tweets;
  }
  
  void follow(int followerId, int followeeId) {
    userFollowers[followeeId].insert(followerId);
    
    const set<tweet_t>& tweets = userTweets[followeeId];
    for (const auto& tweet : tweets) {
      userFeed[followerId].insert(tweet);
    }
  }
  
  void unfollow(int followerId, int followeeId) {
    userFollowers[followeeId].erase(followerId);
    
    const set<tweet_t>& tweets = userTweets[followeeId];
    for (const auto& tweet : tweets) {
      userFeed[followerId].erase(tweet);
    }
  }

private:
  int counter = 0;
  using tweet_t = pair<int, int>;
  unordered_map<int, set<tweet_t>> userTweets;
  unordered_map<int, set<tweet_t, greater<tweet_t>>> userFeed;
  unordered_map<int, unordered_set<int>> userFollowers;
};

int main() {
  return 0;
}
