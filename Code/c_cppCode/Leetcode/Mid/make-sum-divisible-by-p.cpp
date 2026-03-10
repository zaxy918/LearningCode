#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  static const int MAX_N = 1e5 + 10;
  int minSubarray(vector<int> &nums, int p) {
    long long sumAll = 0, res = nums.size();
    for (int n : nums) sumAll += n;
    int remainder = sumAll % p;
    if (remainder == 0) return 0;
    unordered_map<int, int> hashmap;
    hashmap[0] = -1;
    for (long long i = 0, sum = 0, rem, pre; i < nums.size(); i++) {
      sum += nums.at(i);
      rem = sum % p;
      pre = rem - remainder >= 0 ? rem - remainder : rem - remainder + p;
      if (hashmap.count(pre)) {
        res = min(res, i - hashmap[pre]);
      }
      hashmap[rem] = i;
    }
    return res == nums.size() ? -1 : res;
  }
};