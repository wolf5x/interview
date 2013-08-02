// 5min
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> ans(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= i; j++)
                ans[j] = triangle[i][j] + min(ans[j], ans[j+1]);
        }
        return ans[0];
    }
};

