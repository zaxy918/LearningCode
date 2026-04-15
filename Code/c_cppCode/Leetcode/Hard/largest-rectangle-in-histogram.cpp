#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int ans = 0, cur_idx, cur_max;
    int n = heights.size();
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && heights[i] <= heights[stk.top()]) {
        cur_idx = stk.top(), stk.pop();
        cur_max = heights[cur_idx] * (i - (stk.empty() ? -1 : stk.top()) - 1);
        ans = max(cur_max, ans);
      }
      stk.push(i);
    }
    while (!stk.empty()) {
      cur_idx = stk.top(), stk.pop();
      cur_max = heights[cur_idx] * (n - (stk.empty() ? -1 : stk.top()) - 1);
      ans = max(cur_max, ans);
    }
    return ans;
  }
};