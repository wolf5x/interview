// 3min, 1AC
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = obstacleGrid[0][0] == 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = obstacleGrid[i][j] ? 0
                    : dp[i][j]+(i?dp[i-1][j]:0)+(j?dp[i][j-1]:0);
            }
        }
        return dp[m-1][n-1];
    }
};

