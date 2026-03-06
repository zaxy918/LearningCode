#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool possibleToStamp(vector<vector<int>> &g, int stampHeight, int stampWidth) {
    int n = g.size();
    int m = g.at(0).size();
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        grid[i + 1][j + 1] = g[i][j];
      }
    }
    preSum(grid, n, m);
    vector<vector<int>> res(n + 2, vector<int>(m + 2));
    for (int i = stampHeight; i <= n; i++) {
      for (int j = stampWidth; j <= m; j++) {
        if (getSum(grid, i - stampHeight + 1, j - stampWidth + 1, i, j) == 0) {
          res[i - stampHeight + 1][j - stampWidth + 1]++;
          res[i - stampHeight + 1][j + 1]--;
          res[i + 1][j - stampWidth + 1]--;
          res[i + 1][j + 1]++;
        }
      }
    }
    preSum(res, n, m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (res[i][j] == 0 && g[i - 1][j - 1] == 0) return false;
      }
    }
    return true;
  }

  void preSum(vector<vector<int>> &g, int n, int m) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
      }
    }
  }

  int getSum(vector<vector<int>> &grid, int a, int b, int c, int d) {
    return grid[c][d] - grid[a - 1][d] - grid[c][b - 1] + grid[a - 1][b - 1];
  }
};