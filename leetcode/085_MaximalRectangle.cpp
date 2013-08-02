class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n+1, 0);
        int ans = 0;
        for(int r = 0; r < m; r++) {
            stack<int> stk;
            stk.push(-1);
            for(int i = 0; i <= n; i++) {
                height[i] = i < n ? 
                        matrix[r][i] == '1' ? height[i]+1 : 0
                        : -1;
                while(stk.top()>=0 && height[stk.top()]>height[i]) {
                    int t = height[stk.top()];
                    stk.pop();
                    ans = max(ans, t*(i-1-stk.top()));
                }
                stk.push(i);
            }
        }
        return ans;
    }
};

