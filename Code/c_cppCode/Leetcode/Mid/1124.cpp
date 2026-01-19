#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  static const int MAX_N = 1e4 + 10;
  int preSum[MAX_N];
  int longestWPI(vector<int> &hours) {
    // More than 8 -> 1 Less equal than 8 -> -1
    for (auto &h : hours) {
      h = h > 8 ? 1 : -1;
    }
    int res = 0;
    unordered_map<int, int> hashmap;
    for (int i = 1; i <= hours.size(); i++) {
      preSum[i] = preSum[i - 1] + hours[i - 1];
      if (preSum[i] > 0) {
        res = i;
      } else {
        if (hashmap.count(preSum[i] - 1)) res = max(res, i - hashmap[preSum[i] - 1]);
      }
      if (!hashmap[preSum[i]]) hashmap[preSum[i]] = i;
    }
    return res;
  }
};

int main() {
  vector<int> hours({6, 6, 9});
  Solution s;
  cout << s.longestWPI(hours);
}