// https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb
#include <iostream>
using namespace std;

const int MAXN = 1e6 + 10;

int n;
int arr[MAXN], l[MAXN], r[MAXN];
int stk[MAXN];
int top, cur_idx;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    while (top && arr[stk[top]] >= arr[i]) {
      cur_idx = stk[top--];
      l[cur_idx] = top ? stk[top] : -1;
      r[cur_idx] = i;
    }
    stk[++top] = i;
  }
  while (top) {
    cur_idx = stk[top--];
    l[cur_idx] = top ? stk[top] : -1;
    r[cur_idx] = -1;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (r[i] != -1 && arr[r[i]] == arr[i]) {
      r[i] = r[r[i]];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << l[i] << " " << r[i] << endl;
  }
  return 0;
}