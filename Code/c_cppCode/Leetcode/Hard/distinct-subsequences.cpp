#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int numDistinct(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        vector<unsigned long long> dp(lt + 1);
        for (int i = 1; i <= ls; i++) {
            dp[0] = 1;
            for (int j = lt; j > 0; j--) {
                dp[j] += s[i - 1] == t[j - 1] ? dp[j - 1] : 0;
            }
        }
        return dp[lt];
    }
};