#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int smallestDistancePair(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    int l = 0, r = nums[n - 1] - nums[0], m, cnt;
    while (l <= r) {
      m = l + (r - l) / 2;
      cnt = f(nums, m);
      if (cnt >= k) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
  int f(vector<int> &nums, int limit) {
    int cnt = 0;
    for (int l = 0, r = 0; l < nums.size(); l++) {
      while (r + 1 < nums.size() && nums[r + 1] - nums[l] <= limit) r++;
      cnt += r - l;
    }
    return cnt;
  }
};