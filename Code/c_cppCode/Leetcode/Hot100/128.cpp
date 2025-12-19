#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution1 {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return 1;
    int res = 1;
    int temp = 1;
    set<int> numSet(nums.begin(), nums.end());
    set<int>::iterator it = numSet.begin();
    while (it != numSet.end()) {
      int now = *it++;
      if (it == numSet.end()) break;
      int nxt = *it;
      if (nxt - now == 1) {
        temp++;
      } else {
        res = max(temp, res);
        temp = 1;
      }
    }
    return max(res, temp);
  }
};
class Solution {
public:
  static const int MAX_N = 1e6;
  static const int LENGTH = 32;
  int slots[MAX_N];
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return 1;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int maxIdx = 0;
    int res = 1;
    int temp = 0;
    for (int i = 0; i < nums.size(); i++) {
      minVal = min(nums.at(i), minVal);
      maxVal = max(nums.at(i), maxVal);
    }
    // Num size is small, use the hash bucket
    if (maxVal - minVal < MAX_N * 32) {
      for (int i = 0, idx, offset, num; i < nums.size(); i++) {
        num = nums.at(i) - minVal;
        idx = num / LENGTH;
        offset = num % LENGTH;
        slots[idx] |= 1 << offset;
        maxIdx = max(idx, maxIdx);
      }
      for (int i = 0; i <= maxIdx; i++) {
        for (int j = 0; j < LENGTH; j++) {
          if (slots[i] & (1 << j)) {
            temp++;
          } else {
            res = max(temp, res);
            temp = 0;
          }
        }
      }
      res = max(temp, res);
    } else {
      /*
       * Start to enum from the least num of the sequence.
       * Skip all nums that is not the least.
       */
      unordered_set<int> us(nums.begin(), nums.end());
      for (auto &n : us) {
        int num = n;
        if (!us.count(num - 1)) {
          while (us.count(num)) {
            temp++;
            num++;
          }
          res = max(res, temp);
          temp = 0;
        }
      }
    }
    return res;
  }
};
int main() {
  Solution *s = new Solution();
  vector<int> nums;
  nums.push_back(-1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(0);
  s->longestConsecutive(nums);
  return 0;
}