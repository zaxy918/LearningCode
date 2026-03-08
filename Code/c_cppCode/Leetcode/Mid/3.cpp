#include <iostream>
using namespace std;
class Solution {
public:
  bool arr[256];
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    for (int r = 0, l = 0; r < s.length(); r++) {
      int n = s[r];
      while (arr[n] == true) {
        arr[s[l++]] = false;
      }
      ans = max(ans, r - l + 1);
      arr[s[r]] = true;
    }
    return ans;
  }
};

int main() {
  Solution s;
  s.lengthOfLongestSubstring("abcabcbb");
  return 0;
}