#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
  static const int MAX_N = 5 * 1e5 + 10;
  int status = 0;
  int state[MAX_N];
  int findTheLongestSubstring(string s) {
    int res = 0;
    unordered_map<char, int> vowel;
    unordered_map<int, int> earliest;
    vowel['a'] = 0;
    vowel['e'] = 1;
    vowel['i'] = 2;
    vowel['o'] = 3;
    vowel['u'] = 4;
    for (int i = 0; i < s.length(); i++) {
      if (isVowel(s.at(i))) {
        status ^= (1 << vowel[s.at(i)]);
      }
      // 00000
      if (!status) {
        res = max(res, i + 1);
      } else if (earliest.count(status)) {
        res = max(res, i - earliest[status]);
      }
      if (!earliest.count(status)) earliest[status] = i;
    }
    return res;
  }

  int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};

int main() {
  string s = "eleetminicoworoep";
  Solution slt;
  cout << slt.findTheLongestSubstring(s);
}