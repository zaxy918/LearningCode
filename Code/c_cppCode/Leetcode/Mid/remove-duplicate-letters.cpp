#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
  int cnts[26];
  bool enter[26];
  string removeDuplicateLetters(string s) {
    stack<int> stk;
    fill(cnts, cnts + 26, 0);
    fill(enter, enter + 26, false);
    for (char c : s) cnts[c - 'a']++;
    for (int i = 0; i < s.length(); i++) {
      if (!enter[s[i] - 'a']) {
        while (!stk.empty() && s[i] < s[stk.top()] && cnts[s[stk.top()] - 'a']) {
          enter[s[stk.top()] - 'a'] = false;
          stk.pop();
        }
        stk.push(i);
        enter[s[i] - 'a'] = true;
      }
      cnts[s[i] - 'a']--;
    }
    string ans;
    while (!stk.empty()) {
      ans = s[stk.top()] + ans;
      stk.pop();
    }
    return ans;
  }
};

int main() {
  Solution s;
  s.removeDuplicateLetters("bcabc");
  return 0;
}