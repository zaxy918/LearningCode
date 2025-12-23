#include <iostream>
#include <vector>
using namespace std;
class Solution1 {
public:
  void moveZeroes(vector<int> &nums) {
    int cnt = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums.at(i) == 0) {
        cnt++;
        for (int j = i; j < nums.size() - cnt; j++) {
          swap(nums.at(j), nums.at(j + 1));
        }
      }
    }
  }
};
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    if (nums.size() == 0) return;
    int l = 0, r = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums.at(l)) {
        r++;
      } else {
        swap(nums.at(l), nums.at(r));
      }
    }
  }
};