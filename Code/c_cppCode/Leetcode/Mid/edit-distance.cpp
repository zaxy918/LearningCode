#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int del = 1, ist = 1, rplc = 1;
        vector<int> dp(l2 + 1);
        for (int i = 0; i <= l2; i++) dp[i] = ist * i;
        for (int i = 1; i <= l1; i++) {
            int pre = (i - 1) * ist, bkup;
            for (int j = 1; j <= l2; j++) {
                bkup = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = pre;
                else
                    dp[j] = min(dp[j] + del, min(pre + rplc, dp[j - 1] + ist));
                pre = bkup;
            }
            dp[0] = ist * i;
        }
        return dp[l2];
    }
};