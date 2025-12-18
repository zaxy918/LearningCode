#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> ht;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      if (ht.find(target - nums.at(i)) != ht.end()) {
        res.push_back(ht[target - nums.at(i)]);
        res.push_back(i);
        return res;
      }
      ht[nums.at(i)] = i;
    }
    return vector<int>(0);
  }
};
class Solution1 {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int len = nums.size();
    vector<int> res;
    vector<int> num(nums);
    sort(num.begin(), num.end());
    int l = 0, r = len - 1;
    int sum = num.at(l) + num.at(r);
    while (sum != target) {
      if (sum < target) {
        sum = num.at(++l) + num.at(r);
      }
      if (sum > target) {
        sum = num.at(l) + num.at(--r);
      }
    }
    for (int i = 0; i < len; i++) {
      if (res.size() == 2) break;
      if (nums[i] == num[l])
        res.push_back(i);
      else if (nums[i] == num[r])
        res.push_back(i);
    }
    return res;
  }
};
