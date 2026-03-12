#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        if (l1 + l2 != l3) return false;
        if (l1 < l2) swap(s1, s2);
        l1 = s1.length();
        l2 = s2.length();
        vector<bool> dp(l2 + 1, false);
        dp[0] = true;
        for (int i = 1; i <= l2; i++) {
            if (s2[i - 1] != s3[i - 1]) break;
            dp[i] = true;
        }
        for (int i = 1; i <= l1; i++) {
            dp[0] = s1[i - 1] == s3[i - 1] && dp[0];
            for (int j = 1; j <= l2; j++) {
                dp[j] = (s1[i - 1] == s3[i + j - 1] && dp[j]) || (s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
            }
        }
        return dp[l2];
    }
};