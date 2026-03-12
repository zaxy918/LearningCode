#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    int land = 0;
    int res = 0;
    int move[5] = {-1, 0, 1, 0, -1};
    int maxDistance(vector<vector<int>> &grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    land++;
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        if (land == 0 || land == n * n) return -1;
        while (!q.empty()) {
            res++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int dx = x + move[i];
                    int dy = y + move[i + 1];
                    if (dx >= 0 && dy >= 0 && dx < n && dy < n && !vis[dx][dy]) {
                        vis[dx][dy] = true;
                        q.push({dx, dy});
                    }
                }
            }
        }
        return res - 1;
    }
};