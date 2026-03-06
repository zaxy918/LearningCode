#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int largest1BorderedSquare(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid.at(0).size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        grid[i][j] += get(grid, i - 1, j) + get(grid, i, j - 1) - get(grid, i - 1, j - 1);
      }
    }
    // If all number is 0
    if (grid[m - 1][n - 1] == 0) return 0;
    int len = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = i + len, l = j + len; k < m && l < n; k++, l++) {
          if (getSum(grid, i, j, k, l) - getSum(grid, i + 1, j + 1, k - 1, l - 1) == (k - i) * 4) {
            len = k - i + 1;
          }
        }
      }
    }
    return len * len;
  }
  int get(vector<vector<int>> &grid, int i, int j) {
    return (i < 0 || j < 0) ? 0 : grid[i][j];
  }
  int getSum(vector<vector<int>> &grid, int a, int b, int c, int d) {
    return a > c ? 0 : grid[c][d] - get(grid, c, b - 1) - get(grid, a - 1, d) + get(grid, a - 1, b - 1);
  }
};