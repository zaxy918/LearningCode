#include <iostream>
using namespace std;

const int OFFSET = 3 * 1e4;
const int MAX_M = 1e6 + 10 + 2 * OFFSET;

int n, m;
int v, x;
int cnt[MAX_M];

void set(int l, int r, int s, int e, int d) {
  cnt[l + OFFSET] += s;
  cnt[l + 1 + OFFSET] += d - s;
  cnt[r + 1 + OFFSET] -= e + d;
  cnt[r + 2 + OFFSET] += e;
}

void build() {
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i <= n; i++) {
      cnt[i + OFFSET] += cnt[i - 1 + OFFSET];
    }
  }
}

void fall(int v, int x) {
  set(x - 3 * v + 1, x - 2 * v, 1, v, 1);
  set(x - 2 * v + 1, x, v - 1, -v, -1);
  set(x + 1, x + 2 * v, -v + 1, v, 1);
  set(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1);
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> v >> x;
    fall(v, x);
  }
  build();
  for (int i = 1; i <= m; i++) cout << cnt[i + OFFSET] << " ";
  return 0;
}