#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int row = mat.size(), col = mat.at(0).size(), ans = 0, cur_idx;
    vector<int> cols(col, 0);
    vector<int> l(col);
    vector<int> r(col);
    stack<int> stk;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cols[j] = mat[i][j] == 0 ? 0 : cols[j] + 1;
        while (!stk.empty() && cols[j] <= cols[stk.top()]) {
          cur_idx = stk.top(), stk.pop();
          l[cur_idx] = stk.empty() ? -1 : stk.top();
          r[cur_idx] = j;
        }
        stk.push(j);
      }
      while (!stk.empty()) {
        cur_idx = stk.top(), stk.pop();
        l[cur_idx] = stk.empty() ? -1 : stk.top();
        r[cur_idx] = -1;
      }
      for (int j = 0; j < col; j++) {
        if (l[j] == -1) {
          if (r[j] == -1) {
            ans += cols[j] * col * (col + 1) / 2;
          } else {
            ans += (cols[j] - cols[r[j]]) * (r[j] - l[j] - 1) * (r[j] - l[j]) / 2;
          }
        } else {
          if (r[j] == -1) {
            ans += (cols[j] - cols[l[j]]) * (col - l[j] - 1) * (col - l[j]) / 2;
          } else {
            ans += (cols[j] - max(cols[r[j]], cols[l[j]])) * (r[j] - l[j] - 1) * (r[j] - l[j]) / 2;
          }
        }
      }
    }
    return ans;
  }
};