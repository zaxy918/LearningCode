#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0) return 0;
    int row = matrix.size(), col = matrix.at(0).size(), cur_max, cur_idx, ans = 0;
    vector<int> cols(col, 0);
    stack<int> stk;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (matrix[i][j] == '0')
          cols[j] = 0;
        else
          cols[j]++;
        while (!stk.empty() && cols[j] <= cols[stk.top()]) {
          cur_idx = stk.top(), stk.pop();
          cur_max = cols[cur_idx] * (j - (stk.empty() ? -1 : stk.top()) - 1);
          ans = max(cur_max, ans);
        }
        stk.push(j);
      }
      while (!stk.empty()) {
        cur_idx = stk.top(), stk.pop();
        cur_max = cols[cur_idx] * (col - (stk.empty() ? -1 : stk.top()) - 1);
        ans = max(cur_max, ans);
      }
    }
    return ans;
  }
};