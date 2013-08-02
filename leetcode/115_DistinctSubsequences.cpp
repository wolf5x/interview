// http://leetcode.com/onlinejudge#question_115
// 10min
// O(mn) DP.
class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.length(), n = T.length();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] > 0) {
                    if (i<m && j<n && S[i]==T[j])
                        dp[i+1][j+1] += dp[i][j];
                    if (i<m)
                        dp[i+1][j] += dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};

