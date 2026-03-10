#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] <= 0) nums[i] = n + 2;
    }
    for (int i = 0, posi; i < n; i++) {
      posi = abs(nums[i]);
      if (posi <= n && nums[posi - 1] > 0)
        nums[posi - 1] = -nums[posi - 1];
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) return i + 1;
    }
    return n + 1;
  }
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n;
    while (l < r) {
      if (nums[l] == l + 1) {
        l++;
      } else if (nums[l] <= l || nums[l] > n || nums[l] == nums[nums[l] - 1]) {
        swap(nums[l], nums[--r]);
      } else {
        swap(nums[l], nums[nums[l] - 1]);
      }
    }
    return l + 1;
  }
};

int main() {
  Solution s;
  vector<int> nums({1, 2, 0});
  s.firstMissingPositive(nums);
  return 0;
}