// http://leetcode.com/onlinejudge#question_73
// 1000min = =|
// space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool fh = false, fv = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!i && matrix[i][j]==0)
                    fh = true;
                if(!j && matrix[i][j]==0)
                    fv = true;
                if(i && j && matrix[i][j]==0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(int i = 1; i < m; i++)
            if(matrix[i][0] == 0)
                for(int j = 1; j < n; j++)
                    matrix[i][j] = 0;
        for(int j = 1; j < n; j++)
            if(matrix[0][j] == 0)
                for(int i = 1; i < m; i++)
                    matrix[i][j] = 0;
        if(fh)
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if(fv)
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};
