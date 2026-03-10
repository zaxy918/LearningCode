#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
public:
  vector<vector<int>> new_matrix;
  NumMatrix(vector<vector<int>> &matrix) {
    int m = matrix.at(0).size();
    int n = matrix.size();
    for (int i = 0; i <= n; i++) {
      new_matrix.push_back(vector<int>(m));
      for (int j = 0; j <= m; j++) {
        new_matrix.at(i).push_back(0);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        new_matrix.at(i + 1).at(j + 1) = matrix.at(i).at(j);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        new_matrix.at(i).at(j) +=
            new_matrix.at(i).at(j - 1) +
            new_matrix.at(i - 1).at(j) -
            new_matrix.at(i - 1).at(j - 1);
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    row2++;
    col2++;
    return new_matrix.at(row2).at(col2) - new_matrix.at(row2).at(col1) - new_matrix.at(row1).at(col2) + new_matrix.at(row1).at(col1);
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */