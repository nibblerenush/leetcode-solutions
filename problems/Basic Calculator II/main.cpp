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
  int calculate(string s)
  {
    vector<string> output;
    stack<char> op_stack;
    int number = 0;
    
    // Get Reverse Polish notation
    for (char c : s)
    {
      if (isspace(c))
      {
        continue;
      }
      else if (isdigit(c))
      {
        number *= 10;
        number += c - '0';
      }
      else
      {
        output.push_back(to_string(number));
        number = 0;
        
        while (!op_stack.empty() && is_higher_or_equal_priority(op_stack.top(), c))
        {
          output.push_back({ op_stack.top() });
          op_stack.pop();
        }

        op_stack.push(c);
      }
    }

    // Post processing
    output.push_back(to_string(number));
    while (!op_stack.empty())
    {
      output.push_back({ op_stack.top() });
      op_stack.pop();
    }
    
    // Calculate Reverse Polish notation
    static const unordered_set<string> signs = {"+", "-", "*", "/"};
    stack<int> number_stack;
    for (const auto& elem : output)
    {
      if (signs.count(elem))
      {
        int num2 = number_stack.top();
        number_stack.pop();

        int num1 = number_stack.top();
        number_stack.pop();

        number_stack.push(do_operation(num1, num2, elem[0]));
      }
      else
      {
        number_stack.push(stoi(elem));
      }
    }

    return number_stack.top();
  }

private:
  bool is_higher_or_equal_priority(char op_top, char c)
  {
    if (op_top == '*' || op_top == '/')
    {
      return true;
    }
    else if (c == '+' || c == '-')
    {
      return true;
    }
    return false;
  }

  int do_operation(int num1, int num2, char op)
  {
    switch (op)
    {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    case '/':
      return num1 / num2;
    }

    return -1;
  }
};

int main() {
  return 0;
}
