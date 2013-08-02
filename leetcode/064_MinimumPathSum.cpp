// 5min, 1AC
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int> > dp(grid);
        int m = dp.size(), n = dp[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i||j) {
                    dp[i][j] += min(i?dp[i-1][j]:INT_MAX, j?dp[i][j-1]:INT_MAX);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

