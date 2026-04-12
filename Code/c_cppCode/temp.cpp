#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1010;

int round[3][MAXN];
int abc[3];
int turn[3];
int x[3];
int score;

int get_score() {
  if (abc[0] == abc[1] && abc[2] == abc[0]) return 200;
  if (abc[0] == abc[1] - 1 && abc[1] == abc[2] - 1) return 200;
  if (abc[0] == abc[1] || abc[1] == abc[2] || abc[2] == abc[0]) return 100;
  sort(abc, abc + 3);
  if (abc[0] == abc[1] - 1 && abc[1] == abc[2] - 1) return 100;
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      cin >> round[i][j];
    }
  }
  int m;
  cin >> m;
  while (m--) {
    for (int i = 0; i < 3; i++) {
      cin >> x[i];
      turn[i] += x[i];
      abc[i] = round[i][turn[i] % n];
    }
    score += get_score();
  }
  cout << score << endl;
  return 0;
}