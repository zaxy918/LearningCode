#include <iostream>
using namespace std;
class Solution {
public:
  int cnt[26];
  int longestSubstring(string s, int k) {
    int ans = 0;
    for (int re = 1; re <= s.size() / k; re++) {
      fill(cnt, cnt + 26, 0);
      for (int l = 0, r = 0, valid = 0, have = 0; r < s.length(); r++) {
        int c = s[r] - 'a';
        if (cnt[c]++ == 0) {
          have++;
          while (have > re) {
            if (cnt[s[l] - 'a']-- == k) valid--;
            if (cnt[s[l++] - 'a'] == 0) have--;
          }
        }
        if (cnt[c] == k) valid++;
        if (valid == have && valid == re) ans = max(ans, r - l + 1);
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  s.longestSubstring("ababbc", 2);
  return 0;
}