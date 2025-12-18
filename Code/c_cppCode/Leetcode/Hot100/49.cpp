#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    unordered_map<string, int> tb;
    int cnt = 0;
    for (int i = 0; i < strs.size(); i++) {
      string str = strs.at(i);
      sort(str.begin(), str.end());
      if (tb.find(str) != tb.end()) {
        res.at(tb[str]).push_back(strs.at(i));
      } else {
        vector<string> entry;
        res.push_back(entry);
        res.at(cnt).push_back(strs.at(i));
        tb[str] = cnt++;
      }
    }
    return res;
  }
};