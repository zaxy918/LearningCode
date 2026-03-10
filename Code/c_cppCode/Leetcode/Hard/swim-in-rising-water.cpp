#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    struct Node {
        int x, y, w;
        bool operator<(const Node &other) const {
            return this->w > other.w;
        }
    };
    static const int MAX_N = 51;
    const int MOVE[5] = {-1, 0, 1, 0, -1};
    int dis[MAX_N][MAX_N];
    bool vis[MAX_N][MAX_N];
    priority_queue<Node> heap;
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = INT_MAX;
            }
        }
        dis[0][0] = grid[0][0];
        heap.push({0, 0, dis[0][0]});
        while (!heap.empty()) {
            Node cur = heap.top();
            heap.pop();
            if (!vis[cur.x][cur.y]) {
                vis[cur.x][cur.y] = true;
                for (int i = 0, dx, dy, curDis; i < 4; i++) {
                    dx = cur.x + MOVE[i];
                    dy = cur.y + MOVE[i + 1];
                    if (dx >= 0 && dy >= 0 && dx < n && dy < n && !vis[dx][dy]) {
                        curDis = max(dis[cur.x][cur.y], grid[dx][dy]);
                        if (curDis < dis[dx][dy]) {
                            dis[dx][dy] = curDis;
                            heap.push({dx, dy, curDis});
                        }
                    }
                }
            }
        }
        return dis[n - 1][n - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid(5, vector<int>(5));
    grid = {{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}};
    s.swimInWater(grid);
}