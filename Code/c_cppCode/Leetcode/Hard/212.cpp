#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  static const int MAX_N = 1e5;
  const int MOVE[5] = {-1, 0, 1, 0, -1};
  int trie[MAX_N][26];
  int pass[MAX_N];
  string end[MAX_N];
  int cnt = 1;
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    // Build the trie
    build(words);
    vector<string> res;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board.at(i).size(); j++) {
        dfs(board, res, i, j, 1);
      }
    }
    return res;
  }

  int dfs(vector<vector<char>> &board, vector<string> &res, int x, int y, int node) {
    // Out of range or have been visited
    if (x >= board.size() || x < 0 || y >= board.at(0).size() || y < 0 || board.at(x).at(y) == 0) return 0;
    char tmp = board.at(x).at(y);
    int path = tmp - 'a';
    // The next char
    node = trie[node][path];
    // No next or have been visited
    if (pass[node] == 0) return 0;
    int visited = 0;
    // End of the word
    if (end[node] != "") {
      visited++;
      res.push_back(end[node]);
      end[node] = "";
    }
    // Mark visited
    board.at(x).at(y) = 0;
    // Try all direction
    for (int i = 0, dx, dy; i < 4; i++) {
      dx = x + MOVE[i];
      dy = y + MOVE[i + 1];
      visited += dfs(board, res, dx, dy, node);
    }
    // Delete all the words that have been visited
    pass[node] -= visited;
    // Recovery
    board.at(x).at(y) = tmp;
    return visited;
  }

  void insert(string s) {
    int cur = 1;
    for (int i = 0, path; i < s.length(); i++) {
      path = s.at(i) - 'a';
      if (trie[cur][path] == 0) trie[cur][path] = ++cnt;
      pass[cur]++;
      cur = trie[cur][path];
    }
    pass[cur]++;
    end[cur] = s;
  }

  void build(vector<string> &words) {
    for (auto s : words) {
      insert(s);
    }
  }
};