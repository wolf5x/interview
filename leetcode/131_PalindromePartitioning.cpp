class Solution {
    vector<vector<int>> dp;
    string gs;
    int gl;
public:
    vector<vector<string>> partition(string s) {
        gs = s;
        gl = gs.length();
        dp.resize(gl);
        for(int i = 0; i < gl; i++) {
            dp[i].resize(gl);
            for(int j = i; j < gl; j++) {
                dp[i][j] = check(i, j) ? 2 : -1;
            }
        }
        vector<string> mem;
        vector<vector<string>> ans;
        dfs(ans, mem, 0);
        return ans;
    }
    
    void dfs(vector<vector<string>> &ans, vector<string> &mem,
            int p) {
        if(p == gl) {
            ans.push_back(mem);
        }
        for(int i = p; i < gl; i++) {
            if(getdp(p, i) == 2 && getdp(i+1, gl-1) > 0) {
                mem.push_back(gs.substr(p, i-p+1));
                dfs(ans, mem, i+1);
                mem.pop_back();
            }
        }
    }
    
    
    bool check(int x, int y) {
        int l = y+1-x;
        for(int i = 0; i < l/2; i++)
            if(gs[x+i] != gs[x+l-1-i])
                return false;
        return true;
    }
    
    int getdp(int x, int y) {
        if(x > y) return 1;
        if(dp[x][y] >= 0) return dp[x][y];
        int &r = dp[x][y];
        for(int i = x; i < y; i++)
            if(getdp(x, i)>0 && getdp(i+1, y)>0)
                return r = 1;
        return r = 0;
    }
};

