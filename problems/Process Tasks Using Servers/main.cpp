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
  struct Server
  {
    int weight = 0;
    int index = 0;
  };
  
  class ServerCompare
  {
  public:
    bool operator()(const Server& lh, const Server& rh)
    {
      if (lh.weight == rh.weight) return lh.index > rh.index;
      return lh.weight > rh.weight;
    }
  };

  struct Task
  {
    long endTime = 0;
    Server server;
  };

  class TaskCompare
  {
  public:
    bool operator()(const Task& lh, const Task& rh)
    {
      return lh.endTime > rh.endTime;
    }
  };

public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks)
  {
    const int serversSize = servers.size();
    const int tasksSize = tasks.size();

    priority_queue<Server, vector<Server>, ServerCompare> serversPq;
    for (int i = 0; i < serversSize; ++i)
    {
      Server server;
      server.weight = servers[i];
      server.index = i;
      serversPq.push(server);
    }
    
    vector<int> ans(tasksSize);
    priority_queue<Task, vector<Task>, TaskCompare> tasksPq;
    long threshold = 0;
    
    for (int i = 0; i < tasksSize; ++i)
    {
      threshold = max(threshold, long(i));
      if (serversPq.empty())
      {
        threshold = max(threshold, tasksPq.top().endTime);
      }

      while (!tasksPq.empty())
      {
        Task task = tasksPq.top();
        if (task.endTime <= threshold)
        {
          tasksPq.pop();
          serversPq.push(task.server);
        }
        else break;
      }
      
      Server server = serversPq.top();
      serversPq.pop();

      Task task;
      task.endTime = threshold + tasks[i];
      task.server = server;

      ans[i] = server.index;
      tasksPq.push(task);
    }

    return ans;
  }
};

int main() {
  return 0;
}
