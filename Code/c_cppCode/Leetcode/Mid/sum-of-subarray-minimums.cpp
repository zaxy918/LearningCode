#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  static const int MOD = 1e9 + 7;
  int sumSubarrayMins(vector<int> &arr) {
    int n = arr.size();
    stack<int> stk;
    int cur_idx, ans;
    ans = 0;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && arr[stk.top()] >= arr[i]) {
        cur_idx = stk.top(), stk.pop();
        ans = (ans + ((long long)(cur_idx - (stk.empty() ? -1 : stk.top())) * (i - cur_idx) * arr[cur_idx]) % MOD) % MOD;
      }
      stk.push(i);
    }
    while (!stk.empty()) {
      cur_idx = stk.top(), stk.pop();
      ans = (ans + ((long long)(cur_idx - (stk.empty() ? -1 : stk.top())) * (n - cur_idx) * arr[cur_idx])) % MOD;
    }
    return ans;
  }
};
int main() {
  Solution s;
  vector<int> arr({3, 1, 2, 4});
  s.sumSubarrayMins(arr);
  return 0;
}