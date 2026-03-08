#include <iostream>
using namespace std;
class Solution {
public:
  int cnts[256];
  string minWindow(string s, string t) {
    fill(cnts, cnts + 256, 0);
    int debt = t.length();
    bool flag = false;
    int ans = s.length(), left = 0;
    for (int i = 0; i < debt; i++) {
      cnts[t[i]]--;
    }
    for (int r = 0, l = 0; r < s.length(); r++) {
      if (cnts[s[r]] < 0) {
        debt--;
      }
      cnts[s[r]]++;
      while (debt == 0) {
        flag = true;
        if (r - l + 1 < ans) {
          ans = r - l + 1;
          left = l;
        }
        if (ans == t.length()) return s.substr(left, ans);
        if (--cnts[s[l++]] < 0) debt++;
      };
    }
    return flag ? s.substr(left, ans) : "";
  }
};
int main() {
  Solution s;
  s.minWindow("ADOBECODEBANC", "ABC");
  return 0;
}