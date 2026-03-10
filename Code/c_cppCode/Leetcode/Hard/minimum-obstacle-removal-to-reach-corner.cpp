#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    const int MOVE[5] = {-1, 0, 1, 0, -1};
    int minimumObstacles(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        deque<pair<int, int>> dq(m * n);
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dq.push_front({0, 0});
        dis[0][0] = 0;
        while (!dq.empty()) {
            int size = dq.size();
            for (int i = 0, curX, curY; i < size; i++) {
                curX = dq.front().first;
                curY = dq.front().second;
                dq.pop_front();
                for (int j = 0, dx, dy; j < 4; j++) {
                    dx = curX + MOVE[j];
                    dy = curY + MOVE[j + 1];
                    if (dx >= 0 && dy >= 0 && dx < n && dy < m && !vis[dx][dy]) {
                        vis[dx][dy] = true;
                        dis[dx][dy] = dis[dx][dy] > dis[curX][curY] + grid[dx][dy] ? dis[curX][curY] + grid[dx][dy] : dis[dx][dy];
                        if (dx == n - 1 && dy == m - 1) return dis[n - 1][m - 1];
                        if (grid[dx][dy]) {
                            dq.push_back({dx, dy});
                        } else {
                            dq.push_front({dx, dy});
                        }
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};