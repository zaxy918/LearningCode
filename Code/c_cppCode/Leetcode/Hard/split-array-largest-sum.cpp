#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int splitArray(vector<int> &nums, int k) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    int l = 1, r = sum, m, need, ans = 0;
    while (l <= r) {
      m = l + (r - l) / 2;
      need = f(nums, m);
      if (need <= k) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
  int f(vector<int> &nums, int m) {
    int need = 1, sum = 0;
    for (int num : nums) {
      if (num > m) return INT_MAX;
      sum += num;
      if (sum > m) {
        need++;
        sum = num;
      }
    }
    return need;
  }
};