#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    static const int MAX_C = 2001;
    static const int MAX_EDGE = MAX_C * (MAX_C - 1);
    int head[MAX_C];
    int next[MAX_EDGE];
    int to[MAX_EDGE];
    int cnt;
    int indeg[MAX_C];
    int q[MAX_EDGE];
    int h, t;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> res;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1] + 1, v = prerequisites[i][0] + 1;
            indeg[v]++;
            next[++cnt] = head[u];
            head[u] = cnt;
            to[cnt] = v;
        }
        for (int i = 1; i <= numCourses; i++) {
            if (indeg[i] == 0) {
                q[t++] = i;
                res.push_back(i - 1);
            }
        }
        while (h < t) {
            int size = t - h;
            for (int i = 0, cur; i < size; i++) {
                cur = q[h++];
                for (int j = head[cur]; j > 0; j = next[j]) {
                    if (--indeg[to[j]] == 0) {
                        q[t++] = to[j];
                        res.push_back(to[j] - 1);
                    }
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>(0);
    }
};