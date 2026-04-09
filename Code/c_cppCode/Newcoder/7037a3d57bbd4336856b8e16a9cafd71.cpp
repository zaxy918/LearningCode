#include <iostream>
using namespace std;

const int MAX_N = 1e5 + 1;

int n;
int h[MAX_N];

bool can_jump(long long e, int max_h) {
  for (int i = 0; i < n; i++) {
    e += e - h[i];
    if (e >= max_h) return true;
    if (e < 0) return false;
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  int max_h = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    max_h = max(max_h, h[i]);
  }
  int l = 1, r = max_h, m, ans = max_h;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (can_jump((long long)m, max_h)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
