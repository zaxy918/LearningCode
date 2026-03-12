#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    struct Node {
        int x;
        int y;
        int w;
        bool operator<(const Node &other) const {
            return this->w > other.w;
        }
    };
    static const int MAX_N = 110;
    const int MOVE[5] = {-1, 0, 1, 0, -1};
    int dis[MAX_N][MAX_N];
    bool vis[MAX_N][MAX_N];
    priority_queue<Node, vector<Node>> heap;
    int minimumEffortPath(vector<vector<int>> &heights) {
        int r = heights.size();
        int c = heights[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dis[i][j] = INT_MAX;
            }
        }
        dis[0][0] = 0;
        heap.push({0, 0, 0});
        while (!heap.empty()) {
            Node cur = heap.top();
            heap.pop();
            if (!vis[cur.x][cur.y]) {
                vis[cur.x][cur.y] = true;
                for (int i = 0, dx, dy, curDis; i < 4; i++) {
                    dx = cur.x + MOVE[i];
                    dy = cur.y + MOVE[i + 1];
                    if (dx >= 0 && dy >= 0 && dx < r && dy < c && !vis[dx][dy]) {
                        curDis = max(abs(heights[cur.x][cur.y] - heights[dx][dy]), dis[cur.x][cur.y]);
                        if (curDis < dis[dx][dy]) {
                            dis[dx][dy] = curDis;
                            heap.push({dx, dy, curDis});
                        }
                    }
                }
            }
        }
        return dis[r - 1][c - 1];
    }
};