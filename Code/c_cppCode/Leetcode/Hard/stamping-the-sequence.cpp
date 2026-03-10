#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    static const int MAX_N = 1001;
    int q[MAX_N];
    int h, t;
    int indeg[MAX_N];
    int vis[MAX_N];

    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int ls = stamp.length(), lt = target.length();
        vector<vector<int>> graph(lt, vector<int>(0));
        fill(indeg, indeg + lt - ls + 2, ls);
        //* Amazing build graph
        for (int i = 0; i <= lt - ls; i++) {
            for (int j = 0; j < ls; j++) {
                if (target[i + j] == stamp[j]) {
                    if (--indeg[i] == 0) {
                        q[t++] = i;
                        res.push_back(i);
                    }
                } else {
                    graph[i + j].push_back(i);
                }
            }
        }
        while (h < t) {
            int size = t - h;
            for (int i = 0, cur; i < size; i++) {
                cur = q[h++];
                for (int j = 0; j < ls; j++) {
                    if (!vis[cur + j]) {
                        vis[cur + j] = true;
                        for (auto k : graph[cur + j]) {
                            if (--indeg[k] == 0) {
                                q[t++] = k;
                                res.push_back(k);
                            }
                        }
                    }
                }
            }
        }
        reverse(res.begin(), res.end());
        return res.size() == lt - ls + 1 ? res : vector<int>(0);
    }
};

int main() {
    Solution slt;
    slt.movesToStamp("abc", "abcbc");
    return 0;
}