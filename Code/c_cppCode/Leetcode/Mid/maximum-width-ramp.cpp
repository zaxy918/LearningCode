#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int maxWidthRamp(vector<int> &nums) {
    stack<int> stk; // Store the possible left index of the widest ramp
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      if (!stk.empty() && nums[i] >= nums[stk.top()]) {
        continue;
      }
      stk.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
      if (stk.empty()) break;
      while (!stk.empty() && nums[i] >= nums[stk.top()]) {
        int cur_idx = stk.top();
        stk.pop();
        ans = max(ans, i - cur_idx);
      }
    }
    return ans;
  }
};