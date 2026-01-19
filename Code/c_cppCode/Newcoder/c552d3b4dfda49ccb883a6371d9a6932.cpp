#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  static const int MAX_N = 1e6;
  int pass[MAX_N];
  int trie[MAX_N][12];
  int cnt = 0;
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param b int整型vector<vector<>>
   * @param a int整型vector<vector<>>
   * @return int整型vector
   */
  vector<int> countConsistentKeys(vector<vector<int>> &b, vector<vector<int>> &a) {
    vector<string> bstr = parseSecret(b);
    vector<string> astr = parseSecret(a);
    for (auto s : astr) {
      insert(s);
    }
    vector<int> res;
    for (auto s : bstr) {
      res.push_back(prefix(s));
    }
    return res;
  }

  void insert(string s) {
    int cur = 1;
    for (int i = 0, path; i < s.length(); i++) {
      path = parsePath(s.at(i));
      if (trie[cur][path] == 0) trie[cur][path] = ++cnt;
      pass[cur]++;
      cur = trie[cur][path];
    }
    pass[cur]++;
  }

  int prefix(string s) {
    int cur = 1;
    for (int i = 0, path; i < s.length(); i++) {
      path = parsePath(s.at(i));
      if (trie[cur][path] == 0) return 0;
      cur = trie[cur][path];
    }
    return pass[cur];
  }

  vector<string> parseSecret(vector<vector<int>> &a) {
    vector<string> secret;
    for (auto vec : a) {
      string s = "";
      for (int i = 1; i < vec.size(); i++) {
        s += to_string(vec.at(i) - vec.at(i - 1));
        s += ",";
      }
      secret.push_back(s);
    }
    return secret;
  }

  int parsePath(const char &c) {
    if (c == '-') {
      return 11;
    } else if (c == ',') {
      return 12;
    } else {
      return c - '0';
    }
  }
};