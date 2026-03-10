#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    for (int i = 0, e, o; i < nums.size(); i++) {
      if (i % 2 == 1) {
        o = i;
        while (o < nums.size()) {
          if (nums[o] % 2 == 1) {
            swap(nums[i], nums[o]);
            break;
          } else {
            o++;
          }
        }
      } else {
        e = i;
        while (e < nums.size()) {
          if (nums[e] % 2 == 0) {
            swap(nums[i], nums[e]);
            break;
          } else {
            e++;
          }
        }
      }
    }
    return nums;
  }
  vector<int> sortArrayByParityII2(vector<int> &nums) {
    int e = 0, o = 1, n = nums.size();
    while (e < n && o < n) {
      if (nums[n - 1] % 2) {
        swap(nums[n - 1], nums[o]);
        o += 2;
      } else {
        swap(nums[n - 1], nums[e]);
        e += 2;
      }
    }
    return nums;
  }
};