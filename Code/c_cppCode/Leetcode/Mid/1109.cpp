#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  static const int MAX_N = 2 * 1e4 + 10;
  int cnt[MAX_N];
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> ans(n);
    for (auto booking : bookings) {
      cnt[booking[0]] += booking[2];
      cnt[booking[1] + 1] -= booking[2];
    }
    for (int i = 1; i <= n; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      ans[i - 1] = cnt[i];
    }
    return ans;
  }
};