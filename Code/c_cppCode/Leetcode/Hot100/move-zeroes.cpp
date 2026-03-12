#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    if (nums.size() <= 1) return;
    int slow = 0;
    while (slow < nums.size() && nums.at(slow) != 0) slow++;
    for (int fast = slow + 1; fast < nums.size(); fast++) {
      if (nums.at(fast) != 0) {
        swap(nums.at(slow), nums.at(fast));
        slow++;
      }
    }
  }

  void moveZeros2(vector<int> &nums) {
    int left = 0, right = 0;
    while (right < nums.size()) {
      if (nums.at(right)) {
        swap(nums.at(right), nums.at(left));
        left++;
      }
      right++;
    }
  }
};