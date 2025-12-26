#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    unordered_map<int, int> hashMap;
    for (int i = 0; i < len; i++) {
      hashMap[nums.at(i)] = i;
    }
    int twoSum;
    vector<vector<int>> res;
    for (int i = 0; i < len; i++) {
      for (int j = len - 1; j > i; j--) {
        twoSum = nums.at(i) + nums.at(j);
        if (hashMap.find(-twoSum) != hashMap.end() && hashMap[-twoSum] > i && hashMap[-twoSum] < j) {
          vector<int> three(3);
          three[0] = nums.at(i);
          three[1] = nums.at(j);
          three[2] = nums.at(hashMap[-twoSum]);
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
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(-1);
  nums.push_back(-4);
  s->threeSum(nums);
  return 0;
}