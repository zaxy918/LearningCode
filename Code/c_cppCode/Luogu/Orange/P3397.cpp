#include <iostream>
using namespace std;

const int MAX_N = 1010;

int n, m;
int ground[MAX_N][MAX_N];

int main() {
  cin >> n >> m;
  while (m--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ground[x1][y1]++;
    ground[x1][y2 + 1]--;
    ground[x2 + 1][y1]--;
    ground[x2 + 1][y2 + 1]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ground[i][j] += ground[i - 1][j] + ground[i][j - 1] - ground[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ground[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}