// 20min, 1RE
class Solution {

public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int> > dp(m+1, vector<int>(n+1, -1));
        dp[0][0] = 0;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(dp[i][j] >= 0) {
                    // insert & remove
                    if(i<m) checkmin(dp[i+1][j], 1+dp[i][j]);
                    if(j<n) checkmin(dp[i][j+1], 1+dp[i][j]);
                    // modify
                    if(i<m && j<n) checkmin(dp[i+1][j+1], 1+dp[i][j]);
                    // match
                    if(i<m && j<n && word1[i]==word2[j])
                        checkmin(dp[i+1][j+1], dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
    
    void checkmin(int &a, int b) {
        if(a < 0 || a > b) a = b;
    }
};

