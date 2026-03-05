#include <climits>
#include <iostream>
using namespace std;

long long t, n, first, last;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long maxn = INT_MIN;
    for (long long i = 0, a; i < n; i++) {
      cin >> a;
      if (i == 0) {
        first = a;
      }
      if (i == n - 1) {
        last = a;
      }
      maxn = max(maxn, a);
    }
    cout << maxn * (n - 2) + first + last << endl;
  }
  return 0;
}