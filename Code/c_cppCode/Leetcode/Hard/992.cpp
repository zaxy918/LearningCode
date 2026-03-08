#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return f(nums, k) - f(nums, k - 1);
  }

  int f(vector<int> &nums, int k) {
    int cnt = 0;
    unordered_map<int, int> hashmap;
    for (int r = 0, l = 0, kinds = 0; r < nums.size(); r++) {
      if (hashmap[nums[r]]++ == 0) {
        kinds++;
        while (kinds > k) {
          if (--hashmap[nums[l++]] == 0) kinds--;
        }
      }
      cnt += r - l + 1;
    }
    return cnt;
  }
};