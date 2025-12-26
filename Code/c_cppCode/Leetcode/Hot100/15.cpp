#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int len = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0, target, l, r; i < len; i++) {
      if (nums.at(i) > 0) break;
      if (i > 0 && nums.at(i) == nums.at(i - 1)) continue;
      target = -nums.at(i);
      l = i + 1, r = len - 1;
      while (l < r) {
        if (nums.at(l) + nums.at(r) == target) {
          res.push_back({nums.at(i), nums.at(l), nums.at(r)});
          l++, r--;
          while (l < r && nums.at(l - 1) == nums.at(l)) l++;
          while (l < r && nums.at(r + 1) == nums.at(r)) r--;
        } else if (nums.at(l) + nums.at(r) < target) {
          l++;
        } else {
          r--;
        }
      }
    }
    return res;
  }
};
int main() {
  Solution s;
  vector<int> nums;
  nums.push_back(-100);
  nums.push_back(-70);
  nums.push_back(-60);
  nums.push_back(110);
  nums.push_back(120);
  nums.push_back(130);
  nums.push_back(160);
  s.threeSum(nums);
}