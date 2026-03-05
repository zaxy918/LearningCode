#include <climits>
#include <iostream>
using namespace std;

int t, n, m, k, maxn, rest;

int main() {
  cin >> t;
  while (t--) {
    maxn = INT_MIN;
    cin >> n >> k;
    for (int i = 0, pre; i < n; i++) {
      cin >> m;
      if (i == 0) {
        maxn = max(k + m, maxn);
        rest = pre = m;
      } else {
        maxn = max(pre + m, maxn);
        pre = m;
      }
    }
    cout << max(m + k, maxn) << endl;
  }
  return 0;
}