#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  long long maxRunTime(int n, vector<int> &batteries) {
    int size = batteries.size();
    if (size < n) return 0;
    long long sum = 0;
    for (int i = 0; i < size; i++) {
      sum += batteries[i];
    }
    long long ans = 0;
    for (long long l = 1, r = sum / n, m = l + (r - l) / 2; l <= r; m = l + (r - l) / 2) {
      sum = 0;
      for (int cap : batteries) {
        sum += min((long long)cap, m);
      }
      if (sum >= m * n) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};