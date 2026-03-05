#include <cstring>
#include <iostream>
using namespace std;

const int MOD = 998244353;
const int MAXN = 4 * 1e5 + 10;

int t, n;
bool ni[MAXN];

long long step(long long x) {
  if (x == 1 || x == 0) return 1LL;
  long long res = 1;
  for (int i = 2; i <= x; i++) {
    res = (res * i) % MOD;
  }
  return res;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    memset(ni, 0, sizeof ni);
    for (int i = 0, a; i < n; i++) {
      cin >> a;
      ni[a] = true;
    }
    for (int i = 0, b; i < n; i++) cin >> b;
    int can = 0, win = 0;
    for (int i = 1; i <= 2 * n; i++) {
      if (!ni[i])
        can++;
      else if (can) {
        can--;
        win++;
      }
    }
    cout << (step(n - win) * step(win)) % MOD << endl;
  }
  return 0;
}