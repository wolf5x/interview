// 10min
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] += (i?dp[i-1][j]:0) + (j?dp[i][j-1]:0);
            }
        }
        return dp[m-1][n-1];
    }
};

