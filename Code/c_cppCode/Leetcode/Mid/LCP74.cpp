#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int fieldOfGreatestBlessing(vector<vector<int>> &forceField) {
    int n = forceField.size();
    vector<long long> xs(2 * n), ys(2 * n);
    for (long long i = 0, x, y, side, x1, x2, y1, y2, cntx = 0, cnty = 0; i < n; i++) {
      x = forceField[i][0];
      y = forceField[i][1];
      side = forceField[i][2];
      x1 = 2 * x - side;
      x2 = 2 * x + side;
      y1 = 2 * y - side;
      y2 = 2 * y + side;
      xs[cntx++] = x1;
      xs[cntx++] = x2;
      ys[cnty++] = y1;
      ys[cnty++] = y2;
    }
    int sizex = sort_and_unique(xs);
    int sizey = sort_and_unique(ys);
    unordered_map<long long, long long> mapx = maparr(xs, sizex);
    unordered_map<long long, long long> mapy = maparr(ys, sizey);
    vector<vector<long long>> g(sizex + 2, vector<long long>(sizey + 2));
    for (long long i = 0, x, y, side, x1, x2, y1, y2, cntx = 0, cnty = 0; i < n; i++) {
      x = forceField[i][0];
      y = forceField[i][1];
      side = forceField[i][2];
      x1 = 2 * x - side;
      x2 = 2 * x + side;
      y1 = 2 * y - side;
      y2 = 2 * y + side;
      diff(g, mapx[x1], mapy[y1], mapx[x2], mapy[y2]);
    }
    preSum(g);
    int ans = 0;
    for (int i = 1; i < g.size() - 1; i++) {
      for (int j = 1; j < g.at(i).size() - 1; j++) {
        ans = g[i][j] > ans ? g[i][j] : ans;
      }
    }
    return ans;
  }

  void preSum(vector<vector<long long>> &g) {
    for (int i = 1; i < g.size(); i++) {
      for (int j = 1; j < g.at(i).size(); j++) {
        g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
      }
    }
  }

  int sort_and_unique(vector<long long> &arr) {
    sort(arr.begin(), arr.end());
    int size = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] != arr[size]) {
        arr[++size] = arr[i];
      }
    }
    return size + 1;
  }

  unordered_map<long long, long long> maparr(vector<long long> &arr, int size) {
    unordered_map<long long, long long> res;
    for (int i = 0; i < size; i++) {
      res[arr[i]] = i + 1;
    }
    return res;
  }

  void diff(vector<vector<long long>> &g, int x1, int y1, int x2, int y2) {
    g[x1][y1]++;
    g[x1][y2 + 1]--;
    g[x2 + 1][y1]--;
    g[x2 + 1][y2 + 1]++;
  }
};
int main() {
  Solution s;
  vector<vector<int>> f(2, vector<int>(3));
  f[0][0] = 0;
  f[0][1] = 0;
  f[0][2] = 1;
  f[1][0] = 1;
  f[1][1] = 0;
  f[1][2] = 1;
  s.fieldOfGreatestBlessing(f);
  return 0;
}