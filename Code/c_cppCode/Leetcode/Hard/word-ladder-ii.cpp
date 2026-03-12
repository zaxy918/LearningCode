#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<string>> res;
    vector<string> path;
    map<string, unordered_set<string>> graph;
    unordered_set<string> dict;
    unordered_set<string> bigQ, smallQ, curQ;
    bool find;

    bool bfs(string start, string aim) {
        find = false;
        smallQ.insert(start);
        bigQ.insert(aim);
        while (!smallQ.empty()) {
            int size = smallQ.size();
            string cur;
            for (auto s : smallQ) dict.erase(s);
            for (auto cur : smallQ) {
                for (int i = 0; i < cur.length(); i++) {
                    for (int j = 0; j < 26; j++) {
                        string temp = cur;
                        cur[i] = j + 'a';
                        if (cur != temp && dict.count(cur)) {
                            if (cur == aim) find = true;
                            curQ.insert(cur);
                            graph[cur].insert(temp);
                        }
                        cur = temp;
                    }
                }
            }
            if (curQ.size() > bigQ.size()) {
                bigQ = curQ;
                smallQ = bigQ;
            } else {
                smallQ = curQ;
            }
            if (find) return true;
            curQ.clear();
        }
        return false;
    }

    void dfs(string start, string aim) {
        path.push_back(start);
        if (start == aim) {
            res.push_back(path);
        } else if (graph.count(start)) {
            for (auto str : graph[start]) {
                dfs(str, aim);
            }
        }
        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        for (auto s : wordList) {
            dict.insert(s);
        }
        dict.insert(beginWord);
        if (!dict.count(endWord)) return res;
        if (bfs(endWord, beginWord))
            dfs(beginWord, endWord);
        return res;
    }
};
int main() {
    Solution sl;
    vector<string> worldList = {"hot", "dot", "dog", "lot", "log", "cog"};
    sl.findLadders("hit", "cog", worldList);
}