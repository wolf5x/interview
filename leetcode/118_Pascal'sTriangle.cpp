class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        for(int i = 0; i < numRows; i++) {
            vector<int> row;
            for(int j = 0; j <= i; j++)
                row.push_back(j==0 || j==i ? 1 : ans[i-1][j]+ans[i-1][j-1]);
            ans.push_back(row);
        }
        return ans;
    }
};

