#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;

int n, a[MAXN], ans;
int stk[MAXN][2];
int top;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1, turn; i >= 0; i--) {
    turn = 0;
    while (top && stk[top][0] < a[i]) {
      turn = max(turn + 1, stk[top--][1]);
    }
    stk[++top][0] = a[i];
    stk[top][1] = turn;
    ans = max(turn, ans);
  }
  cout << ans << endl;
  return 0;
}