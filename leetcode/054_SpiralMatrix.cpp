// ?min, 1AC
// O(1) extra space
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        int sz = m*n;
        ans.resize(sz);
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int dir = 0;
        for(int x = 0, i = 0, j = 0; x < sz; x++) {
            ans[x] = matrix[i][j];
            if(dir == 0 && i == n-1-j
                    || dir == 1 && m-1-i == n-1-j
                    || dir == 2 && m-1-i == j
                    || dir == 3 && i == j+1)
                dir = (dir+1)%4;
            i += dr[dir], j += dc[dir];
        }
        return ans;
    }
};

