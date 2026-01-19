#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int res = 0;
    unordered_map<int, int> hashmap;
    // The sum of 0 occurs when there is no number (visually)
    hashmap[0] = 1;
    for (int i = 0, sum = 0; i < nums.size(); i++) {
      sum += nums.at(i);
      if (hashmap.count(sum - k)) res += hashmap[sum - k];
      hashmap[sum]++;
    }
    return res;
  }
};