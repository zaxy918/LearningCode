#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int ans = INT_MAX;
    for (int i = 0, l = 0, sum = 0; i < nums.size(); i++) {
      sum += nums[i];
      while (sum >= target) {
        ans = min(ans, i - l + 1);
        sum -= nums[l++];
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};