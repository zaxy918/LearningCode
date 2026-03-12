#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<int> dp(len + 1);
        dp[len] = 1;
        for (int i = len - 1; i >= 0; i--) {
            int pre = 0, bkup;
            dp[i] = 1;
            for (int j = i + 1; j <= len; j++) {
                bkup = dp[j];
                if (s[i] == s[j])
                    dp[j] = pre + 2;
                else
                    dp[j] = max(dp[j - 1], dp[j]);
                pre = bkup;
            }
        }
        return dp[len];
    }
};