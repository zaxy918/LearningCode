#include <climits>
#include <iostream>
using namespace std;

const int MAX_N = 1e7 + 10;

int n, m;
long long l, r, s, e;
long long cnt[MAX_N];

void set(int l, int r, int s, int e, int d) {
  cnt[l] += s;
  cnt[l + 1] += d - s;
  cnt[r + 1] -= d + e;
  cnt[r + 2] += e;
}

void build() {
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i <= n; i++) {
      cnt[i] += cnt[i - 1];
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> s >> e;
    set(l, r, s, e, (e - s) / (r - l));
  }
  build();
  long long maxn = INT_MIN, eor = 0;
  for (int i = 1; i <= n; i++) {
    maxn = max(maxn, cnt[i]);
    eor ^= cnt[i];
  }
  cout << eor << " " << maxn;
  return 0;
}