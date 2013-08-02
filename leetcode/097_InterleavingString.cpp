// 5min 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if(m+n != s3.length())
            return false;
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(dp[i][j]){ 
                    if(i < m && s1[i] == s3[i+j])
                        dp[i+1][j] = true;
                    if(j < n && s2[j] == s3[i+j])
                        dp[i][j+1] = true;
                }
            }
        }
        return dp[m][n];
    }
};

