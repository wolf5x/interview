// Palindrome Partitioning II
class Solution {
    vector<int> dp;
    vector<vector<bool>> palin;
    string gs;
    int gl;
public:
    int minCut(string s) {
        gs = s;
        gl = gs.length();
        palin.assign(gl, vector<bool>(gl));
        for(int i = 0; i < gl; i++) {
            for(int j = 0; j+i < gl; j++)
                palin[j][j+i] = check(j, j+i);
        }
        dp.resize(gl);
        for(int i = 0; i < gl; i++) {
            if(check(0, i))
                dp[i] = 1;
            else
                dp[i] = i+1;
            for(int j = 0; j < i; j++) {
                if(palin[j+1][i])
                    dp[i] = min(dp[i], dp[j]+1);
            } 
        }
        return dp[gl-1]-1;
    }
    
    bool check(int x, int y) {
        if(gs[x] != gs[y]) return false;
        if(x+1<=y-1) return palin[x+1][y-1];
        else return true;
    }
};

