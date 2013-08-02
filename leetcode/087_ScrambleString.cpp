// 1hour
// O(n^4)
class Solution {
    vector<vector<vector<char> > > dp;
    string gs1, gs2;
public:
    bool isScramble(string s1, string s2) {
        gs1 = s1, gs2 = s2;
        int n = s1.length();
        dp.assign(n, vector<vector<char> >(n, vector<char>(n+1, -1)));
        return getdp(0, 0, n) > 0;
    }
    
    char getdp(int i, int j, int k) {
        if(k == 0)
            return 1;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        char &r = dp[i][j][k];
        if(k == 1)
            return r = ((gs1[i] == gs2[j]) ? 1 : 0);
        for(int p = 1; p < k; p++) {
            if(getdp(i, j, p) && getdp(i+p, j+p, k-p)
                    || getdp(i, j+k-p, p) && getdp(i+p, j, k-p))
                return r = 1;
        }
        return r = 0;
        
    }
};

