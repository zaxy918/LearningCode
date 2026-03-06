#include <iostream>
using namespace std;

const int OFFSET = 30000;
const int MAX_M = 1e6 + 10 + OFFSET * 2;

int n, m;
int lake[MAX_M];

void set(int l, int r, int a, int d, int e) {
  lake[l] += a;
  lake[l + 1] += d - a;
  lake[r] -= e + d;
  lake[r + 1] += e;
}

void fall(int v, int x) {
  x += OFFSET;
  set(x - 3 * v + 1, x - 2 * v, 1, 1, v - 1);
  set(x - 2 * v, x, v, -1, 1 - v);
  set(x, x + 2 * v, -v, 1, v - 1);
  set(x + 2 * v, x + 3 * v, v, -1, 1);
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  while (n--) {
    int v, x;
    cin >> v >> x;
    fall(v, x);
  }
  // Presum
  for (int i = 1; i <= m + OFFSET + 1; i++) {
    lake[i] += lake[i - 1];
  }
  for (int i = 1; i <= m + OFFSET + 1; i++) {
    lake[i] += lake[i - 1];
  }
  for (int i = OFFSET + 1; i <= m + OFFSET; i++) {
    cout << lake[i] << " ";
  }
  return 0;
}