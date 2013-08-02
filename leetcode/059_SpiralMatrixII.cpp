// 5min, 1AC
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));
        int x = 0, i = 0, j = 0;
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        int k = 0;
        while(x < n*n) {
            ans[i][j] = ++x;
            if(k == 0 && i+j == n-1
                    || k == 1 && i == j
                    || k == 2 && i+j == n-1
                    || k == 3 && i == j+1)
                k = (k+1)%4;
            i += di[k], j += dj[k];
        }
        return ans;
    }
};

