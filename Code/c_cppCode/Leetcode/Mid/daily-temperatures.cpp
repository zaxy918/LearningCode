#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> stk;
    int n = temperatures.size();
    vector<int> days(n);
    int cur_idx;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
        cur_idx = stk.top(), stk.pop();
        days[cur_idx] = i - cur_idx;
      }
      stk.push(i);
    }
    return days;
  }
};
int main() {
  Solution s;
  vector<int> temperature({73, 74, 75, 71, 69, 72, 76, 73});
  s.dailyTemperatures(temperature);
  return 0;
}