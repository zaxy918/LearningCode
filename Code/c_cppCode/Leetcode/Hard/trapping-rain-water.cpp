#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 1, highest = height[0]; i < n; i++) {
      highest = max(height[i], highest);
      left[i] = highest;
    }
    for (int i = n - 2, highest = height[n - 1]; i >= 0; i--) {
      highest = max(height[i], highest);
      right[i] = highest;
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      ans += max(0, min(left[i], right[i]) - height[i]);
    }
    return ans;
  }
  int trap2(vector<int> &height) {
    int n = height.size(), l = 1, r = n - 2, lmax = height[0], rmax = height[n - 1];
    int ans = 0;
    while (l <= r) {
      if (lmax < rmax) {
        lmax = max(height[l], lmax);
        ans += max(lmax - height[l++], 0);
      } else {
        rmax = max(height[r], rmax);
        ans += max(rmax - height[r--], 0);
      }
    }
    return ans;
  }
};